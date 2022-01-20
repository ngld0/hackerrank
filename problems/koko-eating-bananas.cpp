class Solution {
public:
   
    bool check(int k, int h, vector<int> &piles){
      int count = 0;
      for(auto it : piles){
        count += it / k;
        if(it % k != 0) count++;
      }
      if(count <= h) return true;
      return false;
    }
  
    int minEatingSpeed(vector<int>& piles, int h) {
        int beg = 1, end = INT_MIN, ans;
        for(auto it : piles) if(it > end) end = it;

        while(beg <= end){
            int mid = beg + (end - beg)/2;
            if(check(mid, h, piles)) {
                ans = mid;
                end = mid - 1;
            }
            else beg = mid + 1;
        }
        return ans;
    }
};
