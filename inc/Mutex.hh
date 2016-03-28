//
// Mutex.hh for Mutex.hh in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Fri Apr 25 12:57:24 2014 abgral_f
// Last update Fri Apr 25 18:23:19 2014 LOEB Thomas
//

#ifndef                         MUTEX_HH_
# define                        MUTEX_HH_

#include                        "AMutex.hh"

class                           Mutex : public AMutex
{
public:
  Mutex();
  virtual ~Mutex();
  virtual void                  lock();
  virtual void                  unlock();
};

#endif
