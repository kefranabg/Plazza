//
// Pizza.hh for Pizza.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 16:52:43 2014 Baptiste Acca
// Last update Sat Apr 26 18:27:09 2014 LOEB Thomas
//

#ifndef PIZZA_HH_
#define PIZZA_HH_

#include "APizza.hh"

class Pizza : public APizza {
public:
  Pizza();
  virtual ~Pizza();
  virtual void bakePizza(double const &) const;
  virtual std::vector <Ingredient *> getIngredients() const;
  virtual TaillePizza getSize() const;
  virtual TypePizza getType() const;
  virtual int getIdCmd() const;
  virtual void setIdCmd(int const &);
};

#endif /* PIZZA_HH_ */
