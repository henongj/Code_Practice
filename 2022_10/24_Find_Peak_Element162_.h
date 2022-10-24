class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;   
        
        if(nums.size() == 2)
        {
            return nums[0] > nums[1] ? 0 : 1;
        }            

        while (lo < hi) { // 오르막
            mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1])
                lo = mid + 1;
            else { // 내리막 
                hi = mid;
            }
        }

        return lo;
    }
};

/*
hi = mid; => 정답 후보군은 2개
hi = mid - 1 => 정답 후보군 1개

hi = mid; => 리턴 없이 정답 후보를 좁혀서 2개가 남음 => 후처리로 정답 특정
hi = mid - 1 => 정답 조건을 특정할 수 있음 => 후처리 X

*/
