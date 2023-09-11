//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    //int count = 2;
    bool isLucky(int n) {
        // code here
        
        int count = 2; //Set count variable at 2 cause 
        //the element started deleting from 2 thn increase
        
        while(count <= n){ //While loop continue till count is lesser than or equal n
        
            if(n%count == 0)return 0;//if number is divisible by count thhat means it got deleted
            //Not lucky
            
            n = n - (n/count);//If count is 2 and number is 11 then total 5 number will be deleted
            // remaining number = number - deleted number
            count++;//count is increased as per the problem
        }
        return 1;//While loop ends and the number survived so lucky
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends