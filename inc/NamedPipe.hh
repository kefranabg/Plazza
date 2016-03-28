//
// NamedPipe.hh for NamedPipe.hh in /home/loeb_t/rendu/cpp_plazza
//
// Made by LOEB Thomas
// Login   <loeb_t@epitech.net>
//
// Started on  Fri Apr 25 15:19:35 2014 LOEB Thomas
// Last update Fri Apr 25 15:43:02 2014 LOEB Thomas
//

#ifndef			NAMEDPIPE_HH_
# define		NAMEDPIPE_HH_

# include		"ANamedPipe.hh"

# define		RIGHTS		0644

class			NamedPipe : public ANamedPipe {
public:
  NamedPipe(unsigned int);
  virtual ~NamedPipe();
  virtual void		mkfifo();
  virtual void		unlink();
  virtual void		open(ANamedPipe::Speaker);
  virtual void		close(ANamedPipe::Speaker);
  virtual void		write(ANamedPipe::Speaker);
  virtual void		read(ANamedPipe::Speaker);
};

#endif
