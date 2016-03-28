//
// Kitchen.cpp for Kitchen.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Fri Apr 25 15:20:51 2014 Baptiste Acca
// Last update Sun Apr 27 18:17:26 2014 LOEB Thomas
//

#include <sstream>
#include <unistd.h>
#include "Kitchen.hh"
#include "Static.hh"

Kitchen::Kitchen(unsigned int id)
{
  unsigned int i;

  for (i = 0; i < NB_INGREDIENTS ; ++i)
    this->_stock[i] = new Ingredient(static_cast<TypeIngredient>(i), INGREDIENTS_BASE_NB);
  for (i = 0; static_cast<int>(i) < Kitchen::_nbCooks; ++i)
    this->_cooks.push_back(new Cook(*this));
  this->_id = id;
  this->_stockManagement = new Thread();
  this->_stop = false;
  this->_namedPipe = new NamedPipe(id);
  for (i = 0; static_cast<int>(i) < Kitchen::_nbCooks; ++i)
    this->_cooks[i]->create(&launchCook, this->_cooks[i]);
}

Kitchen::~Kitchen()
{
  for (unsigned int i = 0; static_cast<int>(i) < Kitchen::_nbCooks; ++i)
    this->_cooks[i]->join();
  delete[](this->_stock);
  delete (this->_stockManagement);
  delete (this->_namedPipe);
}

bool Kitchen::isAllFree() const {
  for (unsigned int i = 0; i < this->_cooks.size(); ++i)
    if (this->_cooks[i]->getPizza() != NULL)
      return (false);
  return (true);
}

void *incIngredients(void *data)
{
  Kitchen *kitchen;

  kitchen = static_cast<Kitchen *>(data);
  while (kitchen->getStop() == false)
    {
      usleep(Kitchen::_timerFill * 1000);
      kitchen->getMutex()->lock();
      for (unsigned int i = 0; i < NB_INGREDIENTS; ++i)
	{
	  if (kitchen->getStock()[i]->getAmount() < NB_INGREDIENTS)
	    kitchen->getStock()[i]->incIng();
	}
      kitchen->getMutex()->unlock();
    }
  return (NULL);
}

void Kitchen::waitOrder() {
  int max = this->_namedPipe->getFd(ANamedPipe::Kitchen + 1);
  struct timeval tv;

  this->_stockManagement->create(&incIngredients, this);
  while (this->getStop() == false) {
    FD_ZERO(&this->_listenfds);
    FD_SET(max, &this->_listenfds);
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (select(max + 1, &this->_listenfds, NULL, NULL, &tv) > 0)
      if (FD_ISSET(max, &this->_listenfds))
	this->getOrder();
  }
  this->_stockManagement->join();
}

void Kitchen::getOrder() {
  this->_namedPipe->read(ANamedPipe::Kitchen);
  std::string const ret = this->_namedPipe->getBuffer();
  if (ret[0] == '0')
    {
      APizza *newPizza = this->_factory.createPizza(static_cast<TypePizza>(ret[2]),
						    static_cast<TaillePizza>(ret[3]),
						    static_cast<int>(ret[1]));
      this->_mutex->lock();
      this->_pizzas.push_back(newPizza);
      this->_mutex->unlock();
    }
  else if (ret[0] == '1')
    this->giveCooksOccup();
  else if (ret[0] == '2')
    this->giveCooksIngredients();
}

void Kitchen::giveCooksOccup() const {
  std::ostringstream pizzaLeft;

  pizzaLeft << ((this->_cooks.size() * 2) - this->_pizzas.size()) << std::endl;
  this->_namedPipe->setBuffer(pizzaLeft.str());
  this->_namedPipe->write(ANamedPipe::Kitchen);
}

void Kitchen::giveCooksIngredients() const {
  std::ostringstream ingrStatus;

  for (unsigned int i = 0; i < NB_INGREDIENTS ; i++)
    ingrStatus << this->_stock[i]->getAmount();
  ingrStatus << std::endl;
  this->_namedPipe->setBuffer(ingrStatus.str());
  this->_namedPipe->write(ANamedPipe::Kitchen);
}

void Kitchen::givePizza(APizza const *pizza) const {
  std::ostringstream pizzaReady;

  pizzaReady << '0' << pizza->getIdCmd() << pizza->getType() << pizza->getSize() << std::endl;
  this->_namedPipe->setBuffer(pizzaReady.str());
  this->_namedPipe->write(ANamedPipe::Kitchen);
}

Ingredient **Kitchen::getStock() {
  return this->_stock;
}

bool Kitchen::getStop() const {
  return this->_stop;
}

void Kitchen::setStop(bool const stop) {
  this->_stop = stop;
}

ANamedPipe *Kitchen::getNamedPipe() const {
  return this->_namedPipe;
}

unsigned int Kitchen::getId() const {
  return this->_id;
}
