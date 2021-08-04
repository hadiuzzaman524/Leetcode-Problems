#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {

        string prefix=strs[0];

        for(int i=1; i<strs.size(); i++)
        {

            string temp="";
            for(int j=0; j<prefix.size(); j++)
            {
                if(prefix[j]==strs[i][j])
                {
                    temp+=prefix[j];
                }
                else
                    break;
            }
            prefix=temp;
        }

        return prefix;
    }
};


int main()
{
    Solution obj;
    vector<string> str;
    str.push_back("felower");
    str.push_back("tflow");
    str.push_back("wflatter");


    cout<<obj.longestCommonPrefix(str);

    return 0;
}
