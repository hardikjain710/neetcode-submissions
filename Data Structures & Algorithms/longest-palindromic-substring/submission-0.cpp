class Solution {
public:
bool check(string &s,int i ,int j){
    while(i<=j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            return false;

        }
    }
    return true;
}
    string longestPalindrome(string s) {

        int n=s.length();
        int len=0;
        int sp=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(check(s,i,j)){
                    if(j-i+1>len){
                        len=j-i+1;
                        sp=i;
                    }

                }
            }
        }
        return s.substr(sp,len);
        
    }
};
