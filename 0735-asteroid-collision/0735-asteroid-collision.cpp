class Solution {
public:
    void operation(int i,stack<int>&st,vector<int>& asteroids){
        while(!st.empty()){
            int top= st.top();
            if( top == abs(asteroids[i]) ){
                asteroids[i]=0;
                st.pop();
                return ;
            }
            else if( top > abs(asteroids[i]) ) return ;
            else{
                st.pop();
            }
        }
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n=asteroids.size();

        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()  &&  asteroids[i]<0) ans.push_back(asteroids[i]);
            else if(asteroids[i]>0) st.push(asteroids[i]);
            else{
                operation(i,st,asteroids);
                if(st.empty() && asteroids[i]!=0){
                    ans.push_back(asteroids[i]);
                }
            }
        }

        vector<int> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};