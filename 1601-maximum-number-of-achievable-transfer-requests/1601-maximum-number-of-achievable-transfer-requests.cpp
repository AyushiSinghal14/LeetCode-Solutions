class Solution {
public:
    int res=0;
    void backTrack(int i,int count,vector<vector<int>>&req,vector<int>&indeg){
        //count will keep currrent count of requests that can be processed;
        //If traversed entire requests array, then check whether you are in valid state or not 
        //by checking all incoming requests = outgoing requests for the same
        if(i==req.size()){
            bool isValid=true;
            for(auto it:indeg){
                if(it!=0)isValid=false;
            }
            if(isValid)res=max(res,count);
            return;
        }

        //Take current request
        indeg[req[i][0]]-=1;
        indeg[req[i][1]]+=1;
        backTrack(i+1,count+1,req,indeg);
        //Not Consider
        indeg[req[i][0]]+=1;
        indeg[req[i][1]]-=1;
        backTrack(i+1,count,req,indeg);
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>indeg(n,0);
        backTrack(0,0,requests,indeg);
        return res;
    }
};