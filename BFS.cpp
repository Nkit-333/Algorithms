 #include<bits/stdc++.h>
 using namespace std;
 struct node
 {
     int data;
     node *next; 
 };
void insert(node*root[],node*head[],int src,int des)
{
    if(head[src]==NULL)
    {
    node *temp=new node;
    temp->data=des;
    temp->next=NULL;
    head[src]=temp;
    root[src]=temp;

    }
    else
    {
        node *temp=new node;
        temp->data=des;
        temp->next=NULL;
        root[src]->next=temp;
        root[src]=temp;
    }
}
void BFS(node *root[], node *head[],int v)
{
    int visited[v];

    for(int i=0;i<v;i++)
        visited[i]=0;

    list <int> storque;
    int i=0;
    visited[i]=1;
    storque.push_back(i);
   while(!storque.empty())
    {
        i=storque.front();
        storque.pop_front();
        cout<<i<<" "; 
        
        root[i]=head[i];

        while(root[i]!=NULL)
        {
            if(visited[root[i]->data]==0)
            {
                storque.push_back(root[i]->data);
                visited[root[i]->data]=1;
            }
            root[i]=root[i]->next;
        }
        

     }  

}
void printgraph(node* root[],node *head[],int v)
{
    for(int i=0;i<v;i++)
    {
        root[i]=head[i];
        while(root[i]!= NULL)
        {
            cout<<root[i]->data<<" ";
            root[i]=root[i]->next;
        }
        cout<<"\n";
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
      /*  if(src==des)
        insert(root,head,src,des);*/
    
                insert(root,head,src,des);
                insert(root,head,des,src);

            
    }
   
    //printgraph(root,head,v);
   BFS(root,head,v);
}