#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(const string& arr) {
    stack<char> s;
    int totalSize = size(arr);

    for (int i = 0; i < totalSize;i++) {
        char c = static_cast<char>(arr[i]);
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty())  { // checking stack empty or not
                return false; // closing not match
            }
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false; // poping out if not match closing brackets
            }
        }
    }

    return s.empty(); // empty / all brackets are true
}

int main() {
    string arr1 = "{[{}{}]}[()]";
    string arr2 = "{{}{}]";
    string arr3 = "[]{}()";
    string arr4 = "{()}[)";
    string arr5 = "{(})";

    cout << "\n\n\t\t\t \"1\" means balanced & \"0\" means not balanced \n\n\n";

    cout << arr1 << " : " << isBalanced(arr1) << endl;
    cout << arr2 << " : " << isBalanced(arr2) << endl;
    cout << arr3 << " : " << isBalanced(arr3) << endl;
    cout << arr4 << " : " << isBalanced(arr4) << endl;
    cout << arr5 << " : " << isBalanced(arr5) << endl;

    return 0;
}
