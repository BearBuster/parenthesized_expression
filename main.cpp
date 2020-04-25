#include "Function.h"

int main() {
    string s = {"0123456789"};
    string str = {"la"};
    cout << str.size() << endl;
    cout << s << endl;
    s = s.substr(1 , s.size()-2);
    cout << s;
    return 0;
}
