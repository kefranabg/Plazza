//
// Pizza.cpp for Pizza.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 16:52:25 2014 Baptiste Acca
// Last update Sat Apr 26 18:26:31 2014 LOEB Thomas
//

#include <unistd.h>
#include "Pizza.hh"

Pizza::Pizza()
{

}

Pizza::~Pizza()
{

}

void Pizza::bakePizza(double const &multiplier) const
{
  usleep(this->_cookTime * 1000000 * multiplier);
}

std::vector <Ingredient *> Pizza::getIngredients() const
{
  return (this->_ingredients);
}

TaillePizza Pizza::getSize() const
{
  return (this->_size);
}

TypePizza Pizza::getType() const
{
  return (this->_type);
}

int Pizza::getIdCmd() const
{
  return (this->_idCmd);
}

void Pizza::setIdCmd(int const &idCmd)
{
  this->_idCmd = idCmd;
}
