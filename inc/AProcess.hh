//
// AProcess.hh for AProcess.hh in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Thu Apr 24 22:05:27 2014 abgral_f
// Last update Sun Apr 27 18:30:55 2014 LOEB Thomas
//

#ifndef                         APROCESS_HH_
# define                        APROCESS_HH_

#include			<sys/wait.h>
#include                        <unistd.h>
#include			<sys/types.h>

class                           AProcess
{
public:
  AProcess();
  virtual ~AProcess();
  virtual int                  fork() = 0;
  virtual int                  waitpid() const = 0;
  virtual pid_t			getPid() const = 0;
protected:
  pid_t				_pid;
};

#endif
