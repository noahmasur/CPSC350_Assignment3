#include "GenStack.h"
#include <fstream>
#include <typeinfo>

class SyntaxChecker{
  public:
    static string readFile(string fName);
    static void checkSyntax(string cont);

  private:
    SyntaxChecker();
    static char getPair(char c);
    static bool isPair(char c, char top);
};
