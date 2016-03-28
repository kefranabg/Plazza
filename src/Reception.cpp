//
// Reception.cpp for Reception.cpp in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Thu Apr 24 16:06:07 2014 abgral_f
// Last update Sun Apr 27 18:46:25 2014 LOEB Thomas
//

#include		<iostream>
#include		"Reception.hh"
#include		"Parser.hh"
#include		"Process.hh"

Reception::Reception() {}

Reception::~Reception() {}

void			Reception::getOrder(std::vector<Kitchen *> & kitchens)
{
  Parser		p;
  std::vector<std::string *> pizzas;

  if (!std::getline(std::cin, this->_line, '\n'))
    this->_line = "/closed";
  if (this->_line != "/closed") {
    p.setIdCommand(this->_orders.size() + 1);
    try {
      pizzas = p.checkOrder(this->_line);
      this->_orders.push_back(new Order(pizzas, this->_line));
      this->algorithm(kitchens, pizzas);
    } catch (std::logic_error le) {
      std::cerr << le.what() << std::endl;
    }
  }
}

int			Reception::getCooksOccup(Kitchen * k)
{
  std::string cmd("1");
  k->getNamedPipe()->setBuffer(cmd);
  k->getNamedPipe()->write(ANamedPipe::Reception);
  k->getNamedPipe()->read(ANamedPipe::Reception);
  std::string const ret = k->getNamedPipe()->getBuffer();
  return (getNb<int>(ret));
}

bool			Reception::getIngredients(Kitchen * k)
{
  std::string cmd("2");
  k->getNamedPipe()->setBuffer(cmd);
  k->getNamedPipe()->write(ANamedPipe::Reception);
  k->getNamedPipe()->read(ANamedPipe::Reception);
  std::string const ret = k->getNamedPipe()->getBuffer();
  for (unsigned int i = 0; i < NB_INGREDIENTS ; ++i)
    if (ret[i] == '0')
      return (false);
  return (true);
}

void			Reception::createKitchen(std::vector<Kitchen *> & ks) {
  Process		p;
  Kitchen *		k;
  unsigned int		idx;
  unsigned int		i;

  if (p.fork() == 0) {
    idx = ks.size() + 1;
    k = new Kitchen(idx);
    ks.push_back(k);
    k->getNamedPipe()->open(ANamedPipe::Kitchen);
    k->waitOrder();
    for (i = 0; i < ks.size() && ks[i]->getId() != idx; ++i);
    ks.erase(ks.begin() + i);
    k->getNamedPipe()->close(ANamedPipe::Kitchen);
    k->getNamedPipe()->close(ANamedPipe::Reception);
    delete (k);
  } else if (p.getPid() > 0) {
    k->getNamedPipe()->open(ANamedPipe::Reception);
  }
}

void			Reception::algorithm(std::vector<Kitchen *> & ks, std::vector<std::string *> const & ps)
{
  int			idxK;
  int			size_min;
  int			tmp;
  unsigned int		j ;

  for (unsigned int i = 0; i < ps.size(); ++i) {
    size_min = Kitchen::_nbCooks * 2;
    idxK = -1;
    for (j = 0; j < ks.size(); ++j)
      if ((tmp = this->getCooksOccup(ks[j])) < size_min &&
	  this->getIngredients(ks[j]) == true) {
	size_min = tmp;
	idxK = j;
      }
    if (idxK == -1) {
      idxK = j;
      this->createKitchen(ks);
    }
    ks[idxK]->getNamedPipe()->setBuffer(*ps[i]);
    ks[idxK]->getNamedPipe()->write(ANamedPipe::Reception);
  }
}

void			Reception::listen(std::vector<Kitchen *> & kitchens) {
  struct timeval	tv;
  int			max = 0;

  FD_ZERO(&this->_listenfds);
  FD_SET(0, &this->_listenfds);
  for (unsigned int i = 0; i < kitchens.size(); ++i)
    {
      if (kitchens[i]->getNamedPipe()->getFd(ANamedPipe::Reception + 1) > max)
	max = kitchens[i]->getNamedPipe()->getFd(ANamedPipe::Reception + 1);
      FD_SET(kitchens[i]->getNamedPipe()->getFd(ANamedPipe::Reception + 1), &this->_listenfds);
    }
  tv.tv_sec = 1;
  tv.tv_usec = 0;
  if (select(max + 1, &this->_listenfds, NULL, NULL, &tv) > 0)
    {
      if (FD_ISSET(0, &this->_listenfds))
	getOrder(kitchens);
      for (unsigned int i = 0; i < kitchens.size(); ++i)
	if (FD_ISSET(kitchens[i]->getNamedPipe()->getFd(ANamedPipe::Reception + 1), &this->_listenfds))
	  {
	    kitchens[i]->getNamedPipe()->read(ANamedPipe::Reception);
	    std::string const ret = kitchens[i]->getNamedPipe()->getBuffer();
	    if (this->_orders[ret[1]]->pizzaReady(ret) == true)
	      {
		std::cout << "Command \""
			  << this->_orders[ret[1]]->getCmd()
			  << "\" done in "
			  << static_cast<double>(this->_orders[ret[1]]->getTime() / CLOCKS_PER_SEC)
			  << " second(s)"
			  << std::endl;
		this->_orders.erase(this->_orders.begin() + ret[1]);
	      }
	  }
    }
}
