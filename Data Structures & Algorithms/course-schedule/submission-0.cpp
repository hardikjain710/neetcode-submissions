class Solution {
public:
bool dfs(vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& in_stack ,int node,int parent){
    visited[node]=true;
    in_stack[node]=true;
    for(int u:adj[node]){
        if(!visited[u]){
            if(dfs(adj,visited,in_stack,u,node)){
                return true;
            }
        }
        else if(in_stack[u]){
            return true;

        }
    }
    in_stack[node]=false;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i=0; i<n; i++){
            int n1=prerequisites[i][0];
            int n2=prerequisites[i][1];
            adj[n2].push_back(n1);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>in_stack(numCourses,false);
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(adj,visited,in_stack,i,-1)){
                    return false;
                }
            }
        }
        return true;
    }
};
