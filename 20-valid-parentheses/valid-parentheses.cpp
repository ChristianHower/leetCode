#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        if (s.length() <= 1){
            cout << "this is the issue";
            return false;
        }

        // EMPTY stack definition
        stack<char> runStack = {};

        // Map definition 
        map<char, char> parMap;

        // Adding keys and vals to map
        parMap['('] = ')';
        parMap['['] = ']';
        parMap['{'] = '}';

        for (int i = 0; i < s.length(); i++){

            for (const auto& pair : parMap){
                if (pair.first == s[i]){
                    runStack.push(s[i]);
                    break;
                }
                else if (pair.second == s[i]){
                    if (runStack.size() < 1){
                        return false;
                    }
                    else if (runStack.top() != pair.first){
                        cout << "option this one";
                        return false;
                    }
                    else {
                        runStack.pop();
                    }
                }
                
            }
            
        }
        if (runStack.size() > 0){
            cout << "kitty cat";
            return false;
        }
        return true;
    }
};