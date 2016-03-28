//
// Order.cpp for Order.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 18:48:11 2014 Baptiste Acca
// Last update Sun Apr 27 17:51:12 2014 LOEB Thomas
//

#include "Order.hh"
#include "Factory.hh"

Order::Order(std::vector<std::string *> pizzas, std::string cmd) {
  Factory tmp;

  for (unsigned int i = 0; i < pizzas.size(); ++i)
    this->_pizzas.push_back(tmp.createPizza(static_cast<TypePizza>((*pizzas[i])[2]),
					    static_cast<TaillePizza>((*pizzas[i])[3]),
					    static_cast<int>((*pizzas[i])[1])));
  this->_cmd = cmd;
  this->_time = ::clock();
}

Order::~Order() {}

bool Order::pizzaReady(std::string const & s) {
  for (unsigned int i = 0; i < this->_pizzas.size(); ++i)
    if (this->_pizzas[i]->getIdCmd() == s[1] &&
	this->_pizzas[i]->getType() == s[2] &&
	this->_pizzas[i]->getSize() == s[3]) {
      this->_pizzas.erase(this->_pizzas.begin() + i);
      if (this->_pizzas.empty() == true)
	{
	  this->_time = ::clock() - this->_time;
	  return (true);
	}
      return (false);
    }
  return (false);
}

clock_t Order::getTime() const {
  return (this->_time);
}

std::string const & Order::getCmd() const {
  return (this->_cmd);
}
