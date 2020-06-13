#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
int vertArr[20][20]; //the adjacency matrix initially 0
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
bool issafe(int v,int color[],int row,int c)
{
    for(int i=0;i<v;i++)
    {
        if(vertArr[row][i]==1&&color[i]==c)
            return false;
        
    }
    return true;
}
bool graphcolorutil(int v,int m,int color[],int row)
{
    if(v==row)
        return true;

    for(int i=1;i<=m;i++)
    {
        if(issafe(v,color,row,i))
        {
            color[row]=i;

            if(graphcolorutil(v,m,color,row+1)==   true )
                return true;
            else    
            color[row]=0;
        }
    }
    return false;
}
void printsol(int color[],int v)
{
    for(int i=0;i<v;i++)
        cout<<color[i]<<" ";
}
bool graphcolor(int v,int m)
{
    int color[v];
    for(int i=0;i<v;i++)
        color[i]=0;
    if(graphcolorutil(v,m,color,0)==false)
    {
        cout<<"solution not possible";
        return false;
    }
        printsol(color,v);
        return true;

     
}
int main(int argc, char* argv[]) {
   int v,e,src,des;
   cin>>v>>e;
   for(int i=0;i<e;i++)
   {
       cin>>src>>des;
       add_edge(src,des);
   }
   int m;
   cin>>m;
   graphcolor(v,m);
   //displayMatrix(v);
   return 0;
}