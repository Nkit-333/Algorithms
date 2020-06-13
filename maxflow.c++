#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define v 5
bool BFS(int graph[v][v],int source,int sink,int parent[])
{
	
	int visited[v];
	bool send;
	for(int i=0;i<v;i++)
	{
			visited[i]=0;
			parent[i]=-1;
	}
	queue<int> tqueue;
	
	tqueue.push(source);
	visited[source]=1;
	send=false;
	
	while(!tqueue.empty())
		{
			
			int start=tqueue.front();
			tqueue.pop();
			for(int j=0;j<v;j++)
			{
				if(graph[start][j]>0&&visited[j]==0)
				{
					
					tqueue.push(j);
					visited[j]=1;
					parent[j]=start;

					if(j==sink)
					{
						send=true;
						break;
					}
				}
			}

		}
		
			
		return send;
}

void MaxFlow(int graph[v][v], int source, int sink)
{
	
	int parent[v];
	int u;
	int max_flow=0;
	while(BFS(graph,source,sink,parent))
	{
		int path_flow=INT_MAX;
		for(int i=sink;i!=source;i=parent[i])
		{
			u=parent[i];
			path_flow=min(path_flow,graph[u][i]);
		}
		for(int i=sink;i!=source;i=parent[i])
		{
			u=parent[i];
			graph[u][i]-=path_flow;
			graph[i][u]+=path_flow;
		}
		max_flow+=path_flow;
	}
	cout<<max_flow;
}

int main()
{
 	
	int graph[v][v];
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			graph[i][j]=0;
	int src,des,weight,e;
	cin>>e;
	for(int i=0;i<e;i++)
	{
		cin>>src>>des>>weight;
		graph[src][des]=weight;
	}
		for(int i=0;i<v;i++)
		{	
		for(int j=0;j<v;j++)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<"\n";
	}
	MaxFlow(graph, 0, 4);

}