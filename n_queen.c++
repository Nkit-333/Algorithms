#include<iostream>
#include<math.h>
using namespace std;
int a[20];
int count=0;
int place(int pos)
{
    for(int i=1;i<pos;i++)
    {
        if(a[i]==a[pos]||abs(a[pos]-a[i])==abs(i-pos))
            return 0;
    }
    return 1;
}
void print( int n)
{
    int i,j;
 count++;
 printf("\n\nSolution #%d:\n",count);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(a[i]==j)
    cout<<"Q\t";
    
   else
    cout<<"*\t";
  }
    cout<<"\n";

}
}
void queen(int n)
{
    int k=1;
    a[k]=0;
    while(k!=0)
    {
            do
            {
                a[k]++;
            }while(a[k]<=n&&!place(k));
            if(a[k]<=n)
            {
                if(k==n)
                    print(n);
                else
                    {
                        k++;
                        a[k]=0;
                    }
            }
            else
                k--;

    }
}
int main()
{
        int n;
        cin>>n;
        queen(n);


}