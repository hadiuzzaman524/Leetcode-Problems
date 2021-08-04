#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string str)
    {
        stack<char> stk;

        for(int i=0; str[i]!='\0'; i++)
        {
            if(str[i]=='('||str[i]=='{'||str[i]=='[')
            {
                stk.push(str[i]);
            }
            else
            {
                if(stk.empty())
                    return false;
                char top=stk.top();
                if((top=='('&& str[i]==')')||(top=='{'&& str[i]=='}')||(top=='['&& str[i]==']'))
                {
                    stk.pop();
                }else{
                return false;
                }
            }
        }

        if(stk.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution ob;
    cout<<ob.isValid("([()])");

    return 0;
}
