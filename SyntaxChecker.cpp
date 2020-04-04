#include "SyntaxChecker.h"

string SyntaxChecker::readFile(string fName){
  ifstream inFS;
  string fCont, out;

  inFS.open(fName);

//Testing if file was able to be opened
  if(!inFS.is_open()){
    return "N/A";
  }

  while(getline(inFS, fCont)){
    out += fCont + "\n";
  }

  inFS.close();
  return out;
}

void SyntaxChecker::checkSyntax(string cont){
  GenStack<char> *charStack = new GenStack<char>();
  int line = 1;
  char top;

  for(char c : cont){
    if(c == '\n'){
        line++; //If new line in file add to line count
    } else if(c == '{' || c == '(' || c == '['){
          charStack->push(c); //Push to stack if charcter is an opening delimeter
    }else if(c == '}' || c == ')' || c == ']'){
      top = charStack->peek();
      if(isPair(c, top)){
        charStack->pop();
      }else{
        delete charStack;
        if(top == '\0'){
          cout << "Line" <<  to_string(line) << ": Extra delimeter " << c << " found" << endl;
          return;
        } else{
          cout << "Line" << to_string(line) << ": Expected " << getPair(top) << " and found " << c << endl;
          return;
        }
      }
    }
  }

  if(charStack->isEmpty()){
    delete charStack;

    cout <<"The delimiter syntax is correct" << endl;
  } else{
    delete charStack;
    cout << "Reached end of file: Missing " << getPair(top) << endl;
  }
}

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

bool SyntaxChecker::isPair(char c, char top){
  return (c == getPair(top));
}
