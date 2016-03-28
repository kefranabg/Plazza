//
// ANamedPipe.cpp for ANamedPipe.cpp in /home/loeb_t/rendu/cpp_plazza
//
// Made by LOEB Thomas
// Login   <loeb_t@epitech.net>
//
// Started on  Fri Apr 25 13:31:16 2014 LOEB Thomas
// Last update Fri Apr 25 16:16:42 2014 LOEB Thomas
//

#include	<sstream>
#include	"ANamedPipe.hh"

ANamedPipe::ANamedPipe(unsigned int noKitchen) {
  std::ostringstream oss;

  oss << noKitchen;
  this->_filenames[0] = std::string(K_TO_R(oss.str()));
  this->_filenames[1] = std::string(R_TO_K(oss.str()));
}

ANamedPipe::~ANamedPipe() {}

std::string const & ANamedPipe::getFilename(unsigned int idx) const {
  return (this->_filenames[idx]);
}

int ANamedPipe::getFd(unsigned int idx) const {
  return (this->_fds[idx]);
}

std::string const & ANamedPipe::getBuffer() const {
  return (this->_buffer);
}

void ANamedPipe::setBuffer(std::string const & buffer) {
  this->_buffer = buffer;
}
