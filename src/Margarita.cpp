//
// Margarita.cpp for Margarita.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 15:50:38 2014 Baptiste Acca
// Last update Thu Apr 24 17:40:04 2014 Baptiste Acca
//

#include "Margarita.hh"

Margarita::Margarita(int const &idCmd, TaillePizza const &size)
{
  this->_size = size;
  this->_type = MARGARITA;
  this->_cookTime = 1;
  this->_idCmd = idCmd;
  Ingredient *tmp = new Ingredient(DOE, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(TOMATO, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(GRUYERE, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
}

Margarita::Margarita(TaillePizza const &size)
{
  this->_size = size;
  this->_type = MARGARITA;
  this->_cookTime = 1;
  Ingredient *tmp = new Ingredient(DOE, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(TOMATO, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(GRUYERE, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
}

Margarita::~Margarita()
{

}
