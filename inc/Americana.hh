//
// Americana.hh for Americana.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 17:07:06 2014 Baptiste Acca
// Last update Thu Apr 24 17:36:16 2014 Baptiste Acca
//

#ifndef AMERICANA_HH_
#define AMERICANA_HH_

#include "Pizza.hh"

class Americana : public Pizza {
public:
  Americana(int const &, TaillePizza const &);
  Americana(TaillePizza const &);
  virtual ~Americana();
};

#endif /* AMERICANA_HH_ */
