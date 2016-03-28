//
// Fantasia.hh for Fantasia.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 17:07:59 2014 Baptiste Acca
// Last update Thu Apr 24 17:49:14 2014 Baptiste Acca
//

#ifndef FANTASIA_HH_
#define FANTASIA_HH_

#include "Pizza.hh"

class Fantasia : public Pizza {
public:
  Fantasia(int const &, TaillePizza const &);
  Fantasia(TaillePizza const &);
  virtual ~Fantasia();
};

#endif /* FANTASIA_HH_ */
