//
// Cook.cpp for Cook.cpp in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Fri Apr 25 15:17:39 2014 abgral_f
// Last update Sun Apr 27 16:16:51 2014 LOEB Thomas
//

#include	<cerrno>
#include	"Kitchen.hh"

Cook::Cook(Kitchen & atp) : _atp(&atp), _pizza(NULL) {}

Cook::~Cook() {}

APizza *	Cook::getPizza() const {
  return (this->_pizza);
}

bool		Cook::takeIngredients(AMutex *am, Ingredient *ing[NB_INGREDIENTS], APizza *ap) {
  am->lock();
  for (unsigned int i = 0; i < ap->getIngredients().size(); ++i)
    if (ing[ap->getIngredients()[i]->getType()]->getAmount() <= 0)
      return (false);
    else
      ing[ap->getIngredients()[i]->getType()]->decIng();
  am->unlock();
  return (true);
}

void		Cook::makePizzas(Kitchen *atp) {
  while (atp->getStop() == false)
    if (this->_pizza == NULL && (this->_pizza = atp->takePizza()) == NULL) {
      if (atp->waitPizza(5) == ETIMEDOUT &&
	  atp->isAllFree() == true)
	atp->setStop(true);
    } else {
      if (this->takeIngredients(atp->getMutex(), atp->getStock(), this->_pizza) == true) {
	this->_pizza->bakePizza(atp->_multiplier);
	atp->givePizza(this->_pizza);
	this->_pizza = NULL;
      }
      atp->freePizza();
    }
}

Kitchen *	Cook::getATP() const {
  return (this->_atp);
}

void		*launchCook(void *cook) {
  Cook		*_cook = static_cast<Cook *>(cook);

  _cook->makePizzas(_cook->getATP());
  return (NULL);
}
