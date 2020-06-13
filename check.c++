#include<iostream>
using namespace std;
bool game(int n)
{
    if(n==2)
        return true;
    else 
    return false;
}
bool new2(int n)
{
    if(game(n)==true)
    {
        
           
            cout<<"hello";
            return false;
        
    }
     new2(n+1);


}
int main()
{
    int n=1;
    new2(n);
}