 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 struct node
 {
     int data;
     //int weight;
     node *next; 
 };
void insert(node*root[],node*head[],int src,int des)
{
    if(head[src]==NULL)
    {
    node *temp=new node;
    temp->data=des;
    temp->next=NULL;
   // temp->weight=w;
    head[src]=temp;
    root[src]=temp;

    }
    else
    {
        node *temp=new node;
        temp->data=des;
        temp->next=NULL;
        //temp->weight=w;
        root[src]->next=temp;
        root[src]=temp;
    }
}
void print(struct node * head[],struct node *  root[],int V)
{
    for(int i=0;i<V;++i)
    {
        root[i] = head[i];
        while(root[i] != NULL)
        {
            cout<<root[i]-> data;
            //cout<<root[i] -> weight;
            root[i] = root[i]->next;
        }
        cout<<"\n";
    }
}
void DFS(int i,node*head[],node*root[],int v )

{
    node *p;
   
	printf("\n%d",i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;
       
	   if(!visited[i])
            DFS(i);
        p=p->next;
    }
}
int main()
{

    int v,src,des,w;
    cin>>v;
    
    node *root[v],*head[v];
    for(int i=0;i<v;i++)
    {
        root[i]=NULL;
        head[i]=NULL;
    }
    int e;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>src>>des;
        if(src==des)
        insert(root,head,src,des);
        else{
                insert(root,head,src,des);
                insert(root,head,des,src);
            }
    }
   //print(head,root,v);
   DFS(0,head,root,v);
}
