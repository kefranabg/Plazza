//
// Plazza.cpp for Plazza.cpp in /home/loeb_t/rendu/cpp_plazza
//
// Made by LOEB Thomas
// Login   <loeb_t@epitech.net>
//
// Started on  Sun Apr 27 12:48:28 2014 LOEB Thomas
// Last update Sun Apr 27 18:33:14 2014 LOEB Thomas
//

#include	"Plazza.hh"
#include	"Process.hh"

Plazza::Plazza() {
  this->_reception = new Reception();
  this->_open = true;
}

Plazza::~Plazza() {
  delete(this->_reception);
}

bool Plazza::isOpen() const {
  return (this->_open);
}

void Plazza::closePlazza(bool b) {
  this->_open = !b;
}

void Plazza::makeBusiness() {
  Process wait;

  while (this->isOpen() == true)
    {
      this->_reception->listen(this->_kitchens);
      if (this->_reception->getLine() == "/closed")
      	this->closePlazza(true);
    }
  while (!wait.waitpid());
}
