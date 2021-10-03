#if !defined(ALREADYEXISTSEXCEPTION_HPP)
#define ALREADYEXISTSEXCEPTION_HPP

#include <iostream>
#include <stdexcept>

class AlreadyExistsException
{
public:
  virtual const char *what() const throw();
};

#endif // ALREADYEXISTSEXCEPTION_HPP
