 #include<iostream>
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
void DFS(node*head[],node*root[],int v )
{
    int flag[v],start;
    memset(flag,0,sizeof(flag));
    stack<int> mystack; 
    mystack.push(0);
    start=mystack.top();
    mystack.pop();
    cout<<start;
    while(1)
    {
        
        flag[start]=1;
        
       // int x=0;
        root[start]=head[start];
        while(root[start]!=NULL)
        {       
           if(flag[root[start]->data]==0)
           {
               
               flag[root[start]->data]=1;
               mystack.push(root[start]->data);
           }
           root[start]=root[start]->next;
        }                                                             
        if(mystack.empty()==1)
            break;
        else
            {
                start=mystack.top();
                mystack.pop();
                cout<<start;
            }
       
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
   print(head,root,v);
   DFS(head,root,v);
}
