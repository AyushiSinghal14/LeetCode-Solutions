class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        int i=0;
        long ans=0;
        while(i<s.length() && s[i]==' ') i++; // count the spacing
        s=s.substr(i); // remove the space from left side
        int sign = 1;
        if(s[0]=='-') sign = -1; // check whether integer is positive or negative
        i=(s[0]=='-' || s[0]=='+') ? 1 : 0; // set value of i for traverse in the string
        while(i<s.length()){
            if(s[i]==' ' || !isdigit(s[i])) break;
            ans = ans*10+(s[i]-'0');
            if(sign==-1 && -1*ans<INT_MIN) return INT_MIN;
            if(sign==1 && ans>INT_MAX) return INT_MAX;
            i++;
        }
        return (int)(sign*ans);
    }
};