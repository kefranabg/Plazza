//
// Order.hh for Order.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 18:45:28 2014 Baptiste Acca
// Last update Sun Apr 27 16:47:39 2014 LOEB Thomas
//

#ifndef ORDER_HH_
#define ORDER_HH_

#include <time.h>
#include <string>
#include "APizza.hh"

class Order {
private:
  std::string _cmd;
  std::vector <APizza *> _pizzas;
  clock_t _time;

public:
  Order(std::vector<std::string *>, std::string);
  ~Order();
  bool pizzaReady(std::string const &);
  clock_t getTime() const;
  std::string const & getCmd() const;
};

#endif /* ORDER_HH_ */
