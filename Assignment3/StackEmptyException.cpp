#include "StackEmptyException.h"
using namespace std;

//default constructor, invokes the default constructor of RunTimeException
StackEmptyException::StackEmptyException():RunTimeException(){}

//custom constructor, invokes the custom constructor of RunTimeException to set the error message to a custom one
StackEmptyException::StackEmptyException(string message):RunTimeException(message){}

//destructor
StackEmptyException::~StackEmptyException(){

}
