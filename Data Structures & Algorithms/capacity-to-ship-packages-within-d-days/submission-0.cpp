class Solution {
public:
bool helper(vector<int>& weights,int mid, int days){
    int cnt=1;
    int sum=0;
    for(int i=0; i<weights.size(); i++){
        sum+=weights[i];
        if(sum>mid){
            cnt++;
            sum=weights[i];
        }
    }
    return cnt<=days;
} 
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        int maxi=0;
        for(int i=0; i<n; i++){
            sum+=weights[i];
            maxi=max(maxi,weights[i]);
        }

        int l=maxi;
        int r=sum;

        while(l<r){
            int mid=l+(r-l)/2;
            if(helper(weights,mid,days)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};