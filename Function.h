#ifndef TREEMYSELF_FUNCTION_H
#define TREEMYSELF_FUNCTION_H

#include <iostream>
#include <fstream>
using namespace std;

struct node{
    string data;
    node *left , *right;
};
typedef node *pNode;

pNode makeTree( string );
int priority ( char );
void print( pNode );
int calc( pNode );
void printChoice();
void readFromKeyboard( string& );
void readFromFile( string& );
void writeToFile( string );
void freeMem( pNode );
void checkParentheses( string& );
#endif
