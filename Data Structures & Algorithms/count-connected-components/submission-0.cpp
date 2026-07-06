class Solution {
public:
void dfs(vector<vector<int>>& adj,vector<bool>&visited,int node){
    visited[node]=true;
    for(int u:adj[node]){
        if(!visited[u]){
            dfs(adj,visited,u);
        }
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(int i=0; i<m; i++){
            int n1=edges[i][0];
            int n2=edges[i][1];
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                cnt++;
            }
        }
        return cnt;

    }
};
