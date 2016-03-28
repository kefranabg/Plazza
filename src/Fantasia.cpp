//
// Fantasia.cpp for Fantasia.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 17:05:48 2014 Baptiste Acca
// Last update Thu Apr 24 17:41:05 2014 Baptiste Acca
//

#include "Fantasia.hh"

Fantasia::Fantasia(int const &idCmd, TaillePizza const &size)
{
  this->_size = size;
  this->_type = FANTASIA;
  this->_cookTime = 4;
  this->_idCmd = idCmd;
  Ingredient *tmp = new Ingredient(DOE, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(TOMATO, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(EGGPLANT, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(GOATCHEESE, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(CHIEFLOVE, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
}

Fantasia::Fantasia(TaillePizza const &size)
{
  this->_size = size;
  this->_type = FANTASIA;
  this->_cookTime = 4;
  Ingredient *tmp = new Ingredient(DOE, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(TOMATO, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(EGGPLANT, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(GOATCHEESE, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
  tmp = new Ingredient(CHIEFLOVE, 1);
  this->_ingredients.push_back(tmp);
  delete tmp;
}

Fantasia::~Fantasia()
{

}
