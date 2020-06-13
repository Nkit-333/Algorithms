    #include <iostream> 
    #include <list> 
    #include <stack> 
    using namespace std; 
    int store[3][3];
    class g 
    { 
        int V;    
        list<int> *adj;    
    
    
        void fill(int v, bool visited[], stack<int> &Stack); 
    
        
        void DFSUtil(int v, bool visited[],int i,int row); 
    public: 
        g(int V); 
        void addEdge(int v, int w); 
    
    
        void printSCCs(); 
    
        
        g trans(); 
    }; 
    
    g::g(int V) 
    { 
        this->V = V; 
        adj = new list<int>[V]; 
    } 
    


    void g::DFSUtil(int v, bool visited[],int k,int row) 
    { 
        
    
        
        visited[v] = true; 
        store[row][k]=v;
        //cout << store[row][k] << " "; 
        
        
        list<int>::iterator i; 
        for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        {
                if (!visited[*i]) 
                    DFSUtil(*i, visited,k+1,row);
                    
        }

        
    } 
    
    g g::trans() 
    { 
        g g(V); 
        for (int v = 0; v < V; v++) 
        { 
            list<int>::iterator i; 
            for(i = adj[v].begin(); i != adj[v].end(); ++i) 
            { 
                g.adj[*i].push_back(v); 
            } 
        } 
        return g; 
    } 
    
    void g::addEdge(int v, int w) 
    { 
        adj[v].push_back(w); 
    } 
    
    void g::fill(int v, bool visited[], stack<int> &Stack) 
    { 
        
        visited[v] = true; 
    
        
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
            if(!visited[*i]) 
                fill(*i, visited, Stack); 
    
        
        Stack.push(v); 
    } 
    

    void g::printSCCs() 
    { 
        stack<int> Stack; 
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;i++)
                store[i][j]=-1;
        }
        
        bool *visited = new bool[V]; 
        for(int i = 0; i < V; i++) 
            visited[i] = false; 
    
    
        for(int i = 0; i < V; i++) 
            if(visited[i] == false) 
                fill(i, visited, Stack); 
    
        
        g gr = trans(); 
    
    
        for(int i = 0; i < V; i++) 
            visited[i] = false; 
    
        
        int row=0;
        while (Stack.empty() == false) 
        { 
            
            int v = Stack.top(); 
            Stack.pop(); 
    
        
            if (visited[v] == false) 
            { 
                
                gr.DFSUtil(v, visited,0,row); 
            // cout << endl; 
                row++;
            } 
        
        } 
        int lol[3];
        for(int i=0;i<sizeof(store) / sizeof(store[0]);i++)
        {  
        int count=0;  
        for(int j=0;j<sizeof(store[0])/sizeof(store[0][0]);j++)
            {
                if(store[i][j]!=-1)
                    {
                        count++;
                    }
            } 

        lol[i]=count;
        }
        int max=lol[0];
        for(int i=0;i<max;i++)
        {
            if(max<lol[i])
                max=lol[i];
        }      
        cout<< max;

    } 
    

    int main() 
    { 
        int V,E;
        cin>>V>>E;
        g g(V); 
        int src,des;
        for(int i=0;i<E;i++)
        {
            cin>>src>>des;
            g.addEdge(src,des);
        }
    
        cout << "Following are strongly connected components in "
                "given g \n"; 
        g.printSCCs(); 
    
        return 0; 
    } 