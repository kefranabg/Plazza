//
// main.cpp for main.cpp in /home/loeb_t/rendu/cpp_plazza
//
// Made by LOEB Thomas
// Login   <loeb_t@epitech.net>
//
// Started on  Fri Apr 25 16:47:49 2014 LOEB Thomas
// Last update Sun Apr 27 18:50:06 2014 LOEB Thomas
//

#include		<sstream>
#include		<iostream>
#include		"Plazza.hh"

template<typename T>
T			getNb(std::string const &nb)
{
  T		ret;
  std::stringstream	oss(nb);

  oss >> ret;
  return ret;
}

void			parsParameters(int ac, char **av)
{
  if (ac != 4)
    throw std::runtime_error(BAD_ARGS);
  if ((Kitchen::_multiplier = getNb<double>(av[1])) < 0
      || (Kitchen::_nbCooks = getNb<int>(av[2])) < 0
      || (Kitchen::_timerFill = getNb<int>(av[3])) < 0)
    throw std::runtime_error(NEG_ARG);
}

int			main(int ac, char **av) {
  Plazza		plazza;

  try
    {
      parsParameters(ac, av);
      plazza.makeBusiness();
    }
  catch (std::runtime_error e) {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
