/*
graph G = (V,E) consist of :
        V -> set of vertices (individual object in graph)
        E -> set of edges connecting pairs of vertices


        -directed graph : edges have direction
        -undirected : edges have no direction
        -weighted : edges have values (weight /cost /distance)
        -unweighted : no values for edges

        path : a sequence of vertices connected edges

        -cycle : a path that start and end at the same vertex

        Degree-> in undirected graphs -> number of edges connected to a vertex in directed graphs
            inDegree : incomming edges
            outDegree: outgoing edges

*/




/*

#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    vector<vector<int>> nearestZero(vector<vector<int>>& grid){
        // Write you code here...
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m,vector<int> (n,0));
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();
            
            if(x-1 >= 0 && !visited[x-1][y]){
                q.push({{x-1,y},d+1});
                ans[x-1][y] = d+1;
                visited[x-1][y] = 1;
            }
            if(x+1 < m && !visited[x+1][y]){
                q.push({{x+1,y},d+1});
                ans[x+1][y] = d+1;
                visited[x+1][y] = 1;
            }
            if(y-1 >= 0 && !visited[x][y-1]){
                q.push({{x,y-1},d+1});
                ans[x][y-1] = d+1;
                visited[x][y-1] = 1;
            }
            if(y+1 < n && !visited[x][y+1]){
                q.push({{x,y+1},d+1});
                ans[x][y+1] = d+1;
                visited[x][y+1] = 1;
            }
            
        }
        return ans;
    }
};
*/


/*

https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// User function Template for C++
class Solution {
  public:
    void dfs(int curr,vector<vector<pair<int,int>>> adj,vector<int> &visited,stack<int> &st){
        visited[curr] = 1;
        
        for(auto &i : adj[curr]){
            int n = i.first;
            if(!visited[n]){
                dfs(n,adj,visited,st);
            }
        }
        st.push(curr);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i = 0 ; i < m ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
        }
        
        vector<int> visited(n,0);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        
        vector<int> dist(n,INT_MAX);
        dist[0] = 0;
        
        while(!st.empty()){
            int n = st.top();
            st.pop();
            
            for(auto &edge:adj[node]){
                int i = edge.first;
                int w = edge.second;
                
                if(dist[n] + w < dist[i]){
                    dist[i] = dist[n] + w;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
    }
};

*/


/*
https://www.geeksforgeeks.org/problems/prerequisite-tasks/1
class Solution {
  public:
    bool dfs(int node , vector<vector<int>>&adj , vector<int>&visited,vector<int>&rec){
        visited[node] = 1;
        rec[node] = 1;
        
        for(auto n : adj[node]){
            if(!visited[n]){
                if(dfs(n,adj,visited,rec)){
                    return true;
                }
            }else if(rec[n]){
                return true;
            }
        }
        rec[node] = 0;
        return false;
    }
    
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<vector<int>> adj(N);
        
        for(auto & i : prerequisites){
            int u = i.first;
            int v = i.second;
            adj[v].push_back(u);
        }
        vector<int> visited(N,0);
        vector<int> rec(N,0);
        
        for(int i=0;i<N;i++){
            if(visited[i]){
                if(dfs(i,adj,visited,rec)){
                    return true;
                }
            }
        }
        return false;
    }
};
*/

/*
https://www.geeksforgeeks.org/problems/prerequisite-tasks/1
class Solution {
  public:
    bool dfs(int node , vector<vector<int>>&adj , vector<int>&visited,vector<int>&rec){
        visited[node] = 1;
        rec[node] = 1;
        
        for(auto n : adj[node]){
            if(!visited[n]){
                if(dfs(n,adj,visited,rec)){
                    return true;
                }
            }else if(rec[n]){
                return true;
            }
        }
        rec[node] = 0;
        return false;
    }
    
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<vector<int>> adj(N);
        
        for(auto & i : prerequisites){
            int u = i.first;
            int v = i.second;
            adj[v].push_back(u);
        }
        vector<int> visited(N,0);
        vector<int> rec(N,0);
        
        for(int i=0;i<N;i++){
            if(visited[i]){
                if(dfs(i,adj,visited,rec)){
                    return true;
                }
            }
        }
        return false;
    }
};
*/


/*
https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
  public:
    bool bfs(int start,vector<vector<int>> &adj,vector<bool> &visited){
        queue<int> q;
        unordered_map<int,int> parent;
        
        visited[start] = true;
        q.push(start);
        
        parent[start] = -1;
        
        while(!q.empty()){
            int n = q.front();
            q.pop();
            for(int i : adj[n]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                    parent[i] = n;
                }
                else if(parent[n] != i) return true;
            }
        }
        
        return false;
    }
    bool dfs(int n,vector<vector<int>> &adj,vector<bool> &visited,unordered_map<int,int> &parent){
        visited[node] = true;
        for(int i : adj[n]){
            if(!visited[i]){
                parent[i] = n;
                if(dfs(i,adj,visited,parent)) return true;
            }else if(parent[n] != i) return true;
        }
        return false
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
        
    }
};
*/

//Undirected GraphRepresentation - AdjacencyMatrix
#include <iostream>
using namespace std;

/*
class solution{
public:
    void adjmatrix(){
        // Write your code here... 
        int n;
        cin>>n;
        int e;
        cin>>e;
        vector<vector<int>> adj(n+1,vector<int>(n+1,0));
        for(int i=0;i<e;i++){
            int f,t;
            cin>>f>>t;
            adj[f][t] = 1;
            adj[t][f] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
};


//Undirected Graph Representation -Adjacency List
class solution{
    public:
    vector<vector<int>> adjList(){
        //Write your code here...
        int n;
        cin>>n;
        int e;
        cin>>e;
        
        vector<vector<int>> res(n+1);
        
        for(int i=1;i<=e;i++){
            int f,t;
            cin>>f>>t;
            res[f].push_back(t);
            res[t].push_back(f);
        }
        return res;
        
    }
};


//Directed Graph Representation - Adjacency Matrix
class solution{
    public:
    void adjmatrix(){
        //Write your code here...
        int n,e;
        cin>>n;
        cin>>e;
        
        vector<vector<int>> adjM(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=e;i++){
            int f,t;
            cin>>f>>t;
            adjM[f][t] = 1;
            
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<adjM[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
};


//Directed Graph Representation - Adjacency List
class solution{
public:
    vector<vector<int>> adjList(){
        //Write your code here...
        int n,e;
        cin>>n;
        cin>>e;
        
        vector<vector<int>> adjL(n+1);
        
        for(int i=1;i<=e;i++){
            int f,t;
            cin>>f>>t;
            adjL[f].push_back(t);
        }
        
        return adjL;
        
    }
};


//BFS
class solution{
public:
    vector<int> bfs(int n, vector<vector<int>> &adj){
        vector<int> ans;
        vector<int> visited(n, 0);
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int neighbour : adj[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }

        return ans;
    }
};


//DFS
class solution{
    public:
    void DFS(int curr,vector<vector<int>> adj,vector<int>&visited,vector<int> &ans){
        visited[curr] = 1;
        ans.push_back(curr);
        
        for(auto k : adj[curr]){
            if(visited[k] != 1){
                DFS(k,adj,visited,ans);
            }
        }
        
    }
    vector<int> dfs(int n, vector<vector<int>> adj){
        // Write your code here...
        vector<int> visited(n);
        vector<int> ans;
        DFS(0,adj,visited,ans);
        
        return ans;

    }
};



//num of provinces
class Solution {
public:

    void bfs(int start,vector<vector<int>> isConnected,vector<int> &visited){
        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while(!q.empty()) {
            int city = q.front();
            q.pop();

            for(int j = 0; j < isConnected.size(); j++) {
                if(isConnected[city][j] == 1 && visited[j] == 0) {
                    visited[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n);
        int count = 0;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                count++;
                bfs(i,isConnected,visited);
            }
        }
        return count;

    }
};

//number of islands 


class solution{
public:
    void helper(int i,int j,vector<vector<int>> grid,vector<vector<int>> &visited){
        if(visited[i][j] == 1) return;
        
        visited[i][j] = 1;
    
        if(grid[i][j] == 1){
            if(i-1 >=0 && visited[i-1][j] != 1){
                helper(i-1,j,grid,visited);
            }
            if(i+1 < grid.size() && visited[i+1][j] != 1){
                helper(i+1,j,grid,visited);
            }
            if(j-1 >=0 && visited[i][j-1] != 1){
                helper(i,j-1,grid,visited);
            }
            if(j+1 < grid[0].size() && visited[i][j+1] != 1){
                helper(i,j+1,grid,visited);
            }
        }
    }
    
    int numOfIslands(vector<vector<int>>& grid){
        // Write your code here...
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j] == 0){
                    count++;
                    helper(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};




//flood fill

class solution{
    public:
        
    void dfs(vector<vector<int>> &image,int r,int c,int newColor,int currColor){
        if(image[r][c] == currColor){
            image[r][c] = newColor;
        }
        
        if(r-1 >= 0 && image[r-1][c] == currColor){
            dfs(image,r-1,c,newColor,currColor);
        }
        if(r+1 < image.size() && image[r+1][c] == currColor){
            dfs(image,r+1,c,newColor,currColor);
        }
        if(c-1 >= 0 && image[r][c-1] == currColor){
            dfs(image,r,c-1,newColor,currColor);
        }
        if(c+1 < image[0].size() && image[r][c+1] == currColor){
            dfs(image,r,c+1,newColor,currColor);
        }
        
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int r, int c,int newColor){
            // Write your code here...
        
        if(image[r][c] == newColor) return image;
        int currColor = image[r][c];
        dfs(image,r,c,newColor,currColor);
        
        return image;
    }
};



*/




int main(){
    int n;
    int m;

    cout<<"ENTER the number of vertices : ";
    cin>>n;

    cout<<"ENTER the number of edges : ";
    cin>>m;


    unordered_map<int,vector<int>> adjList;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cout<<"adjacency List : "<<endl;
    for(auto i : adjList){
        cout<<endl;
        for(int j : i.second){
            cout<<j<<" ";
        }

    }/*
    unordered_map<int,vector<pair<int,int>>> adjListWeighted;
    for(int i=0;i<m;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        adjList[u].push_back({v,weight});
    }

    for(auto i : adjListWeighted){
        cout<<i.first<<" : "<< endl;
        for(int j : i.second){
            cout<<j.first << " " <<j.second;
        }
    }*/
    

}

