#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
//TLE
     /*   int swap=0;
        for(int i=0; i<nums.size()-1; i++)
        {

            int temp=  nums[i+1];

            if(nums[i]==nums[i+1])
            {
                swap++;
               // cout<< nums[i]<< " ";

                for(int j=i+2; j<nums.size(); j++)
                {
                    nums[j-1]=nums[j];
                }

               // nums[nums.size()-1]=temp;
               nums.pop_back();

                if(temp==nums[i+1])
                {
                    i--;
                }
            }


        }


        return nums.size();
        */
        if(nums.size()==0)
            return 0;

        int i=0;
        for(int j=1; j<nums.size(); j++){

            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }

        return i+1;
    }
};

//[0,0,1,1,1,2,2,3,3,4]

int main()
{

    vector<int> vcc= {0,0,1,1,1,2,2,3,3,4};

    Solution obj;
    int k= obj.removeDuplicates(vcc);

    for(int i=0; i<k; i++)
    {
        cout<< vcc[i]<< " ";
    }
    cout<<endl;
    return 0;
}
