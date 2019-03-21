#include "InputManager.h"

using namespace std;

InputManager::InputManager() { //default constructor

}

InputManager::~InputManager() { //destuctor

}

//reads each line in the file and feed it into SyntaxMachine to check syntax
void InputManager::ScanThroughFile(string fileName, int argumentCount) {

  bool errorFound = false;

  if (argumentCount < 2) { //user did not enter the name of a file as a command line argument

    cout<<"I detected that you did not insert the name of a source file to check."<<endl;

    if (PromptUserIfTheyWishToReadAnotherFile() == false) {

      //user is done
      return;

    }

  }
  else {

    nameOfSourceFileToCheck = fileName;

  }

  while (true) {

    ifstream sourceCodeFileToCheckSyntaxOf(nameOfSourceFileToCheck);

    if (sourceCodeFileToCheckSyntaxOf.is_open()) {

      //file successfully opened

      SyntaxMachine syntaxMachine; //will check the line being fed into it from here for syntax mistakes
      string line; //the current line being read, will be fed into syntaxMachine
      currentLineNumber = 0;

      while (getline(sourceCodeFileToCheckSyntaxOf, line)) {

        //there are still lines to read:

        currentLineNumber++;

        /*

          -an exception is thrown whenever a syntax mistake is detected by syntaxMachine, and
          the message of this exception contains the specifics on that error

        */
        try {

          syntaxMachine.checkSyntaxOfLine(line, currentLineNumber);

        }
        catch (InvalidSyntaxException exception){

          //attempt to remove one more line, if there is no line to remove, then the if statement below will be true and the line read before this empty line was the last line of the file
          getline(sourceCodeFileToCheckSyntaxOf, line);

          if (sourceCodeFileToCheckSyntaxOf.eof()) { //for info on eof, I used: https://stackoverflow.com/questions/47572104/how-to-know-if-next-getline-is-eof-c?rq=1 and http://www.cplusplus.com/reference/istream/istream/getline/

            cout<<"Error: End of file reached: "<<exception.getErrorMessage()<<endl;

          }
          else {

            cout<<"Error: Line "<<currentLineNumber<<": "<<exception.getErrorMessage()<<endl;

          }

          errorFound = true; //tell program an error has been found, so that it can exit and allow the user to fix it
          break;

        }

      }

      sourceCodeFileToCheckSyntaxOf.close();

      if (errorFound) {

        break;

      }
      else if (syntaxMachine.checkIfEndOfFileIsNotMissingAnything() == false) {

        /*

        -If the end of the file is reached and there is
        still an opening delimeter in the stack of the Syntax Machine,
        the code from lines 40-84 will be unable to
        detect that something is missing
        since the expression in the while loop will evaluate
        to false in this case. This portion
        insures that the stack of the syntax machine is checked for emptiness,
        in which case everything is fine. If everything is not fine,
        the statement above prints out the specific
        details on the problem, and the program will exit.

        */
        break;

      }

      cout<<"Delimiter Syntax is correct."<<endl;

      if (PromptUserIfTheyWishToReadAnotherFile() == false) {

        //user is done
        break;

      }

    }
    else {

      cout<<"The source file you entered could not be found"<<endl;

      if (PromptUserIfTheyWishToReadAnotherFile() == false) {

        break;

      }

    }

  }

}

//allows the user to decide if they want to check another file, and asks them to input the name of the file should they say yes
bool InputManager::PromptUserIfTheyWishToReadAnotherFile() {

  char response;

  while (true) { //keep asking the user if they want to continue until they respond correctly

    cout<<"Would you like to insert the name of a source code file to check? Press y for yes or n for no."<<endl;
    cin>>response;
    if (tolower(response) == 'n' || tolower(response == 'y')) {

      break;

    }
    else {

      cout<<"Invalid response."<<endl;

    }

  }

  if (tolower(response) == 'n') {

    //tell program to exit
    return false;

  }
  else {

    //get the name of the file the user wants to check syntax of
    cout<<"Insert the name of a file to check the syntax of: "<<endl;
    cin>>nameOfSourceFileToCheck;
    return true; //tell program not to exit

  }

}
