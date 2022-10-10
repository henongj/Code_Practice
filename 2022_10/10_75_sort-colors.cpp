//https://leetcode.com/problems/sort-colors/submissions/

class Solution {
public:
    void swap(int& a, int& b)
    {
        int c = a;
        a = b;
        b = c;
    }
    void sortColors(vector<int>& nums) {
        int left = 0; int right = nums.size()-1; int idx = 0;
        
        while(idx <= right){
            
            if( nums[idx] == 2 )
            {
                swap(nums[idx] , nums[right]);
                right--;
            }
            else if( nums[idx] == 0)
            {
                swap(nums[idx] , nums[left]);
                idx++; left++;
            }
            else
            {
                idx++;
            }
        }
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(i == 0)
                cout << "[";
            
            cout<<nums[i];
            
            if( i != nums.size()-1)
                cout<<",";
            else{
                cout <<"]";
            }                
        }
        
    }
};
