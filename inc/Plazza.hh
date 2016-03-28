//
// Plazza.hh for Plazza.hh in /home/acca_b/rendu/cpp_plazza
//
// Made by Baptiste Acca
// Login   <acca_b@epitech.net>
//
// Started on  Thu Apr 24 17:08:50 2014 Baptiste Acca
// Last update Sun Apr 27 16:15:55 2014 Baptiste Acca
//

#ifndef				PLAZZA_HH_
# define			PLAZZA_HH_

# include			"Reception.hh"

/* ERRORS */

# define BAD_ARGS		"[Plazza]: Usage: ./Plazza CookingTimeMultiplier CooksNumber TimeRefill"
# define NEG_ARG		"[Plazza]: Error: Arguments can't have negatives values"

class				Plazza {
private:
  Reception			*_reception;
  std::vector<Kitchen *>	_kitchens;
  bool				_open;

public:
  Plazza();
  ~Plazza();
  bool				isOpen() const;
  void				closePlazza(bool);
  void				makeBusiness();
};

#endif				/* PLAZZA_HH_ */
