//
// Ingredient.cpp for Ingredient.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 14:59:11 2014 Baptiste Acca
// Last update Thu Apr 24 15:19:34 2014 Baptiste Acca
//

#include "Ingredient.hh"

Ingredient::Ingredient(TypeIngredient const &type, unsigned int const &amount)
{
  this->_type = type;
  this->_amount = amount;
}

Ingredient::~Ingredient()
{

}

TypeIngredient Ingredient::getType() const
{
  return this->_type;
}

unsigned int Ingredient::getAmount() const
{
  return this->_amount;
}

void Ingredient::incIng()
{
  this->_amount++;
}

void Ingredient::decIng()
{
  this->_amount--;
}
