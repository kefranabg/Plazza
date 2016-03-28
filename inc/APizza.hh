//
// APizza.hh for APizza.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 15:20:56 2014 Baptiste Acca
// Last update Sat Apr 26 18:26:46 2014 LOEB Thomas
//

#ifndef APIZZA_HH_
#define APIZZA_HH_

#include <vector>
#include "Ingredient.hh"

typedef enum TypePizza
  {
    REGINA = 1,
    MARGARITA = 2,
    AMERICAINE = 4,
    FANTASIA = 8
  } TypePizza;

typedef enum TaillePizza
  {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
  } TaillePizza;

class APizza {
protected:
  std::vector <Ingredient *> _ingredients;
  unsigned int _cookTime;
  TypePizza _type;
  TaillePizza _size;
  int _idCmd;

public:
  APizza();
  ~APizza();
  virtual void bakePizza(double const &) const = 0;
  virtual std::vector <Ingredient *> getIngredients() const = 0;
  virtual TaillePizza getSize() const = 0;
  virtual TypePizza getType() const = 0;
  virtual int getIdCmd() const = 0;
  virtual void setIdCmd(int const &) = 0;
};

#endif /* APIZZA_HH_ */
