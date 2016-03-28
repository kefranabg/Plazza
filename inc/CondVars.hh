//
// CondVars.hh for CondVars.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Fri Apr 25 13:48:27 2014 Baptiste Acca
// Last update Fri Apr 25 13:56:14 2014 Baptiste Acca
//

#ifndef CONDVARS_HH_
#define CONDVARS_HH_

#include "ACondVars.hh"

class CondVars : public ACondVars {
public:
  CondVars();
  virtual ~CondVars();
  virtual int timedwait();
  virtual int signal();
};

#endif /* CONDVARS_HH_ */
