#include <iostream>

using namespace std;



int main()
{

    char list1[]= {"House A", "House B", "House C" };
    int list2[]= {1000, 1750, 1500};

    int c=0;

    for(int x: list2)
    {
        c++;
    }

    // Apply Bubble Sort Algorithm
    for(int i=0; i<c; i++)
    {

        for(int j=0; j<c-1-i; j++)
        {

            if(list2[j]>list2[j+1])
            {
                int temp=list2[j];
                string name=list1[j];

                list2[j]=list2[j+1];
                list1[j]=list1[j+1];

                list2[j+1]=temp;
                list1[j+1]=name;
            }

        }
    }
    for(int i=0; i<c; i++)
    {
        cout<< list1[i]<< ", ";
    }
    cout<<endl;
    return 0;
}
