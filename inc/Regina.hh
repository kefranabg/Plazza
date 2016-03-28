//
// Regina.hh for Regina.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 17:02:35 2014 Baptiste Acca
// Last update Thu Apr 24 17:36:26 2014 Baptiste Acca
//

#ifndef REGINA_HH_
#define REGINA_HH_

#include "Pizza.hh"

class Regina : public Pizza {
public:
  Regina(int const &, TaillePizza const &);
  Regina(TaillePizza const &);
  virtual ~Regina();
};

#endif /* REGINA_HH_ */
