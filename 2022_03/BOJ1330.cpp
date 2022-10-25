#include<iostream>
#include<string>
using namespace std;

string compareTwoInt(int a , int b)
{
    if(a > b)
        return ">";
    else if (a == b)
        return "==";
    else if(a < b)
        return "<";
}

int main(void)
{
    int a , b;
    cin >> a >> b;
    cout << compareTwoInt(a,b);
    return 0;
}
