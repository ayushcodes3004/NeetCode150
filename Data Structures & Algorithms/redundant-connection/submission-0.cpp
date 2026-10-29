class DSU{
    vector<int>parent,rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int i){
        return (parent[i]==i)?i: parent[i]=find(parent[i]);
    }
    void unite(int u, int v){
        int s1=find(u), s2=find(v);
        if(s1!=s2){
            if(rank[s1]>rank[s2])   parent[s2]=s1;
            else if(rank[s1]<rank[s2]) parent[s1]=s2;
            else{
                rank[s2]++;
                parent[s1]=s2;
            }
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU d(n+1);
        for(auto e: edges){
            int u=e[0], v=e[1];
            if(d.find(u)==d.find(v)) return {u,v};
            d.unite(u,v);
        }
        return {};
    }
};
