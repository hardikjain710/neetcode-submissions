class Solution {
public:
int cnt=0;
void check(string &s,int i,int j,int n){
    while(i>=0 && j<n){
        if(s[i]==s[j]){
            cnt++;
            i--;
            j++;
        }
        else{
            break;
        }
    }
}
    int countSubstrings(string s) {
       int n=s.length();

       for(int i=0; i<n; i++){
        check(s,i,i,n);
        check(s,i,i+1,n);
       }
       return cnt;
    }
};
