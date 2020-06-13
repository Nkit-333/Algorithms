#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
int vertArr[20][20]; //the adjacency matrix initially 0
int arr [10];
int count = 0;
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
   vertArr[v][u] = 1;
}
bool issafe(int k,int v)
{
   if(vertArr[arr[k-1]][v]==0)
    return false;
   for(int i=0;i<k;i++)
    {
        if(arr[i]==v)
            return false;
    }
    return true;
}
bool hamiutil(int k,int v)
{
    if(k==v)
    {
      if(vertArr[arr[k-1]][arr[0]]==1)
        return true;
      else
      return false;
    }

        for(int i=1;i<v;i++)
        {
        if(issafe(k,i))
        {
            arr[k]=v;
            if(hamiutil(k+1,v)==true)
                return true;
            arr[k]=-1;
        }
        }
        return false;   
    
}
void print(int v)
{
    for(int i=1;i<=v;i++)
        cout<<arr[i]<<" ";
}
void  hami(int v)
{
    
    for(int i=1;i<=v;i++)
        arr[i]=-1;
    
    arr[0]=0;
    int k=1;
    if(hamiutil(k,v)==false)
        {
            cout<< "not possible";
            return; 
        }
    print(v);

}
int main(int argc, char* argv[]) {
   int v,e,src,des;
   cin>>v>>e;
   for(int i=0;i<e;i++)
   {
       cin>>src>>des;
       add_edge(src,des);
   }
   displayMatrix(v);
   hami(v);
   
   return 0;
}
