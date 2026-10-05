class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        stk.push(0);

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '('){
                stk.push(0);
            }
            else{
                int x = stk.top();
                stk.pop();

                if(x == 0){
                    stk.top() += 1;
                }
                else{
                    stk.top() += 2 * x;
                }
            }
        }

        return stk.top();
    }
};