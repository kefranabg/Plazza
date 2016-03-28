//
// AThread.hh for AThread.hh in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Fri Apr 25 14:20:56 2014 abgral_f
// Last update Fri Apr 25 19:14:17 2014 LOEB Thomas
//

#ifndef                         ATHREAD_HH_
# define                        ATHREAD_HH_

#include			<stdexcept>
#include			<pthread.h>

/* ERRORS */

# define PTHREAD_CREATE_ERROR   "[Plazza]: ERROR: System call 'fork' failed\n"
# define PTHREAD_JOIN_ERROR	"[Plazza]: ERROR: System call 'fork' failed\n"

class                           AThread
{
protected:
  pthread_t			_thread;

public:
  AThread();
  virtual ~AThread();
  virtual void                  create(void *(*start_routine)(void*), void *) = 0;
  virtual void                  join() = 0;
  virtual void                  exit() = 0;
};


#endif
