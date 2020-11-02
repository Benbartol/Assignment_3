//Ben Bartol
//Assignment 3
//CPSC-350
//Rene German
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "GenStack.h"
#include "delimiter.h"
using namespace std;

int main(int argc, char** argv){
  delimiter d;

  if(argc < 2){
    cout << "Error: Please enter correct file name" << endl;
  }else if(argc >= 2){
    string file = argv[1];
    d.checkSyntax(file);
  }
  return 0;
}
