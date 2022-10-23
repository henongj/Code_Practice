#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

// code 2022_10_23
// https://leetcode.com/problems/find-peak-element/


class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int middle = 0;

        if (nums.size() == 1) return 0; // 원소가 하나
        if(nums[0] > nums[1]) return 0; // 가장 왼쪽이 peak
        if (nums[nums.size() - 2] < nums[nums.size() - 1]) return nums.size()-1; // 가장 오른족이 peak


        while (left <= right) {
            middle = (right - left) / 2 + left;  
            std:: cout << "(left, middle, right) : ( " << left << ", " << middle << ", " << right << " )\n";
            std::cout << "(middle-1, middle, middle+1) : ( " << nums[middle-1] << ", " << nums[middle] << ", " << nums[middle + 1] << " )\n";
            //peak element 인 경우

            if( nums[middle - 1] < nums[middle] && nums[middle + 1] < nums[middle])
            {
                return middle;
            }
            // 증가 중인 경우
            else if (nums[middle] < nums[middle + 1])
            {
                left = middle + 1;
            }
            // 감소 중인 경우
            else if (nums[middle] < nums[middle - 1])
            {
                right = middle - 1;
            }
        }

        // 거짓리턴 (C++ 문법상 필요)
        return left;
    }
};


/* mainSpace.cpp

#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include"Find_Peak_Element_162.h"


int main(void)
{
	{
		using namespace std;
		vector<int> testCase = { 1,2,1,3,5,6,4 };
		vector<int> testCase2 = { 3,4,3,2,1 };
		
		Solution s = Solution();
		cout << s.findPeakElement(testCase2);
		
	}
	return 0;
}


*/
