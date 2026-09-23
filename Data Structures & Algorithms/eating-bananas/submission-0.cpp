class Solution {
   public:
    bool helper(vector<int>& piles, int mid, int h) {
        int hrs = 0;
        for (int i = 0; i < piles.size(); i++) {
            hrs += piles[i] / mid;
            if (piles[i] % mid != 0) {
                hrs++;
            }
        }
        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = *max_element(piles.begin(), piles.end());

        int l = 1;
        int r = maxi;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (helper(piles, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
