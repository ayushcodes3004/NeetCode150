class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int size=edges.size();
        if(size!= n-1) return false;
        vector<vector<int>>adj(n);
        for(auto e: edges){
            int u=e[0], v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        queue<pair<int,int>>q;
        q.push({0,-1});
        vis[0]=true;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto neigh : adj[node]){
                if(!vis[neigh]){
                    q.push({neigh,node});
                    vis[neigh]=true;
                }else if(neigh!=parent){
                    return false;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;

    }
};
