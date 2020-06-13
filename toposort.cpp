#include<iostream>
#include <stack> 
using namespace std;
int vertArr[20][20]; //the adjacency matrix initially 0
int arr [10];
int count = 0;
stack<int> mystack;
void displayMatrix(int v) {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}
void add_edge(int u, int v) {       //function to add edge into the matrix
   vertArr[u][v] = 1;
}
void TOPutil(int i, bool visited[],int v)
{
    visited[i]=true;
    for(int j=0;j<v;j++)
    {
        if(vertArr[i][j]==1 && visited[j]==false )
        {
            TOPutil(j,visited,v);
        }
    }
    mystack.push(i);
}
void print()
{
    while(mystack.empty()==false)
    {
            cout<<mystack.top()<<" ";
            mystack.pop();
    }
}
void TOP(int v)
{
        bool *visited=new bool[v];
        for(int i=0;i<v;i++)
            visited[i]=false;
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
                TOPutil(i,visited,v);
        }
        print();
}
int main()
{

    int v,e,src,des;
   cin>>v>>e;
   for(int i=0;i<e;i++)
   {    
       cin>>src>>des;
       add_edge(src,des);
   }
   //displayMatrix(v);
   TOP(v);
   
   return 0;
}