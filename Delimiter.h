//Ben Bartol
//Assignment 3
//CPSC-350
//Rene German
#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

class delimiter{
  private:

  public:
    delimiter();
    ~delimiter();

    int checkSyntax(string file);
};
