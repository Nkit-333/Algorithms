#include <bits/stdc++.h> 

using namespace std;
struct node
{
    int data;
    int weight;
    node *next;
};

void insert(node *root[],struct node *head[],int src,int des,int w)
{
    if(head[src]==NULL)
    {
        node *temp= new node;
        temp->data=des;
        temp->weight=w;
        temp->next=NULL;

        head[src]=temp;
        root[src]=temp;
    }
    else
    {
        node *temp=new node;
        temp->data=des;
        temp->weight=w;
        temp->next=NULL;

        root[src]->next=temp;
        root[src]=temp;
    }
}

int main()
{
    int v,e;
    cin>>v>>e;
    node *root[v],*head[v];
    int path[v][v],distance[v][v];
    for(int i=0;i<v;i++)
    {
        
        head[i]=NULL;
        root[i]=NULL;
       
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(i==j)
            {
            distance[i][j]=0;
            }
            else{
            distance[i][j]=1000;
            path[i][j]=-1;
            }
        }
    }
    int src,des,w;
    for(int i=0;i<e;i++)
    {
        cin>>src>>des>>w;
        insert(root,head,src,des,w);
    }
    for(int i=0;i<v;i++)
    {
        root[i]=head[i];
        while(root[i]!=NULL)
        {
            path[i][root[i]->data]=i;
            distance[i][root[i]->data]=root[i]->weight;
            root[i]=root[i]->next;
        }
    }
    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(distance[i][j]>distance[i][k]+distance[k][j])
                {
                    distance[i][j]=distance[i][k]+distance[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        cout<<distance[i][j]<<" ";
        cout<<"\n";
    }
    /*int source,desti;
    cin>>source>>desti;
    cout<<desti<<" ";
    while(1)
    {
        
        if(path[source][desti]==source)
        {
            cout<<path[source][desti]<<" ";
            break; 
        }
        else if(path[source][desti]>v-1)
        {
            cout<<"path not found";
        }
        cout<<path[source][desti]<<" ";
        desti=path[source][desti];
    }*/
}