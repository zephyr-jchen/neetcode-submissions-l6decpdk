class Solution {
public:
    bool isValid(string s) {
        stack<char> stackS;
        for(char c : s){
            if(c == '('){stackS.push(')');}
            else if(c == '{'){stackS.push('}');}
            else if(c == '['){stackS.push(']');}
            else{
                if(stackS.empty() || c != stackS.top()){
                    return false;
                }
                stackS.pop();
            }
            
        }
        return stackS.empty();
    }
};
