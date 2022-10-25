#include<iostream>
#include<vector>
using namespace std;
/*
    binary Search와 매개변수 탐색 알고리즘 문제
    매개변수 탐색이 뭔지 모름 그냥 바이너리로 풀어본다

    1. binary
        a 입력받은 랜선 길이 합(vector<int>v, v.size() == K)을 구한다
        b 만들어야 하는 랜선 갯수(N)로 나눈다 (몫 = m)
        c m은 주어진 랜선이 1개였다면 만들 수 있는 랜선 길이의 최대값이다.

        d (반복자는 i) i = 0 + m / 2
            각 랜선에 대해 i로 나눠서 갯수를 따로따로 구한다
                (N == 만들 수 있는 랜선 갯수) 이면 출력한다
                (만들 수 있는 랜선 갯수 > 합) i를 키운다
                (만들 수 있는 랜선 갯수 < 합) i를 줄인다
        

    2. 1번대로 방식으로 하니까 최대값이 안 나온다.
        

*/
inline int howManyGetLenCable(const vector<int> &v, int lenOfCable)
{ // d
    int numOfMakableCable = 0;
    for(int i = 0 ; i < v.size() ; i++)
    {
        numOfMakableCable = numOfMakableCable + ( v[i] / lenOfCable );
    }
    return numOfMakableCable;
}

int main(void)
{
    int toMakeLenCable, numOfLenCable;
    cin >> numOfLenCable >> toMakeLenCable;
    
    unsigned long sum = 0;
    int maximumCableLength;

    vector<int> v;
    for(int i = 0 ; i < numOfLenCable ; i++)
    {
        int t;
        cin >> t;       
        sum += t;
        v.push_back(t);
    }

    maximumCableLength = sum / toMakeLenCable;

    int startRange = 0; 
    int endRange = maximumCableLength;
    int i = maximumCableLength/2;
    while(1)
    {
        if( howManyGetLenCable(v,i) == toMakeLenCable )
        {
            break;
        }
        else if( howManyGetLenCable(v,i) < toMakeLenCable )
        {
            endRange = i;
            i = (startRange + endRange) / 2;
        }
        else if( howManyGetLenCable(v,i) > toMakeLenCable )
        {
            startRange = i;
            i = (startRange + endRange) / 2;
        }
    } // 최대값이 안 나온다

    int t = i;
 /*   while(1)
    {
        if( howManyGetLenCable(v,t) != toMakeLenCable )
        {
            i = t-1;
            break;
        }
        else
        {
            t = t + 1;
        }
    }*/

    cout << i;

//    int l; cin>>l;

    return 0;
}
