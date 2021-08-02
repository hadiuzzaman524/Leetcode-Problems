#include <iostream>
#include <map>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {

        map<char,int> table;
        table.insert(pair<char,int>('I',1));
        table.insert(pair<char,int>('V',5));
        table.insert(pair<char,int>('X',10));
        table.insert(pair<char,int>('L',50));
        table.insert(pair<char,int>('C',100));
        table.insert(pair<char,int>('D',500));
        table.insert(pair<char,int>('M',1000));

        int value=0;
        for(int i=0; s[i]!='\0'; i++)
        {

            if(table[s[i]]<table[s[i+1]])
            {
                value+=table[s[i+1]]- table[s[i]];
                i++;
            }
            else
            {
                value+= table[s[i]];
            }

        }
        table.clear();
        return value;
    }
};

int main()
{
    Solution s;
    cout<<s.romanToInt("LVIII");

    return 0;
}
