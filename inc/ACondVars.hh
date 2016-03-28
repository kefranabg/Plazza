//
// ACondVars.hh for ACondVars.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Fri Apr 25 13:42:18 2014 Baptiste Acca
// Last update Sat Apr 26 16:57:08 2014 LOEB Thomas
//

#ifndef ACONDVARS_HH_
#define ACONDVARS_HH_

#include <pthread.h>

class ACondVars {
protected:
  pthread_cond_t _cond;
  pthread_mutex_t _mutex;
  struct timespec _timeout;

public:
  ACondVars();
  virtual ~ACondVars();
  void setTimeOut(unsigned int);
  virtual int timedwait() = 0;
  virtual int signal() = 0;
};

#endif /* ACONDVARS_HH_ */
