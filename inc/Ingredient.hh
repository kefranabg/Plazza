//
// Ingredient.hh for Ingredient.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 14:59:04 2014 Baptiste Acca
// Last update Sun Apr 27 12:59:03 2014 LOEB Thomas
//

#ifndef INGREDIENT_HH_
#define INGREDIENT_HH_

typedef enum TypeIngredient
  {
    DOE,
    TOMATO,
    GRUYERE,
    HAM,
    MUSHROOMS,
    STEAK,
    EGGPLANT,
    GOATCHEESE,
    CHIEFLOVE
  } TypeIngredient;

class Ingredient {
  TypeIngredient _type;
  unsigned int _amount;
public:
  Ingredient(TypeIngredient const &, unsigned int const &);
  ~Ingredient();
  TypeIngredient getType() const;
  unsigned int getAmount() const;
  void incIng();
  void decIng();
};

#endif /* INGREDIENT_HH_ */
