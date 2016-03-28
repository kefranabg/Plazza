//
// Factory.cpp for Factory.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 17:58:17 2014 Baptiste Acca
// Last update Sun Apr 27 12:59:36 2014 LOEB Thomas
//

#include <iostream>
#include "Factory.hh"
#include "Regina.hh"
#include "Americana.hh"
#include "Margarita.hh"
#include "Fantasia.hh"

Factory::Factory()
{
  this->_types[0] = REGINA;
  this->_typePtr[0] = &Factory::createRegina;
  this->_types[1] = MARGARITA;
  this->_typePtr[1] = &Factory::createMargarita;
  this->_types[2] = AMERICAINE;
  this->_typePtr[2] = &Factory::createAmericana;
  this->_types[3] = FANTASIA;
  this->_typePtr[3] = &Factory::createFantasia;
}

Factory::~Factory()
{

}

APizza *Factory::createRegina(TaillePizza const &size, int const &idCmd) const
{
  return new Regina(idCmd, size);
}

APizza *Factory::createMargarita(TaillePizza const &size, int const &idCmd) const
{
  return new Margarita(idCmd, size);
}

APizza *Factory::createAmericana(TaillePizza const &size, int const &idCmd) const
{
  return new Americana(idCmd, size);
}

APizza *Factory::createFantasia(TaillePizza const &size, int const &idCmd) const
{
  return new Fantasia(idCmd, size);
}

APizza *Factory::createPizza(TypePizza const &type, TaillePizza const &size, int const &idCmd) const
{
  unsigned int i;

  for (i = 0; i < 4 && this->_types[i] != type; i++);
  if (i < 4 && this->_types[i] == type)
    return (this->*_typePtr[i])(size, idCmd);
  return (NULL);
}
