class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1; // mininum banana
        int right = 1000000000; // maximum banana

        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (canEatInTime(piles, mid, h))
            {
                cout << "mid : " << mid << "\n";
                right = mid  ;
            }
            else
                left = mid + 1;
        }
        return left;
    }

    bool canEatInTime(vector<int>& piles, int k, int h) {
        unsigned long long hour = 0;
        for (auto pile : piles) {
            hour = hour + (pile / k);
            if (pile % k != 0) hour++;
        }
        return hour <= h ? true : false ;
    }
};
