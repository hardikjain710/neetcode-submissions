class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0; 
        int j=n-1;
        while(i<j){
            int s=numbers[i]+numbers[j];
            if(s>target){
                j--;
            }
            else if(s<target){
                i++;
            }
            else{

            return {i+1,j+1};
            }
        }
        return {-1,-1};
        
    }
};
