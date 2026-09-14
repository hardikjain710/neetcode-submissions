class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        int i = 0;
        while (i < n && asteroids[i] < 0) {
            s.push(asteroids[i]);
            i++;
        }
      

        for (int j = i; j < n; j++) {
            
            int x=asteroids[j];
            bool flag=true;

            while(!s.empty() && x<0 && s.top()>0){
                int y=s.top();
                int z=abs(x);
                if(z>y){
                    s.pop();
                }
                else if(z==y){
                    s.pop();
                    flag=false;
                    break;
                }
                else {
                
                    flag = false;
                    break; 
                }
            }
            if (flag) {
                s.push(x);
            }
        }
        vector<int> ans;
        while (!s.empty()) {
            int x = s.top();
            s.pop();
            ans.push_back(x);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};