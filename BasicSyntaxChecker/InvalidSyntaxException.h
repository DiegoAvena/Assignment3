#include "RunTimeException.h"

/*

InvalidSyntaxException is an exception thrown
when delimeter syntax is incorrect

*/
class InvalidSyntaxException: public RunTimeException { //inherits from RunTimeException in order to use its getErrorMessage method

public:
  InvalidSyntaxException(); //constructor
  InvalidSyntaxException(std::string message); //custom constructor, allows user to define their own error message
  ~InvalidSyntaxException(); //destructor

};
