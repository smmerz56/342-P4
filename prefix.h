
#ifndef PREFIX_H
#define PREFIX_H
#include <iostream>
#include <fstream>
using namespace std;

//-----------------------------------------------------------------------------
// ADT Prefix: a mathmatical function whose operators come before the operands
//
// Implementation and assumptions:
//    - The function evaluatePrefixHelper is limited to evaluating functions  
//      with +, -, *, / as the operators.
//    - Operands must be a single digit.
//    - Both prefix and postfix are implemented as char arrays.
//    - The functions are read in from a file and stored in an array.
//    - The functions have to be formatted in the file correctly.
//    - The postfix expression is stored in a separate array from its prefix
//      form.
//    - Im assuming you are ok with me keeping some of your comments in
//      prefix.cpp so I can reference them in the future if need be.
//-----------------------------------------------------------------------------

int const MAXSIZE = 100;

class Prefix {
    friend ostream& operator<<(ostream&, const Prefix&);

public:
    Prefix(); // default constructor
    void setPrefix(ifstream& infile); // reads file and stores in array
    int evaluatePrefix() const; // uses helper function to evaluate
    void outputAsPostfix(ostream&) const; // displays the postfix

private:
    char expr[MAXSIZE+1]; // the array for the prefix expression
    int evaluatePrefixHelper(int&) const; // evaluates and returns expression
    void toPostfix(int&, char [], int&) const; //converts from pre to postfix 
};                                                                 

#endif