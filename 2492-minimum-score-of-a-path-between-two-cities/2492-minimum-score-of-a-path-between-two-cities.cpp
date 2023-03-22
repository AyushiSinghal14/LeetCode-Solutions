class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj; //creating adjacency list
        int ans=INT_MAX; //creating answer variable
        for(auto i:roads) //putting values in adjacency list
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int>vis(n+1); //creating visited array
        queue<int> q; // quque required for bfs
        q.push(1); 
        vis[1] = 1;
        while(!q.empty()) // bfs loop
        {
            int node=q.front();
            q.pop();
            for(auto i:adj[node])
            {
                ans=min(ans,i.second);
                if(vis[i.first]!=1)
                {
                    vis[i.first]=1;
                    q.push(i.first);
                }
            }
        }
        return ans;
    }
};