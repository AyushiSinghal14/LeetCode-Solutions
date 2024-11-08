class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<pair<int , int> , int> , vector<pair<pair<int , int> , int>> , greater<pair<pair<int , int> , int>>>pq;
        vector<pair<vector<int> , int >>v; 
        vector<int>ans; 
        for(int i = 0;i<tasks.size();i++)
        {
            v.push_back({tasks[i] , i});
        }
        sort(v.begin() , v.end());
        long long int ind = 0 , i = 0;
        while(true)
        {
            if(i<v.size() && v[i].first[0] > ind && pq.empty())
            {
                ind = v[i].first[0];
            }
            while(i<v.size() && v[i].first[0] <= ind)
            {
                pq.push({{v[i].first[1] , v[i].second} , v[i].first[0]});
                i++;
            }
            if(i == v.size())
            {
                while(!pq.empty())
                {
                    auto it = pq.top();
                    pq.pop();
                    ans.push_back(it.first.second);
                }
                break;
            }
            else
            {
                auto it = pq.top();
                pq.pop();
                ind += it.first.first;
                ans.push_back(it.first.second);
            }
            // ind++;
        }
        return ans;
    }
};

