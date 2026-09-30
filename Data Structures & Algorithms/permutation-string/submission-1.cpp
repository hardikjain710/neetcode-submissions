class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        vector<int> f(26, 0);

        int n = s1.length();
        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
        }
        int r = 0, l = 0;
        int m = s2.length();

        while (r < m) {
            if (!(freq[s2[r] - 'a'])) {
                r++;
                l = r;
                for (int i = 0; i < 26; i++) {
                    f[i] = 0;
                }
            } 
            else {

                f[s2[r] - 'a']++;
                if (freq == f) {
                    return true;
                }
                else if(freq[s2[r]-'a'] < f[s2[r]-'a']){
                    while(freq[s2[r]-'a'] < f[s2[r]-'a']){
                        f[s2[l]-'a']--;
                        l++;
                    }
                }
                r++;
            }
        }
        return false;
    }
};
