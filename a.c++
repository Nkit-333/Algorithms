#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<10;i++)
    {
        for(int j=1;j<4;j++)
        {
            cout<<"hello";
            if(j==2)
                break;
        }
        cout<<"\n";
    }
}