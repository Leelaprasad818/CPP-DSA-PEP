//Undirected GraphRepresentation - AdjacencyMatrix
#include <bits/stdc++.h>
using namespace std;

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



