//
// NamedPipe.cpp for NamedPipe.cpp in /home/loeb_t/rendu/cpp_plazza
//
// Made by LOEB Thomas
// Login   <loeb_t@epitech.net>
//
// Started on  Fri Apr 25 15:21:03 2014 LOEB Thomas
// Last update Sun Apr 27 18:45:40 2014 LOEB Thomas
//

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"NamedPipe.hh"

NamedPipe::NamedPipe(unsigned int noKitchen) : ANamedPipe(noKitchen) {
  this->mkfifo();
}

NamedPipe::~NamedPipe() {
  this->unlink();
}

void NamedPipe::mkfifo() {
  ::mkfifo(this->_filenames[0].c_str(), RIGHTS);
  ::mkfifo(this->_filenames[1].c_str(), RIGHTS);
}

void NamedPipe::unlink() {
  ::unlink(this->_filenames[0].c_str());
  ::unlink(this->_filenames[1].c_str());
}

void NamedPipe::open(ANamedPipe::Speaker speaker) {
  if (speaker == ANamedPipe::Kitchen) {
    this->_fds[speaker] = ::open(this->_filenames[0].c_str(), O_WRONLY);
    this->_fds[speaker + 1] = ::open(this->_filenames[1].c_str(), O_RDONLY);
  } else {
    this->_fds[speaker + 1] = ::open(this->_filenames[0].c_str(), O_RDONLY);
    this->_fds[speaker] = ::open(this->_filenames[1].c_str(), O_WRONLY);
  }
}

void NamedPipe::close(ANamedPipe::Speaker speaker) {
  ::close(this->_fds[speaker]);
  ::close(this->_fds[speaker + 1]);
}

void NamedPipe::write(ANamedPipe::Speaker speaker) {
  ::write(this->_fds[speaker], this->_buffer.c_str(), this->_buffer.length());
}

void NamedPipe::read(ANamedPipe::Speaker speaker) {
  char buffer[SIZE_BUFFER + 1];
  int ret;

  ret = ::read(this->_fds[speaker + 1], buffer, SIZE_BUFFER);
  buffer[ret] = '\0';
  this->_buffer = buffer;
}
