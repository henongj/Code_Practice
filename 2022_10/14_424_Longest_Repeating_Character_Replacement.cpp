class Solution {
public:
    /*
 
 반례
"BAAAB"
2
    */
    int val(string str, int k)
    {
        int left = 0; int right = 0;
        int strLen = str.length();
        int result = 0; int count = 0;

        vector<int> diffPosition = {}; int diffIndex = 0;
        
        while(left < strLen)
        { // AAABBAABBBB k = 2, output 8 , AAABCAABBBB k = 2, output 7 (A)
            // 글자와 앞 글자 비교
                // 같으면 right++
                // 다르면 right++  count
                    // 이게 k+1번째 중복이면 (result = right - left + 1)
                        // left = 첫 중복위치로
                        // 
                // 
            if(str[left] != str[right] ){
                //글자가 다르면
                count++;
                diffPosition.push_back(right);
                cout << "right index, diffpos " << right <<" "<<diffPosition[diffIndex]<<" ";
                cout << "count : " << count << " result : " << result << "\n";
                
                if( count > k )
                {// k+1번째 중복이면
                    //길이 저장, 첫 중복 위치, count 초기화
                    result = max(result , right-left );
                    left = diffPosition[ diffIndex ];
                    diffIndex++;
                    right = left;
                    count = 0;
                }
            }
            
            if(right == strLen - 1)
                break;
            right++;
        }
        
        return max( result , right-left+1 );
    }
    
    int characterReplacement(string str, int k) {
        
        string s = str;
        reverse(str.begin(),str.end());
        return max(val(str,k) , val(s,k));

        
    }
};
