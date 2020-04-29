#include "Function.h"

int main() {
    int result , choice = 0;
    pNode Tree = nullptr;
    string s = {""};
    printChoice();
    while(choice != 7){
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Enter your expression : ";
                readFromKeyboard(s);
                checkParentheses(s);
                if(s.empty())
                    cout << "Invalid expression" << endl;
                break;
            case 2:
                readFromFile(s);
                cout << "Your expression : "<< s << endl;
                checkParentheses(s);
                if(s.empty())
                    cout << "Invalid expression" << endl;
                break;
            case 3:
                writeToFile(s);
            case 4:
                if(s.size() != 0) {
                    Tree = makeTree(s);
                }else
                    cout << "At first enter expression" << endl;
                break;
            case 5:
                if(Tree) {
                    result = calc(Tree);
                    cout << s << " = " << result << endl;
                } else
                    cout << "At first enter expression" << endl;
                break;
            case 6:
                freeMem(Tree);
                break;
            case 7:
                break;
        }
    }
    return 0;
}
