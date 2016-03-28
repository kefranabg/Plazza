//
// ACondVars.cpp for ACondVars.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Fri Apr 25 13:42:28 2014 Baptiste Acca
// Last update Sat Apr 26 18:09:04 2014 LOEB Thomas
//

#include "ACondVars.hh"

ACondVars::ACondVars()
{
  pthread_cond_init(&this->_cond, NULL);
  pthread_mutex_init(&this->_mutex, NULL);
}

ACondVars::~ACondVars()
{
  pthread_cond_destroy(&this->_cond);
  pthread_mutex_destroy(&this->_mutex);
}

void ACondVars::setTimeOut(unsigned int sec) {
  clock_gettime(CLOCK_REALTIME, &this->_timeout);
  this->_timeout.tv_sec += sec;
  this->_timeout.tv_nsec = 0;
}
