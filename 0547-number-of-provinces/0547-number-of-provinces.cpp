class Solution {
public:
    //Adjacency matrix to Adjacency list
    vector<vector<int>> matrixToList(vector<vector<int>>& isConnected, int n) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        return adj;
    }

    //dfs traversal
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[node] = true;

        for(int n : adj[node]) {
            if(!vis[n]) 
               dfs(n,adj,vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>>adj = matrixToList(isConnected,n);

        vector<bool>vis (n, false);
        int cnt = 0;

        for(int i = 0; i<n; i++) {
            if(!vis[i]) {
                dfs(i,adj,vis);
                cnt++;
            }
        } 
        return cnt;
    }
};