#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
int distance[100];

bool check(int m,int n,int at ,int i,int j)
{
    vector< pair <int,int> > vect; 
    while(1)
    {
        if(arr[i][j]==0)
        {
            arr[i][j]=2;
            vect.push_back( make_pair(i,j));

        }
    }
    
}
bool place(int m,int n,int at)
{
	int distance[at];
     
    while(1)
    {
        if(at==0)
        break;
        if(check(m,n,at,0,0)==false)
        {
            cout<<"couldn't possible";
            return false;

        }
        else
            at--;
        

        return true;
    }
}

int main()
{

	int t,m,n,at;
	cin>>t;
	while(t>0)
	{
		cin>>m>>n>>at;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		}
		place(m,n,at);
		t--;

	}

}