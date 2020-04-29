#include "Function.h"

pNode makeTree(string s){
    pNode root;
    root = new node;
    string str1 , str2;
    int prt , minPrt = 100 , k , i  = 0 , net = 0 ;
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
    if(minPrt == 90){
        root->data = s;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    root->data[0] = s[k];
    root->data[1] = '\0';
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
        return stoi(root->data);
    int num1,num2;
    num1 = calc(root->left);
    num2 = calc(root->right);
    switch(root->data[0]){
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
    }
    return 0;
}
void printChoice(){
    cout << "1.Read expresion from keyboard" << endl;
    cout << "2.Read expresion from file" << endl;
    cout << "3.Write expresion to file" << endl;
    cout << "4.Make Tree" << endl;
    cout << "5.Calculate Tree" << endl;
    cout << "6.Free memory" << endl;
    cout << "7.End" << endl;
}
void readFromKeyboard( string &s ){
    cin >> s;
}
void readFromFile( string &s ){
    ifstream fp("/Users/guardi/CLionProjects/TreeMySelf/input-output.txt");
    if(fp.is_open()){
        getline(fp,s);
    } else{
        cout << "Error with openin file " << endl;
    }
    fp.close();
}
void writeToFile(string s){
    ofstream fp("/Users/guardi/CLionProjects/TreeMySelf/input-output.txt");
    fp << s;
    fp.close();
}
void freeMem( pNode root ){
    if( root->left == nullptr && root->right == nullptr) {
        delete (root);
        return;
    }
    freeMem(root->left);
    freeMem(root->right);
    delete ( root );
}
void checkParentheses(string &s){
    int i = 0 , Parenthe = 0;
    while(s[i] != '\0'){
        (s[i] == '(') ? Parenthe++ : (s[i] == ')') ? Parenthe-- : Parenthe;
        i++;
        if(Parenthe < 0)
            s = "";
    }
    if(Parenthe > 0 )
        s = "";
}

