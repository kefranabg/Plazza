//
// Thread.hh for Thread.hh in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Fri Apr 25 14:26:31 2014 abgral_f
// Last update Sat Apr 26 12:19:01 2014 LOEB Thomas
//

#ifndef                         THREAD_HH_
# define                        THREAD_HH_

#include			"AThread.hh"

class				Thread : public AThread
{
public:
  Thread();
  virtual ~Thread();
  virtual void                  create(void *(*start_routine)(void*), void *);
  virtual void                  join();
  virtual void                  exit();
};

#endif
