class Solution {
   public:
    int n;
    bool checkPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }
        return true;
    }
    void backtrack(string s,int idx,vector<string>&curr,vector<vector<string>>&res){
        if(idx==n){
            res.push_back(curr);
        }
        for(int i=idx; i<n; i++){
            if(checkPalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                backtrack(s,i+1,curr,res);
                curr.pop_back();

            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> curr;
        vector<vector<string>> res;
        backtrack(s, 0, curr, res);
        return res;
    }
};
