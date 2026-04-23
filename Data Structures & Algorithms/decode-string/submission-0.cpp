class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        int curNum = 0;
        string curString = "";
        for(char c : s){
            if(isdigit(c)){
                curNum = curNum * 10 + (c - '0');
            }else if(c == '['){
                numStack.push(curNum);
                strStack.push(curString);
                curNum = 0;
                curString = "";
            }else if(c == ']'){
                int repeat = numStack.top();
                numStack.pop();
                string prevString = strStack.top();
                strStack.pop();
                for(int i = 0; i < repeat; i++){
                    prevString += curString;
                }
                curString = prevString;
            }else{
                curString += c;
            }
        }
        return curString;
    }
};