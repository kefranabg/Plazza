//
// Americana.cpp for Americana.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 17:04:34 2014 Baptiste Acca
// Last update Thu Apr 24 17:40:32 2014 Baptiste Acca
//

#include "Americana.hh"

Americana::Americana(int const &idCmd, TaillePizza const &size)
{
  this->_size = size;
  this->_type = AMERICAINE;
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
  tmp = new Ingredient(STEAK, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
}

Americana::Americana(TaillePizza const &size)
{
  this->_size = size;
  this->_type = AMERICAINE;
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
  tmp = new Ingredient(STEAK, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
}

Americana::~Americana()
{

}
