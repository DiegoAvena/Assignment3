#include <iostream>
#include "GenStack.h"
#include "InvalidSyntaxException.h"

/*

SyntaxMachine is responsible for checking the line fed
into it by the file input manager for syntax mistakes, and if there
are syntax mistakes, it will determine the specifics of the mistake.

*/
class SyntaxMachine {

public:
  void checkSyntaxOfLine(std::string lineToCheckSyntaxOf, unsigned int lineNumber) throw(InvalidSyntaxException); //checks the syntax of the line fed into it, and if an error is found it throws an exception that contains the specifics of the problem in its message
  SyntaxMachine(); //default constructor
  ~SyntaxMachine(); //destructor
  bool checkIfEndOfFileIsNotMissingAnything(); //determine if the end of the file is good based on if the stack is empty, and if it is not then it prints out a message with the specifics of the problem using determineProblemAtEndOfFile

private:
  GenStack<char> stackOfDelimiters; //stores all of the opening delimiters in the file, such as (, {, and [
  GenStack<int> stackOfLinesWithDelimiterIssues; //stores the line number that each opening delimiter (, {, [ was read from. Allows a more accurate telling to the user of where the source of the error may be.
  char currentClosingDelimiterBeingCompared; //keeps track of the current closing delimiter being compared to, such as }, ), or ]
  void determineProblemAtEndOfFile(); //prints out the specifics of the problem found with the syntax when the end of the file has been reached
  std::string determineProblemToReportWhileEndOfFileHasNotBeenReached(); //creates a message that contains the specifics of the mistake found with the syntax while the end of the file has not been reached. This message is the message that is set for the exception thrown

};
