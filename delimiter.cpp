//Ben Bartol
//Assignment 3
//CPSC-350
//Rene German
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "delimiter.h"
#include "GenStack.h"
using namespace std;

delimiter::delimiter(){
  //constructor
}

delimiter::~delimiter(){
  //destructor
}

int delimiter::checkSyntax(string file){
  bool continued = true;
  GenStack<char> s(10);


  while(continued){
    string wholeCode;
    int lineNum = 1;

    ifstream inFS;
    inFS.open(file.c_str());

    while(getline(inFS, wholeCode)){
      for(int i = 0; i < wholeCode.size(); ++i){
        if((wholeCode[i] == '(')||(wholeCode[i] == ')')||(wholeCode[i] == '{')||(wholeCode[i] == '}')||(wholeCode[i] == '[')||(wholeCode[i] == ']')){

          if((s.peek() == '(')&&(wholeCode[i] == ')')){
            s.pop();
          }else if((s.peek() == '{')&&(wholeCode[i] == '}')){
            s.pop();
          }else if((s.peek() == '[')&&(wholeCode[i] == ']')){
            s.pop();
          }

          else if((s.peek() == '(')&&((wholeCode[i] == ']') || (wholeCode[i] = '}'))){
            cout << "Error in line " << lineNum << ": ')' expected and a " << wholeCode[i] << " was found" << endl;
            return 0;
          }
          else if((s.peek() == '[')&&((wholeCode[i] == ')') || (wholeCode[i] = '}'))){
            cout << "Error in line " << lineNum << ": ']' expected and a " << wholeCode[i] << " was found" << endl;
            return 0;
          }
          else if((s.peek() == '{')&&((wholeCode[i] == ']') || (wholeCode[i] = ')'))){
            cout << "Error in line " << lineNum << ": ')' expected and a " << wholeCode[i] << " was found" << endl;
            return 0;
          }
          else if((wholeCode[i] == '(')||(wholeCode[i] == '[')||(wholeCode[i] == '{')){
            s.push(wholeCode[i]);
          }
        }
      }
      ++lineNum;

    }

   if(s.isEmpty() == 0){
     cout << "Error: file ended, missing: " << s.peek() << endl;
     return 0;
   }else if(s.isEmpty() == 1){
     char another;
     cout << "Syntax check complete: No errors spotted \nCheck another file? (y/n)";
     cin >> another;

     if((another == 'Y')||(another == 'y')){
       cout << "What is the name of the next file?";
       cin >> file;
       continue;
     }else{
       continued = false;
     }
   }
 }
 return 0;
}
