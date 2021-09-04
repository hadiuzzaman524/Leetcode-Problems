#include <bits/stdc++.h>
using namespace std;

int catalon(int x){

    if(x<=1)
    return 1;

    int result=0;
    for(int i=0; i<x; i++)
       result+= catalon(i)* catalon(x-i-1);

    return result;
}

int main()
{
    cout<< catalon(3);

    return 0;
}
