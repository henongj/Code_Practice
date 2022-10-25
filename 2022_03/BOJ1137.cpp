#include<iostream>
#include<vector>
#include<string>

using namespace std;

int max(size_t a,size_t b)
{
    return a > b ? a : b;
}
int main(void)
{
    string s;
    int numOfAlphabet = 'Z' - 'A' + 1;
    int alphabetCounting[numOfAlphabet] = {}; // 각 알파벳이 몇 번 나왔는지 기록해줌
    int maximum = 0;

    cin >> s; int index;
    for(size_t i = 0 ; i<s.size() ; i++)
    { //알파벳 카운팅, 가장 많이 등장한 알파벳 횟수 캐치
        (s[i] >= 'a') ? index = s[i] - 'a' : index = s[i] - 'A';
        

        alphabetCounting[index] = alphabetCounting[index] + 1;
        maximum = max(maximum , alphabetCounting[index]);
    }


    int overlapped = 0; int maxNumIndex = 0;
    for(size_t i = 0 ; i < numOfAlphabet ; i++)
        {
            if(maximum == alphabetCounting[i])
            {
                overlapped = overlapped + 1;
                maxNumIndex = i;
            }
        } // 맥시멈이 되는 숫자와 그 인덱스를 찾는다

//출력한다
    if(overlapped >= 2)
        cout << "?";
    else {
            cout << char(maxNumIndex + 'A');
        }

    return 0;
}
