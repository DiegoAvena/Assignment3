#include "InvalidSyntaxException.h"

using namespace std;

//default constructor, invokes the default constructor of RunTimeException
InvalidSyntaxException::InvalidSyntaxException():RunTimeException() {}

//custom constructor, invokes the custom constructor of RunTimeException to set a error custom message
InvalidSyntaxException::InvalidSyntaxException(string message):RunTimeException(message){}

//destructor
InvalidSyntaxException::~InvalidSyntaxException(){

};
