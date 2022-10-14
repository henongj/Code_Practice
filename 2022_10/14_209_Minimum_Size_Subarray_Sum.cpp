class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int left = 0 ; int right = 0;        
        int sum = 0; int count = 0;
        int result = INT_MAX;
        while(right < nums.size() )
        {
            sum = sum + nums[right];
            count++;
            right++;
            while(sum >= s)
            {//값을 넘으면
                result = min(result,count);
                sum = sum - nums[left];
                left++; count--;
            }
        }
        return result;
    }
};
