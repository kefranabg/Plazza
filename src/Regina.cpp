//
// Regina.cpp for Regina.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 17:02:03 2014 Baptiste Acca
// Last update Thu Apr 24 17:39:41 2014 Baptiste Acca
//

#include "Regina.hh"

Regina::Regina(int const &idCmd, TaillePizza const &size)
{
  this->_size = size;
  this->_type = REGINA;
  this->_cookTime = 2;
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
  tmp = new Ingredient(HAM, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(MUSHROOMS, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
}

Regina::Regina(TaillePizza const &size)
{
  this->_size = size;
  this->_type = REGINA;
  this->_cookTime = 2;
  Ingredient *tmp = new Ingredient(DOE, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(TOMATO, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(GRUYERE, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(HAM, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(MUSHROOMS, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
}

Regina::~Regina()
{

}
