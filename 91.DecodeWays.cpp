#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int helper(string s, int idx,vector<int> &dp) {
        //base case
        if(idx>=s.length()) return 1;

        if(s[idx]=='0') return 0;

        if(idx>=s.length()-1) return 1;

        if(dp[idx]!=-1) return dp[idx];

        int n=stoi(s.substr(idx,2));
        if(n>=1 && n<=26){
            return dp[idx]=helper(s,idx+2,dp) + helper(s,idx+1,dp);
        }
        else{
            return dp[idx]=helper(s,idx+1,dp);
        }
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return helper(s,0,dp);
    }
};

int main()
{
    Solution ob;
    string str="226";
    cout<<"RESULT IS: "<<ob.numDecodings(str);
    return 0;
}
