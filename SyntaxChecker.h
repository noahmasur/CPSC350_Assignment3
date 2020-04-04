#include "GenStack.h"
#include <fstream>
#include <typeinfo>

class SyntaxChecker{
  public:
    static string readFile(string fName);
    static bool checkSyntax(string cont);

  private:
    SyntaxChecker(); //Static class so never instantiated

    //Functions only referenced within class
    static char getPair(char c);
    static bool isPair(char c, char top);
};
