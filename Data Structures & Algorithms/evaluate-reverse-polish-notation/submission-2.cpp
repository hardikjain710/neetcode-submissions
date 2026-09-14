class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int n=tokens.size();
        stack<int>s;
        for(int i=0; i<n; i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i]!="*" && tokens[i]!="/"){
                s.push(stoi(tokens[i]));
            }
            else{
                int x=s.top();
                s.pop();
                int y=s.top();
                s.pop();
                if(tokens[i]=="+"){
                    s.push(x+y);
                }
                else if(tokens[i]=="-"){
                    s.push(y-x);
                }
                else if(tokens[i]=="*"){
                    s.push(x*y);
                }
                else{
                   s.push(y/x);

                }

            }

        }
        return s.top();
    }
};
