class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;   

        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1])
                lo = mid + 1;
            else {
                if ( mid >= 1 && nums[mid] < nums[mid - 1])
                    hi = mid - 1;
                else
                    return mid;
            }
        }

        return lo;
    }
};
