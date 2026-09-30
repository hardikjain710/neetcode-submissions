class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        
        int len=0;
        int i=0,j=0;
        int t=k;
        vector<int>visited(26,0);
        while(j<n){

            visited[s[j]-'A']++;
            int maxi=*max_element(visited.begin(),visited.end());
            while(j-i+1 - maxi > k){
                visited[s[i]-'A']--;
                i++;
            }
            len=max(j-i+1,len);
            j++;

        }
        return len;
    }
};
