#include <iostream>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {

        int result=0;
        int newvalue=x;

        while(newvalue!=0)
        {

         if(result>INT_MAX||result<INT_MIN){
            return 0;
         }else{
             result=result*10+newvalue%10;
            newvalue=newvalue/10;
         }

        }


        return result;
    }
};

int main()
{
    Solution solution;

    cout<<solution.reverse(-123456789);

    return 0;
}
