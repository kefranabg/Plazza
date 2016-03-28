//
// Factory.hh for Factory.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 17:51:45 2014 Baptiste Acca
// Last update Thu Apr 24 18:30:15 2014 Baptiste Acca
//

#ifndef FACTORY_HH_
#define FACTORY_HH_

#include "APizza.hh"

class Factory {
private:
  TypePizza _types[4];
  APizza *(Factory::*_typePtr[4])(TaillePizza const &, int const &) const;
private:
  APizza *createMargarita(TaillePizza const &, int const &) const;
  APizza *createAmericana(TaillePizza const &, int const &) const;
  APizza *createFantasia(TaillePizza const &, int const &) const;
  APizza *createRegina(TaillePizza const &, int const &) const;
public:
  Factory();
  ~Factory();
  APizza *createPizza(TypePizza const &, TaillePizza const &, int const &) const;
};

#endif /* FACTORY_HH_ */
