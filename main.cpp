#include "SyntaxChecker.h"

int main(int argc, char const *argv[]) {
  string fCont, fName;
  char choice = '1';
  //Checks for command line parameter
  if( argc < 2){
    cout << "Invalid command line parameters" << endl;
    return 1;
  }

  fName = argv[1];
  while(choice != '2'){
    fCont = SyntaxChecker::readFile(fName);

    if(choice != '1'){
      //If choice input was not 'y' or 'n', inform user and skip to question again
      cout << "Please enter a valid input. \n" << endl;
    }else if(fCont == "N/A"){
      //If read file was unable to open
      cout << "Could not open " << fName<< endl;
    } else{
      SyntaxChecker::checkSyntax(fCont);
    }

    cout << "Would you like to analyze another file: \n\t1) Yes \n\t2) No\nChoice: ";
    cin >> choice;

    if(choice == '1'){
      cout << "Enter the name of the file you want to input from: " << endl;
      cin >> fName;
    }
  }
  return 0;
}
