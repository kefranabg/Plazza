//
// AThreadPool.cpp for AThreadPool.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Fri Apr 25 15:13:27 2014 Baptiste Acca
// Last update Sun Apr 27 16:53:56 2014 LOEB Thomas
//

#include "AThreadPool.hh"

AThreadPool::AThreadPool()
{
  this->_cond = new CondVars();
  this->_mutex = new Mutex();
}

AThreadPool::~AThreadPool()
{
  delete(this->_cond);
  delete(this->_mutex);
}

AMutex * AThreadPool::getMutex() const {
  return (this->_mutex);
}

APizza * AThreadPool::takePizza() {
  APizza * ret = NULL;

  if (!this->_pizzas.empty()) {
    this->_mutex->lock();
    ret = this->_pizzas.back();
    this->_pizzas.pop_back();
    this->_mutex->unlock();
  }
  return (ret);
}

int AThreadPool::waitPizza(unsigned int sec) {
  this->_cond->setTimeOut(sec);
  return (this->_cond->timedwait());
}

int AThreadPool::freePizza() {
  return (this->_cond->signal());
}
