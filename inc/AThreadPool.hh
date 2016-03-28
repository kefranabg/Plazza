//
// AThreadPool.hh for AThreadPool.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Fri Apr 25 15:13:31 2014 Baptiste Acca
// Last update Sun Apr 27 18:48:48 2014 LOEB Thomas
//

#ifndef ATHREADPOOL_HH_
#define ATHREADPOOL_HH_

#include "CondVars.hh"
#include "Mutex.hh"
#include "Pizza.hh"

class AThreadPool {
protected:
  ACondVars *_cond;
  AMutex *_mutex;
  std::vector<APizza *> _pizzas;

public:
  AThreadPool();
  virtual ~AThreadPool();
  AMutex * getMutex() const;
  APizza * takePizza();
  int waitPizza(unsigned int);
  int freePizza();
  virtual void waitOrder() = 0;
  virtual void getOrder() = 0;
  virtual void giveCooksOccup() const = 0;
  virtual void giveCooksIngredients() const = 0;
  virtual void givePizza(APizza const *) const = 0;
};

#endif /* ATHREADPOOL_HH_ */
