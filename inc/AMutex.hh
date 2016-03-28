//
// Amutex.hh for Amutex.hh in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Thu Apr 24 21:18:53 2014 abgral_f
// Last update Fri Apr 25 18:28:10 2014 LOEB Thomas
//

#ifndef				AMUTEX_HH_
# define			AMUTEX_HH_

#include			<pthread.h>

class				AMutex {
protected:
  pthread_mutex_t		_mutex;

public:
  AMutex();
  virtual ~AMutex();
  virtual void			lock() = 0;
  virtual void			unlock() = 0;
};

#endif
