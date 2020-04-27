#include "Function.h"

pNode makeTree(string s){
    pNode root;
    root = new node;
    string str1 , str2;
    int prt , minPrt = 100 , k , i  = 0 , net = 0 ;
    if( s.size() == 1 ){
        root->data = s[0];
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    if(s[0] == '(' && s[s.size()-1] == ')'){
        for(i = 1 ; i < s.size()-2 ; i++ ){
            if(s[i] == '(')
                net++;
            if(s[i] == ')')
                net--;
            if(net < 0)
                break;
        }
        if(net == 0)
            s = s.substr(1 , s.size()-2);
    }
    net = 0;
    for( i = 0 ; i < s.size() ; i++){
        if(net == 0 ) {
            prt = priority(s[i]);
            if (prt <= minPrt) {
                minPrt = prt;
                k = i;
            }
        }
        (s[i] == '(') ? net++ : (s[i] == ')') ? net-- : net;
    }
    root->data = s[k];
    str1 = s.substr(0 , k);
    str2 = s.substr(k+1 , s.size() - k - 1);
    root->left = makeTree(str1);
    root->right = makeTree(str2);
    return root;
}

int priority ( char ch){
    switch (ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 90;
}

void print( pNode root ){
    if( !root )
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
int calc(pNode root){
    if(!root->left)
        return root->data - '0';
    int num1,num2;
    num1 = calc(root->left);
    num2 = calc(root->right);
    switch(root->data){
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
    }
    return 0;
}