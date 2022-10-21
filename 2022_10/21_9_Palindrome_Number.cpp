class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int j = num.length()-1;
        for(int i = 0 ; i < num.length()/2 ; i++)
        {
            if(num[i] != num[j])
                return false;
            j--;
        }
        return true;
    }
};
