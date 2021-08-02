#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x<0)
        {
            return false;
        }
        else
        {
            int result=0;
            int newvalue=x;

            while(newvalue!=0)
            {

                if(!((result>INT_MAX/10)||(result<INT_MIN/10)))
                {
                    result=result*10+newvalue%10;
                    newvalue=newvalue/10;
                }
                else
                {
                    return false;
                }

            }

            if(result==x)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        return false;
    }
};
int main()
{
    Solution obj;
    cout<<obj.isPalindrome(121);
    return 0;
}
