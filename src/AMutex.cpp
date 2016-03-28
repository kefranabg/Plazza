//
// AMutex.cpp for AMutex.cpp in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Fri Apr 25 14:01:42 2014 Baptiste Acca
// Last update Fri Apr 25 18:10:54 2014 LOEB Thomas
//

#include "AMutex.hh"

AMutex::AMutex() {
  pthread_mutex_init(&this->_mutex, NULL);
}

AMutex::~AMutex() {
  pthread_mutex_destroy(&this->_mutex);
}
