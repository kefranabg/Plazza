//
// IUI.hh for IUI.hh in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Thu Apr 24 15:53:54 2014 abgral_f
// Last update Sun Apr 27 18:21:01 2014 LOEB Thomas
//

#ifndef				IUI_HH_
# define			IUI_HH_

#include			"Kitchen.hh"

class				IUI {
public:
  virtual ~IUI() {}
  virtual void			getOrder(std::vector<Kitchen *> &) = 0;
  virtual int			getCooksOccup(Kitchen *) = 0;
  virtual bool			getIngredients(Kitchen *) = 0;
};

# endif
