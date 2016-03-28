//
// AUI.hh for AUI.hh in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Thu Apr 24 15:59:52 2014 abgral_f
// Last update Sun Apr 27 12:24:03 2014 LOEB Thomas
//

#ifndef				AUI_HH_
# define			AUI_HH_

#include			<string>
#include			"IUI.hh"
// #include			"GUI.hh"

class				AUI : public IUI
{
protected:
  std::string			_line;
  // GUI				*_gui;

public:
  AUI();
  virtual ~AUI();
  std::string			getLine() const;
};

#endif
