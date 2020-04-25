#include "Function.h"

pNode makeTree(string data , int priority ){
    pNode Node = new node;
    //Node->data = data;
    //Node->left = nullptr;
    //Node->right = nullptr;

    int breakes = 0;
    int breakesCounter = 0 , i ;
    string str1;
    string str2;
    if (data[0] == '(' && data[data.size()-1] == ')') {
        for (i = 0; i < data.size(); i++) {
            (data[i] == '(')?breakesCounter++:(data[i] == ')')?breakesCounter--:breakesCounter;
            if( breakesCounter < 0 ) break;
            else{
                data = data.substr(1 , data.size()-2);
                priority = 1;
            }
        }
    }
    for( i = 0 ; i < data.size() , i++ ){
        (data[i] == '(')?breakesCounter++:(data[i] == ')')?breakesCounter--:breakesCounter;
        if(breakesCounter != 0) continue;


    return nullptr;
}

int priorityF( char ch ){
        switch (ch){
            case '+':case '-':return 1;
            case '*':case '/':return 2;
            }
            return 3;
        }