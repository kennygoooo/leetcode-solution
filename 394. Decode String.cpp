// 394. Decode String

// Stack   Vector
// push()  push_back()
// pop()   pop_back() 
// top()   back() 

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        string currStr = "";
        int currNum = 0;

        for (int i = 0; i < s.size(); i++){
            char c = s[i];

            if (isdigit(c)){
                currNum = currNum * 10 + (c - '0');
            } else if (c == '['){
                countStack.push(currNum);
                strStack.push(currStr);
                currNum = 0;
                currStr = "";

            } else if (c == ']'){
                int repeat = countStack.top();
                countStack.pop();

                string prev = strStack.top();
                strStack.pop();
                string temp = "";
                for (int i = 0; i < repeat; i++) temp += currStr;
                currStr = prev + temp;
            } else {
                currStr.push_back(c);
            }
        }
        return currStr;
    }
};