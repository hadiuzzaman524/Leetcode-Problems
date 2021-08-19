#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheDistanceValue(vector& arr1, vector& arr2, int d)
    {
        int count=0;
        sort(arr2.begin(),arr2.end());
        for(int i=0; i< arr1.size(); i++)
        {
            int key=arr1[i];
            int l=0,h=arr2.size()-1;
            bool k=true;
            while(l<=h)
            {
                int m=l+(h-l)/2;
                if(abs(key-arr2[m]) <=d)
                {
                    k=false;
                    break;
                }
                else if(arr2[m]>key)
                {
                    h=m-1;
                }
                else
                {
                    l=m+1;
                }
            }
            if(k)
                count++;
        }
        return count;
    }
};
