//
// Process.hh for Process.hh in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Fri Apr 25 13:15:47 2014 abgral_f
// Last update Sun Apr 27 18:30:29 2014 LOEB Thomas
//

#ifndef                         PROCESS_HH_
# define                        PROCESS_HH_

#include			"AProcess.hh"

class                           Process : public AProcess
{
public:
  Process();
  virtual ~Process();
  virtual int                  fork();
  virtual int                  waitpid() const;
  virtual pid_t                 getPid() const;
};

#endif
