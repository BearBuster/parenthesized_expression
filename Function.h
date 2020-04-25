#ifndef TREEMYSELF_FUNCTION_H
#define TREEMYSELF_FUNCTION_H

#include <iostream>
using namespace std;

struct node{
    string data;
    node *left , *right;
};
typedef node *pNode;

pNode makeTree( string , int );
int priorityF( string );

#endif
