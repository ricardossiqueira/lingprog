#if !defined(NOTFOUNDEXCEPTION_HPP)
#define NOTFOUNDEXCEPTION_HPP

#include <iostream>
#include <stdexcept>

class NotFoundException
{
public:
  virtual const char *what() const throw();
};

#endif // NOTFOUNDEXCEPTION_HPP
