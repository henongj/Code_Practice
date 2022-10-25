#include<iostream>
#include<string>
using namespace std;

/*
대상 숫자는 10,000 이하

1. 모든 숫자를 순차적으로 탐색 (무한루프)
    - 문자열로 변환
        6의 갯수 카운트
    - 3개가 넘어가면 
        카운트
    - N값과 동일하면 
        해당 수 출력
        break
2. 1번은 오답나옴 6 갯수가 아니라 모여서 666이여야 함.
        - 3개가 넘어가면 -> 666이 있으면
            카운트
*/

inline bool isThere666(string s)
{
    for(int i = 0 ; i < s.size() - 2 ; i++)
    {
        if(s[i] == '6' && s[i+1] == '6' && s[i+2] == '6')
            return true;
    }
    return false;
}

/* inline bool isThere666(string s)
{ // find 함수 사용 방식. 조금 더 
    return s.find("666") != string::npos ? true : false;
} */

int main(void)
{
    int N;
    cin >> N;

    int counter = 0;

    for(int i = 666 ; ; i++)
    {
        string s = to_string(i);

        if( isThere666(s) )
            counter++;

        if( counter == N )
        {
            cout << i;
            break;
        }
    }

    cin >> N;

    return 0;
}
