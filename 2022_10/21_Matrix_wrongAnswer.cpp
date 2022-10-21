
/*
https://leetcode.com/explore/learn/card/recursion-ii/470/divide-and-conquer/2872/

*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        auto xpos = make_pair<int, int>(1, matrix.size());
        auto ypos = make_pair<int,int>(1, matrix[0].size());

        while ( 1 )
        {

            int x_mid = (xpos.first + xpos.second) / 2; 
            int y_mid = (ypos.first + ypos.second) / 2;
            for (auto x : matrix[y_mid])
            { // 가로
                if ( x == target)
                    return true;
                else if ( x > target)
                    break;
            }
            for (int y = 0; y < ypos.second; y++)
            { // 세로
                if (matrix[y][x_mid] == target)
                    return true;
                else if (matrix[y][x_mid] > target)
                    break;
            }

            if (matrix[y_mid][x_mid] < target)
            {
                xpos.first = x_mid + 1;
                ypos.first = y_mid + 1; // 0 1 target 1
            }
            else if(matrix[y_mid][x_mid] == target)
            else
            {
                xpos.second = x_mid;
                ypos.second = x_mid;
            }          
            if(xpos.first >= xpos.second && ypos.first >= ypos.second)
                break;

        }

        return false;
    }
};
