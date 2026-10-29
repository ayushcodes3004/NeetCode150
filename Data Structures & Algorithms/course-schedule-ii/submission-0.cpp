class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<vector<int>>adj(V);
        for(auto  e: prerequisites){
            int u=e[0], v=e[1];
            adj[v].push_back(u);
        }
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto v: adj[i]){
                indegree[v]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }
        return ((ans.size()==V)? ans: vector<int>{});
    }
};
