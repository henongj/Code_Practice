#include<iostream>
#include<map>
#include<string>
//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {

public:
    int lengthOfLongestSubstring(std::string str) {
        
        if (str.length() == 0)
            return 0;

        int left = 0;  int right = 0;

        std::map<char, int> m;
        int maximum = 1;
        int len = 0;

        for(left ; left < str.length() ; left++)
        {
            std::cout << "left : " << left << "\n";
            for (right = left; right < str.length(); right++)
            {

                if ( m.count( str[right]) == true )
                {
                    maximum = std::max(len, maximum);
                    len = 0;
                    m.clear();
                    break;
                }
                else
                {
                    len++;
                    m.insert(std::pair<char, int>(str[right], right));
                }

            }
                        
        }
        return maximum;
    }

};


int main(void)
{
    // 해당 문자가 

    // 중복이면, 
    // 1. left 이동 
    // 2. 테이블 전부 비우기 
    // 3. len 과 maximum중 큰 것 maximum으로
    // 4. len값을 0으로

    // 중복 아니면
    // 1. 테이블에 right 값 추가
    // 2. right 값 이동
    // 3. len + 1


    std::string example[3] = {"asjrgapa","dvjdabf","au" };
    Solution s = Solution();
    for (int i = 0; i < 3; i++)
    {
        std::cout << s.lengthOfLongestSubstring(example[i]) << "\n";
    }
	return 0;
}
