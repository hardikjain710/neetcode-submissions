class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(128,0);
        int n=s.length();
        int len=0;
        int l=0,r=0;
        while(r<n){
            if(freq[s[r]]==0){
                freq[s[r]]++;
            }
            else{
                while(freq[s[r]]!=0){
                    freq[s[l]]--;
                    l++;
                }
                freq[s[r]]++;
            }
            len=max(len,r-l+1);
            r++;

        }

        return len;
    }
};
