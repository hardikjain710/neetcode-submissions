#include <cstring>
class Solution {
int memo[101][101];
public:
bool solver(string& s1, string& s2, string& s3,int i,int j,int k){
    
    if(k==s3.length()){
        return true;
    }
    bool flag=false;
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    if(i<s1.length() && s1[i]==s3[k]){
         flag=flag || solver(s1,s2,s3,i+1,j,k+1);
    }
    
    if(j<s2.length() && s2[j]==s3[k]){
        flag=flag|| solver(s1,s2,s3,i,j+1,k+1);
    }
    return memo[i][j]=flag;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length()+s2.length()){
            return false;
        }
        memset(memo, -1, sizeof(memo));

       return solver(s1,s2,s3,0,0,0);
        
    }
};
