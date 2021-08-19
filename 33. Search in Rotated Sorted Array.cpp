#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {

        int low=0;
        int high=nums.size()-1;
        int start;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(nums[mid]>nums[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }

        start=low;
        low=0;
        high=nums.size()-1;

        if(target>=nums[start]&& target<=nums[high])
        {
            low=start;
        }
        else
        {
            high=start;
        }

        while(low<=high){
            int midpoint=low+(high-low)/2;

            if(nums[midpoint]==target){
                return midpoint;
            }
            else if(target>nums[midpoint]){
                low=midpoint+1;
            }
            else{
                high=midpoint-1;
            }
        }
        return -1;
    }
};

int main()
{

    Solution obj;
    vector<int> v= {1,3,4};
    cout<< obj.search(v,5);
    return 0;
}
