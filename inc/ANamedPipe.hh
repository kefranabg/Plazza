//
// ANamedPipe.hh for ANamedPipe.hh in /home/loeb_t/rendu/cpp_plazza
//
// Made by LOEB Thomas
// Login   <loeb_t@epitech.net>
//
// Started on  Fri Apr 25 13:13:36 2014 LOEB Thomas
// Last update Fri Apr 25 16:29:41 2014 LOEB Thomas
//

#ifndef			ANAMEDPIPE_HH_
# define		ANAMEDPIPE_HH_

# include		<string>

# define		NB_PIPE		2
# define		SIZE_BUFFER	4096
# define		K_TO_R(x)	("k"+x+"_to_r")
# define		R_TO_K(x)	("r_to_k"+x)

class			ANamedPipe {
public:
  typedef enum		Speaker
    {
      Kitchen		= 0,
      Reception		= 2
    }			Speaker;

protected:
  std::string		_filenames[NB_PIPE];
  int			_fds[NB_PIPE * 2];
  std::string		_buffer;

public:
  ANamedPipe(unsigned int);
  virtual ~ANamedPipe();
  std::string const &	getFilename(unsigned int) const;
  int			getFd(unsigned int) const;
  std::string const &	getBuffer() const;
  void			setBuffer(std::string const &);
  virtual void		mkfifo() = 0;
  virtual void		unlink() = 0;
  virtual void		open(ANamedPipe::Speaker) = 0;
  virtual void		write(ANamedPipe::Speaker) = 0;
  virtual void		read(ANamedPipe::Speaker) = 0;
  virtual void		close(ANamedPipe::Speaker) = 0;
};

#endif
