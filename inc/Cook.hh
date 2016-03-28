//
// Cook.hh for Cook.hh in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Fri Apr 25 15:06:27 2014 abgral_f
// Last update Sun Apr 27 16:15:22 2014 LOEB Thomas
//

#ifndef			COOK_HH_
# define		COOK_HH_

#include		"Ingredient.hh"
#include		"Thread.hh"

class			Kitchen;

class			Cook : public Thread
{
public:
  Cook(Kitchen &);
  virtual ~Cook();
  APizza *		getPizza() const;
  bool			takeIngredients(AMutex *, Ingredient *[], APizza *);
  void			makePizzas(Kitchen *);
  Kitchen *		getATP() const;

private:
  Kitchen		*_atp;
  APizza		*_pizza;
};

void			*launchCook(void *);

#endif
