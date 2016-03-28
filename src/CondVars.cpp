//
// CondVars.cpp for CondVars.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Fri Apr 25 13:48:18 2014 Baptiste Acca
// Last update Sat Apr 26 16:47:32 2014 LOEB Thomas
//

#include "CondVars.hh"

CondVars::CondVars() {
}

CondVars::~CondVars() {
}

int CondVars::timedwait()
{
  return (pthread_cond_timedwait(&(this->_cond), &(this->_mutex), &(this->_timeout)));
}

int CondVars::signal()
{
  return (pthread_cond_signal(&(this->_cond)));
}
