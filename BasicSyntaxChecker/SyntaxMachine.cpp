#include "SyntaxMachine.h"

using namespace std;

SyntaxMachine::SyntaxMachine():stackOfDelimiters() {}  //default constructor

SyntaxMachine::~SyntaxMachine() {}  //default constructor

//checks the syntax of the line fed into it, and if an error is found it throws an exception that contains the specifics of the problem in its message
void SyntaxMachine::checkSyntaxOfLine(string lineToCheckSyntaxOf, unsigned int lineNumber) throw(InvalidSyntaxException) {

  //for help on how to potentially use a stack to check for delimiter syntax, I used pages 204-206 of Data Structures and Algorithms book
  for (int i = 0; i < lineToCheckSyntaxOf.length(); i++) {

    if (lineToCheckSyntaxOf[i] == '{' || lineToCheckSyntaxOf[i] == '[' || lineToCheckSyntaxOf[i] == '(' ) {

      //only push opening delimiters and their line number onto the stacks
      stackOfDelimiters.push(lineToCheckSyntaxOf[i]);
      stackOfLinesWithDelimiterIssues.push(lineNumber);

    }
    else if (lineToCheckSyntaxOf[i] == '}' || lineToCheckSyntaxOf[i] == ']' || lineToCheckSyntaxOf[i] == ')'){

      //whenever a closing delimiter is reached make a comparison between it and the item at the top of the stack
      currentClosingDelimiterBeingCompared = lineToCheckSyntaxOf[i];

      if (stackOfDelimiters.empty()) {

        //there is nothing to compare with, there is invalid syntax as there is an unmatched closing delimiter
        throw(InvalidSyntaxException(determineProblemToReportWhileEndOfFileHasNotBeenReached()));

      }
      else if (((stackOfDelimiters.top() == '{') && (lineToCheckSyntaxOf[i] != '}')) || ((stackOfDelimiters.top() == '(') && (lineToCheckSyntaxOf[i] != ')')) || ((stackOfDelimiters.top() == '[') && (lineToCheckSyntaxOf[i] != ']'))) {

        //the closing delimiter is not the same as the opening at the top of the stack, so the syntax is wrong
        throw(InvalidSyntaxException(determineProblemToReportWhileEndOfFileHasNotBeenReached()));

      }
      else {

        //nothing is wrong with current delimiters, remove the opening delimiter at the top of the stack since it has been matched
        stackOfDelimiters.pop();
        stackOfLinesWithDelimiterIssues.pop();

      }

    }

  }

}

//determine if the end of the file is good based on if the stack is empty, and if it is not then it prints out a message with the specifics of the problem using determineProblemAtEndOfFile
bool SyntaxMachine::checkIfEndOfFileIsNotMissingAnything() {

  if (stackOfDelimiters.empty() == false) {

    //there are still some opening delimiters that are unmatched
    determineProblemAtEndOfFile();
    return false;

  }

  return true;

}

//determine if the end of the file is good based on if the stack is empty, and if it is not then it prints out a message with the specifics of the problem using determineProblemAtEndOfFile
void SyntaxMachine::determineProblemAtEndOfFile() {

  if (stackOfDelimiters.top() == '{') {

    cout<<"Error: End of file reached: Missing '}' in order to match with '{' at line "<<stackOfLinesWithDelimiterIssues.top()<<endl;

  }
  else if (stackOfDelimiters.top() == '[') {

    cout<<"Error: End of file reached: Missing ']' in order to match with '[' at line "<<stackOfLinesWithDelimiterIssues.top()<<endl;

  }
  else {

    cout<<"Error: End of file reached: Missing ')' in order to match with '(' at line "<<stackOfLinesWithDelimiterIssues.top()<<endl;

  }

}

//creates a message that contains the specifics of the mistake found with the syntax while the end of the file has not been reached. This message is the message that is set for the exception thrown
string SyntaxMachine::determineProblemToReportWhileEndOfFileHasNotBeenReached() {

  string itemFoundAtEnd = "";
  itemFoundAtEnd += currentClosingDelimiterBeingCompared; //converts the currentClosingDelimiterBeingCompared to a string so that it can be concatenated to the string returned here

  try {

    if (stackOfDelimiters.top() == '{') {

      return "Expected '}' to match with '{' at line "+to_string(stackOfLinesWithDelimiterIssues.top())+", but found '"+itemFoundAtEnd+"'";

    }
    else if (stackOfDelimiters.top() == '[') {

      return "Expected ']' to match with '[' at line "+to_string(stackOfLinesWithDelimiterIssues.top())+", but found '"+itemFoundAtEnd+"'";

    }
    else {

      return "Expected ')' to match with '(' at line "+to_string(stackOfLinesWithDelimiterIssues.top())+", but found '"+itemFoundAtEnd+"'";

    }

  }
  catch (StackEmptyException exception) {

    //if the stack is empty, then there is a closing delimiter that is unmatched, so something is missing before something

    if (currentClosingDelimiterBeingCompared == '}') {

      return "Missing '{' before '}'";

    }
    else if (currentClosingDelimiterBeingCompared == ')') {

      return "Missing '(' before ')'";

    }
    else {

      return "Missing '[' before ']'";

    }

  }

}
