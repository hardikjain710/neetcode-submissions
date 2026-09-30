class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<pair<int ,int>>res(n);

        int s=0;
        for(int i=0; i<n; i++){
            res[i]={abs(x-arr[i]),arr[i]};
        }
        sort(res.begin(),res.end());
        vector<int>ans;
        for(int i=0; i<k; i++){
            ans.push_back(res[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};