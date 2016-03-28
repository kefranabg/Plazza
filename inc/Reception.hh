//
// Reception.hh for Reception.hh in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Thu Apr 24 15:58:19 2014 abgral_f
// Last update Sun Apr 27 18:23:35 2014 LOEB Thomas
//

#ifndef				RECEPTION_HH_
# define			RECEPTION_HH_

#include			<vector>
#include			<sys/time.h>
#include			<sys/types.h>
#include			<unistd.h>
#include			"AUI.hh"
#include			"Order.hh"

class				Reception : public AUI
{
private:
  std::vector<Order *>		_orders;
  fd_set			_listenfds;

public:
  Reception();
  virtual ~Reception();
  virtual void			getOrder(std::vector<Kitchen *> &);
  virtual int			getCooksOccup(Kitchen *);
  virtual bool			getIngredients(Kitchen *);
  void				listen(std::vector<Kitchen *> &);
  void				algorithm(std::vector<Kitchen *> &, std::vector<std::string *> const &);
  void				createKitchen(std::vector<Kitchen *> &);
};

template <typename T>
T getNb(std::string const &);

# endif
