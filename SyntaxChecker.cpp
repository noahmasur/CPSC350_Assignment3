#include "SyntaxChecker.h"

//Reads in file
string SyntaxChecker::readFile(string fName){
  ifstream inFS;
  string fCont, out;

  inFS.open(fName);

//Testing if file was able to be opened
  if(!inFS.is_open()){
    return "N/A";
  }

  //Stores lines in variable seperated by new line charcter
  while(getline(inFS, fCont)){
    out += fCont + "\n";
  }

  inFS.close();
  return out;
}

//Checks the syntax of a string
bool SyntaxChecker::checkSyntax(string cont){
  GenStack<char> *charStack = new GenStack<char>();
  int line = 1;
  char top;
  bool quote = false;

  for(char c : cont){
    //Check if quote is starting or ending
    if(c == '\'' || c == '\"'){
      quote = !quote;
    }

    //if not in quote
    if(!quote){
      if(c == '\n'){
          line++; //If new line in file add to line count
      } else if(c == '{' || c == '(' || c == '['){
            charStack->push(c); //Push to stack if charcter is an opening delimeter
      }else if(c == '}' || c == ')' || c == ']'){
        top = charStack->peek();

        //If delimeter closes the delimeter from the top of the stack, remove the top
        if(isPair(c, top)){
          charStack->pop();
        }else{
          delete charStack;
          if(top == '\0'){
            //If extra delimeter
            cout << "Line" <<  to_string(line) << ": Extra delimeter " << c << " found" << endl;
            return true;
          } else{
            //If mismatching delimeter
            cout << "Line" << to_string(line) << ": Expected " << getPair(top) << " and found " << c << endl;
            return true;
          }
        }
      }
    }
  }

  if(charStack->isEmpty()){
    //If nothing left on stack syntax is correct
    delete charStack;
    cout <<"The delimiter syntax is correct" << endl;
    return false;
  } else{
    //If something left on stack, missing closing delimeter
    delete charStack;
    cout << "Reached end of file: Missing " << getPair(top) << endl;
    return true;
  }
}

//Return matching closing delimeter from opening delimeter
char SyntaxChecker::getPair(char c){
  switch(c){
    case '{':
      return '}';
    case '(':
      return ')';
    case '[':
      return ']';
  }
}

//Returns whether 2 characters are pairs
bool SyntaxChecker::isPair(char c, char top){
  return (c == getPair(top));
}
