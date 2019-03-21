#include "InputManager.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  if (argc == 1) {

    InputManager inputManager;
    inputManager.ScanThroughFile(argv[0], argc);

  }
  else {

    InputManager inputManager;
    inputManager.ScanThroughFile(argv[1], argc);

  }

  return 0;

}
