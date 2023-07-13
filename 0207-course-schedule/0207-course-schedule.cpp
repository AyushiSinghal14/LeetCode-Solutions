class Solution {
public:
    bool canFinish(int Courses, vector<vector<int>>& prereq) {

       unordered_map<int,vector<int>>mpp;
       unordered_map<int,int>ind;
       vector<int>ans;
       queue<int>q;

       int n = prereq.size();

       for(int i = 0;i<n;++i)
       {
          mpp[prereq[i][1]].push_back(prereq[i][0]);
          ind[prereq[i][0]]++;
       }
    
       for(int i = 0; i < Courses; ++i)
       {
           if(!ind.count(i)) 
           {
              q.push(i);
              ans.push_back(i);
           }
       }

       while(!q.empty())
       {
           auto t = q.front();
           q.pop();
           for(auto &it : mpp[t])
           {
               ind[it]--; 
               if(ind[it] == 0) 
               {
                   ans.push_back(it); 
                   q.push(it); 
               }
           }
       }

      if(ans.size() != Courses) return false; 
  
      return true;
    }
};