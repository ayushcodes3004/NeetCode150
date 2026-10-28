class Solution {
private:
    void bfs(int snode,vector<vector<int>>& adj,vector<int>& vis, int n){
        queue<int>q;
        q.push(snode);
        vis[snode]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto neigh: adj[node]){
                if(!vis[neigh]){
                    vis[neigh]=1;
                    q.push(neigh);
                }
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e: edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,adj,vis,n);
                cnt++;
            }
        }
        return cnt;
    }
};
