#include "RunTimeException.h"
using namespace std;

//default constructor, sets err to default message
RunTimeException::RunTimeException() {

  err = "Runtime exception";

}

//custom constructor, sets err to custom message
RunTimeException::RunTimeException(string customErrorMessage) {

  err = customErrorMessage;

}

//destructor
RunTimeException::~RunTimeException() {

}

//returns a reference to the error message that has been set
string& RunTimeException::getErrorMessage() {

  return err;

}
