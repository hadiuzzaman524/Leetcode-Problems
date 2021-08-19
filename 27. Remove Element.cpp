#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {

        int j=0;
        for(int i=0; i<nums.size(); i++)
        {

           if(nums[i]!=val){
            nums[j]=nums[i];
            j++;
           }
        }
return j;
    }
};

int main()
{
    vector<int> val= {3,2,2,3};
    Solution obj;
    int k=obj.removeElement(val,3);

    for(int i=0; i<k; i++)
        cout<< val[i]<< " ";

    return 0;
}
