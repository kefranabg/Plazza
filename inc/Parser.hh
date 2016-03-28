//
// Parser.hh for Parser.hh in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Fri Apr 25 17:12:06 2014 abgral_f
// Last update Sun Apr 27 14:34:20 2014 abgral_f
//

#ifndef                         PARSER_HH_
# define                        PARSER_HH_

#include			<stdexcept>
#include		        <sstream>
#include			<vector>
#include			<iostream>
#include			<string>
#include			"APizza.hh"

/* ERRORS */

# define WRONG_SYNTHAX		"Synthax error : TYPE SIZE NUMBER[; TYPE SIZE NUMBER]"
# define NO_PIZZAS		"You cannot command 0 pizza"

# define REGINA_STR		"regina"
# define MARGARITA_STR		"margarita"
# define AMERICAINE_STR		"americaine"
# define FANTASIA_STR		"fantasia"

# define SIZE_S			"S"
# define SIZE_M			"M"
# define SIZE_L			"L"
# define SIZE_XL		"XL"
# define SIZE_XXL	        "XXL"

class							Parser
{
public:
  Parser();
  ~Parser();
  std::vector<std::string *> const			checkOrder(std::string &);
  void							setIdCommand(unsigned int);
private:
  void							pushNbPizzas(std::string const &);
  void							countPizzas(unsigned int, bool &,
								    std::vector<std::string> const &);
  void							initToCompare();
  void							initTranscription();
  std::vector<std::string>				getWords(std::string const &);
  void							doTranscription(std::vector<std::string> const &);
private:
  std::string						_nbPizzas;
  unsigned int						_idCommand;
  std::vector<std::string *>				_listPizzas;
  std::vector<std::vector<std::string> >		_toCompare;
  std::vector<std::vector<int> >			_transcription;
};

#endif
