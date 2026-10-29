class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        int n=prerequisites.size();
        vector<vector<int>>adj(V);
        for(auto e: prerequisites){
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
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }
        return (cnt==V);
    }
};
