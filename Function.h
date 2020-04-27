#ifndef TREEMYSELF_FUNCTION_H
#define TREEMYSELF_FUNCTION_H

#include <iostream>
using namespace std;

struct node{
    char data;
    node *left , *right;
};
typedef node *pNode;

pNode makeTree( string );
int priority ( char );
void print( pNode );
int calc( pNode );

#endif
