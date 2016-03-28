//
// Parser.cpp for Parser.cpp in /home/abgral_f/rendu/cpp_plazza
//
// Made by abgral_f
// Login   <abgral_f@epitech.net>
//
// Started on  Fri Apr 25 17:14:42 2014 abgral_f
// Last update Sun Apr 27 18:53:23 2014 abgral_f
//

#include				"Parser.hh"

Parser::Parser()
{

}

Parser::~Parser()
{

}

void					Parser::initToCompare()
{
  std::vector<std::string>		type;
  std::vector<std::string>		size;

  type.push_back(REGINA_STR);
  type.push_back(MARGARITA_STR);
  type.push_back(AMERICAINE_STR);
  type.push_back(FANTASIA_STR);
  size.push_back(SIZE_S);
  size.push_back(SIZE_M);
  size.push_back(SIZE_L);
  size.push_back(SIZE_XL);
  size.push_back(SIZE_XXL);
  this->_toCompare.push_back(type);
  this->_toCompare.push_back(size);
}

void					Parser::initTranscription()
{
  std::vector<int>              type;
  std::vector<int>              size;

  type.push_back(REGINA);
  type.push_back(MARGARITA);
  type.push_back(AMERICAINE);
  type.push_back(FANTASIA);
  size.push_back(S);
  size.push_back(M);
  size.push_back(L);
  size.push_back(XL);
  size.push_back(XXL);
  this->_transcription.push_back(type);
  this->_transcription.push_back(size);
}

std::vector<std::string>		Parser::getWords(std::string const &line)
{
  std::istringstream			tmp(line);
  std::vector<std::string>		words;
  std::string				word;

  while (42)
    {
      tmp >> word;
      if (tmp == 0)
	break;
      words.push_back(word);
    }
  return (words);
}

void					Parser::pushNbPizzas(std::string const &line)
{
  std::istringstream                    tmp(this->_nbPizzas);
  unsigned int                          count;
  unsigned int				nb_pizzas;

  tmp >> nb_pizzas;
  count = 0;
  if (nb_pizzas == 0)
    throw std::logic_error(NO_PIZZAS);
  while (count != nb_pizzas)
    {
      this->_listPizzas.push_back(new std::string(line));
      count++;
    }
}

void					Parser::countPizzas(unsigned int i, bool &check,
							    std::vector<std::string> const &words)
{
  unsigned int                          count;

  if (words[i].size() < 2)
    throw std::logic_error(WRONG_SYNTHAX);
  count = 1;
  this->_nbPizzas = "0";
  while (words[i][count] != '\0')
    {

      if (words[i][count] >= '0' && words[i][count] <= '9')
	this->_nbPizzas += words[i][count];
      else if (words[i][count] != ';')
	throw std::logic_error(WRONG_SYNTHAX);
      else
	{
	  check = true;
	  break;
	}
      count++;
    }
}

void					Parser::doTranscription(std::vector<std::string> const &words)
{
  std::string				tmp;
  unsigned int				count;
  unsigned int				i = 0;
  bool					check = true;

  while (check == true)
    {
      tmp = "";
      check = false;
      count = 0;
      tmp += count;
      tmp += this->_idCommand;
      if (i == words.size())
	throw std::logic_error(WRONG_SYNTHAX);
      while (count != this->_toCompare[0].size() && words[i] != this->_toCompare[0][count])
	count++;
      if (count == this->_toCompare[0].size())
	throw std::logic_error(WRONG_SYNTHAX);
      tmp += this->_transcription[0][count];
      i++;
      count = 0;
      if (i == words.size())
	throw std::logic_error(WRONG_SYNTHAX);
      while (count != this->_toCompare[1].size() && words[i] != this->_toCompare[1][count])
	count++;
      if (count == this->_toCompare[1].size())
	throw std::logic_error(WRONG_SYNTHAX);
      tmp += this->_transcription[1][count];
      i++;
      if (i == words.size())
	throw std::logic_error(WRONG_SYNTHAX);
      if (words[i][0] != 'x')
	throw std::logic_error(WRONG_SYNTHAX);
      this->countPizzas(i, check, words);
      i++;
      if (check == false)
	{
	  if (i != words.size())
	    if (words[i] == ";")
	      check = true;
	  i++;
	}
      this->pushNbPizzas(tmp);
    }
}

std::vector<std::string *> const		Parser::checkOrder(std::string &line)
{
  this->initToCompare();
  this->initTranscription();
  this->doTranscription(this->getWords(line));
  return (this->_listPizzas);
}

void					Parser::setIdCommand(unsigned int idCommand)
{
  this->_idCommand = idCommand;
}
