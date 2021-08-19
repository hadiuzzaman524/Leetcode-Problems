#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findLpsArray(string pattern, vector<int> &v)
    {

        int len=0;
        int i=1;


        while(i<pattern.size())
        {

            if(pattern[len]==pattern[i])
            {
                len++;
                v[i]=len;
                i++;
            }
            else
            {

                if(len==0)
                {
                    v[i]=0;
                    i++;
                }
                else
                {
                    len=v[len-1];
                }
            }
        }
    }
    int strStr(string str, string pattern)
    {

        if(str==""&&pattern=="")
            return 0;
        else if(pattern=="")
            return 0;
        int index=-1;

        int n=str.size();
        int m=pattern.size();
        vector<int> lps(m);
        findLpsArray(pattern,lps);

        int i=0, j=0;

        while(i<n)
        {
            if(str[i]==pattern[j])
            {
                i++ ;
                j++;
            }
            else
            {
                if(j==0)
                {
                    i++;
                }
                else
                {
                    j=lps[j-1];
                }
            }
            if(j==m)
            {
                index=i-j;
                break;
            }
        }

        return index;
    }
};

int main()
{
    string a="aaa";
    string b="a";
    Solution s;
    int x=s.strStr(a,b);
    cout<<x<<endl;
    return 0 ;
}
