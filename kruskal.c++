#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
class edge
{
    public:
    int src,des,weight;


};
bool compare(edge e1,edge e2)
{
    return e1.weight<e2.weight;
}
int find(int *parent,int v)
{
    if(parent[v]==v)
        return v;
   return  find(parent,parent[v]);
}
void kruskal(edge *input ,int v,int e)
{
    sort(input,input+e,compare);

    edge *output=new edge[v-1];
    int *parent =new int [v];
    for(int i=0;i<v;i++)
        parent[i]=i;
    
    int i=0;
    int count=0;
    while(count!=v-1)
    {
        edge currentedge=input[i];
        int x=find(parent,currentedge.src);
        int y=find(parent,currentedge.des);
        if(x!=y)
            {
                output[count]=currentedge;
                count++;
                parent[x]=y;
            }
        i++;
    }
    for(int i=0;i<v-1;i++)
    {
        cout<< output[i].src <<" "<< output[i].des;
        cout<<"\n";
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    edge *input=new edge[e];
    for(int i=0;i<e;i++)
    {
        cin>>input[i].src>>input[i].des>>input[i].weight;
    }
    kruskal(input, v, e);
}