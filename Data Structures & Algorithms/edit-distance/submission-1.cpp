#include<cstring>
class Solution {
   public:
   int memo[101][101];
    int solve(string& s1, string& s2, int i, int j) {
        if (i == s1.length()) {
            return s2.length() - j; 
        }
        if (j == s2.length()) {
            return s1.length() - i; 
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
       
        if (s1[i] == s2[j]) {
            return memo[i][j]=solve(s1, s2, i + 1, j + 1);
        }


       
           int x = solve(s1, s2, i + 1, j);
          int  y = solve(s1, s2, i + 1, j + 1);
          int   z = solve(s1, s2, i, j + 1);
    
         return memo[i][j] = 1+min(x, min(y, z));
        
    }
    int minDistance(string s1, string s2) { 
       
         memset(memo,-1,sizeof(memo));
         return solve(s1,s2,0,0);
       
        }
};
