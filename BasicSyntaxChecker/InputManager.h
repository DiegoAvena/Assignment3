#include <iostream>
#include <fstream>
#include "SyntaxMachine.h"

/*

-InputManager is responsible for
allowing the user to decide which file they want
to check and to feed each line in that file to SyntaxMachine
in order to syntax checking to occur

*/
class InputManager {

private:
  unsigned int currentLineNumber; //keeps track of the number of the line being read
  std::string nameOfSourceFileToCheck; //stores the name of the file that will be read

public:
  InputManager(); //default constructor
  ~InputManager(); //destuctor
  void ScanThroughFile(std::string fileName, int argumentCount); //reads each line in the file and feed it into SyntaxMachine to check syntax
  bool PromptUserIfTheyWishToReadAnotherFile(); //allows the user to decide if they want to check another file, and asks them to input the name of the file should they say yes

};
