//
// Mutex.cpp for Mutex.cpp in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Fri Apr 25 12:56:06 2014 abgral_f
// Last update Fri Apr 25 18:30:05 2014 LOEB Thomas
//

#include                "Mutex.hh"

Mutex::Mutex() {}

Mutex::~Mutex() {}

void                    Mutex::lock() {
  pthread_mutex_lock(&this->_mutex);
}

void                    Mutex::unlock() {
  pthread_mutex_unlock(&this->_mutex);
}
