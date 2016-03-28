//
// Margarita.hh for Margarita.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 15:50:41 2014 Baptiste Acca
// Last update Thu Apr 24 17:36:38 2014 Baptiste Acca
//

#ifndef MARGARITA_HH_
#define MARGARITA_HH_

#include "Pizza.hh"

class Margarita : public Pizza {
public:
  Margarita(int const &, TaillePizza const &);
  Margarita(TaillePizza const &);
  virtual ~Margarita();
};

#endif /* MARGARITA_HH_ */
