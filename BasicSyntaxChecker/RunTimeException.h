#ifndef RUN_TIME_EXCEPTION
#define RUN_TIME_EXCEPTION
//Guards are used since this file will be used by multiple other files. This prevents a multiple definition error from occuring

#include <iostream>

class RunTimeException {

private:
  std::string err; //stores the message containing the details on this error being thrown

public:
  RunTimeException(); //default constructor, sets err to default message
  RunTimeException(std::string customErrorMessage); //custom constructor, sets err to custom message
  ~RunTimeException(); //destructor
  std::string& getErrorMessage(); //returns a reference to the error message that has been set

};

#endif
