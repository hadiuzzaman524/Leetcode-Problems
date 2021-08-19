#include <bits/stdc++.h>
using namespace std;

void lps(string p, vector<int> &ar)
{
    int n=p.size();
    int l=0;
    int i=1;
    while(i<n)
    {
        if(p[l]==p[i])
        {
            l++;
            ar[i]=l;
            i++;
        }
        else
        {
            if(l!=0)
            {
                l=ar[l-1];

            }
            else
            {
                ar[i]=0;
                i++;
            }
        }

    }
}

int kmp(string str, string pattern)
{

    int n=str.size();
    int m=pattern.size();
    vector<int> ar(m);
    lps(pattern,ar);

    /*  for(int i=0; i<ar.size(); i++)
          cout<<ar[i]<< " ";
      cout<<endl;*/


    int i=0,j=0;

    while(i<n){

        if(str[i]==pattern[j]){
            i++;
            j++;
        }
        else{
            if(j==0)
                i++;
            else
                j=ar[j-1];
        }
        if(j==m)
        {
            cout<< i-m<<endl;
            j=ar[j-1];
        }
    }

    return 0;
};

int main()
{


    string pattern="aabaaac";
    string str="aabcdeaabaaacxy";




    int x=kmp(str,pattern);
    cout<<x<<endl;
    return 0;
}
