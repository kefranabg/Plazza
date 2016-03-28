//
// Thread.cpp for Thread.cpp in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Fri Apr 25 14:27:41 2014 abgral_f
// Last update Sat Apr 26 12:20:44 2014 LOEB Thomas
//

#include			"Thread.hh"

Thread::Thread() {}

Thread::~Thread() {}

void				Thread::create(void *(*start_routine)(void*), void *arg)
{
  if (::pthread_create(&(this->_thread), NULL, start_routine, arg) != 0)
    throw std::runtime_error(PTHREAD_CREATE_ERROR);
}

void				Thread::join()
{
  if (::pthread_join(this->_thread, NULL) != 0)
    throw std::runtime_error(PTHREAD_JOIN_ERROR);
}

void				Thread::exit()
{
  ::pthread_exit(NULL);
}
