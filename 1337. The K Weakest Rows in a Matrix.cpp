#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        vector<int> v;

        for(int i=0; i<mat.size(); i++)
        {
            int c=0;
            for(int j=0; j<mat[i].size(); j++)
            {
                if(mat[i][j]==1)
                {
                    c++;
                }
            }

            v.push_back(c);
        }

       multimap<int,int> m;


       for(int i=0; i<v.size(); i++){
        m.insert({v[i],i});
       }

       vector<int> temp;
       for( auto it=m.begin(); it!=m.end(); it++){
        if(k==0){
            break;
        }
        k--;
        temp.push_back(it->second);
       }

        return temp;
    }
};
int main()
{
    vector<vector<int>> v = {{1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
    };

    Solution obj;
    vector<int> x=obj.kWeakestRows(v,3);

    for(int i=0; i<x.size(); i++)
        cout<< x[i]<<endl;



    return 0;
}
