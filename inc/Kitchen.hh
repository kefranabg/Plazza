//
// Kitchen.hh for Kitchen.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Fri Apr 25 15:20:55 2014 Baptiste Acca
// Last update Sun Apr 27 16:36:42 2014 Baptiste Acca
//

#ifndef KITCHEN_HH_
#define KITCHEN_HH_

#include		<sys/time.h>
#include		<sys/types.h>
#include		<unistd.h>
#include "AThreadPool.hh"
#include "Cook.hh"
#include "Factory.hh"
#include "NamedPipe.hh"

#define NB_INGREDIENTS		9
#define INGREDIENTS_BASE_NB	5

class Kitchen : public AThreadPool {
  unsigned int _id;
  std::vector<Cook *> _cooks;
  AThread *_stockManagement;
  Ingredient *_stock[NB_INGREDIENTS];
  bool _stop;
  ANamedPipe *_namedPipe;
  Factory _factory;
  fd_set _listenfds;

public:
  static double _multiplier;
  static int _nbCooks;
  static int _timerFill;

public:
  Kitchen(unsigned int);
  virtual ~Kitchen();
  bool isAllFree() const;
  virtual void waitOrder();
  virtual void getOrder();
  virtual void giveCooksOccup() const;
  virtual void giveCooksIngredients() const;
  virtual void givePizza(APizza const *) const;
  Ingredient **getStock();
  bool getStop() const;
  void setStop(bool const);
  ANamedPipe *getNamedPipe() const;
  unsigned int getId() const;
};

#endif /* KITCHEN_HH_ */
