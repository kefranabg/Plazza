//
// Process.cpp for Process.cpp in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Fri Apr 25 13:17:42 2014 abgral_f
// Last update Sun Apr 27 18:31:22 2014 LOEB Thomas
//

#include			"Process.hh"

Process::Process() {}

Process::~Process() {}

int				Process::fork()
{
  this->_pid = ::fork();
  return (this->_pid);
}

int				Process::waitpid() const
{
  return (::waitpid(0, NULL, 0));
}

pid_t				Process::getPid() const
{
  return (this->_pid);
}
