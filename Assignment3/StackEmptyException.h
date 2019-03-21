#include "RunTimeException.h"

class StackEmptyException: public RunTimeException { 

public:
  StackEmptyException(); //default constructor
  StackEmptyException(std::string message); //custom constructor
  ~StackEmptyException(); //destructor

};
