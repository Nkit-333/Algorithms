// C++ program to print the complete 
// DFS-traversal of graph 
// using back-tracking 
#include <bits/stdc++.h> 
using namespace std; 
const int N = 1000; 
vector<int> adj[N]; 

// Function to print the complete DFS-traversal 
void dfsUtil(int u, int node, bool visited[], 
			vector<pair<int, int> > road_used, int parent, int it) 
{ 
	int c = 0; 

	// Check if all th node is visited or not 
	// and count unvisited nodes 
	for (int i = 0; i < node; i++) 
		if (visited[i]) 
			c++; 

	// If all the node is visited return; 
	if (c == node) 
		return; 

	// Mark not visited node as visited 
	visited[u] = true; 

	// Track the current edge 
	road_used.push_back({ parent, u }); 

	// Print the node 
	cout << u << " "; 

	// Check for not visited node and proceed with it. 
	for (int x : adj[u]) { 

		// call the DFs function if not visited 
		if (!visited[x]) 
			dfsUtil(x, node, visited, road_used, u, it + 1); 
	} 

	// Backtrack through the last 
	// visited nodes 
	for (auto y : road_used) 
		if (y.second == u) 
			dfsUtil(y.first, node, visited, 
					road_used, u, it + 1); 
} 

// Function to call the DFS function 
// which prints the DFS-travesal stepwise 
void dfs(int node) 
{ 

	// Create a array of visited ndoe 
	bool visited[node]; 

	// Vector to track last visited road 
	vector<pair<int, int> > road_used; 

	// Initialize all the node with false 
	for (int i = 0; i < node; i++) 
		visited[i] = false; 

	// call the function 
	dfsUtil(0, node, visited, road_used, -1, 0); 
} 

// Function to insert edges in Graph 
void insertEdge(int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 
void print()
{
    for(int a=0; a<11; a++) {
  for(vector<int>::const_iterator i =adj[a].begin(); i != adj[a].end(); ++i) {
    cout << *i << ' ';
  }
  cout << endl;
}
}
// Driver Code 
int main() 
{ 
	// number of nodes and edges in the graph 
	int node = 11, edge = 13; 

	// Function call to create the graph 
	insertEdge(0, 1); 
	insertEdge(0, 2); 
	insertEdge(1, 5); 
	insertEdge(1, 6); 
	insertEdge(2, 4); 
	insertEdge(2, 9); 
	insertEdge(6, 7); 
	insertEdge(6, 8); 
	insertEdge(7, 8); 
	insertEdge(2, 3); 
	insertEdge(3, 9); 
	insertEdge(3, 10); 
	insertEdge(9, 10); 
    //print();
	// Call the function to print 
	dfs(node); 

	return 0; 
} 
