/*There is a robot on an m x n grid. The robot is initially located
 at the top-left corner (i.e., grid[0][0]). The robot tries to move 
 to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can
  only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique 
paths that the robot can take to reach the bottom-right corner.*/

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int isValid(int m, int n,int i, int j) {
        if(i>=m || i<0 || j>=n || j<0)
            return false;
        else
            return true;
    }

    int helper(int m, int n,int i,int j,vector<vector<int>> &dp){
        if(!isValid(m,n,i,j)){
             return 0;
        }
        if(i==m-1 && j==n-1){
             return 1;
        }
       if(dp[i][j]!= -1) return dp[i][j];

         int r = helper(m,n,i,j+1,dp);
         int b = helper(m,n,i+1,j,dp);
    
        return dp[i][j] = r+b;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m,n,0,0,dp);
    }
};

int main(){
    Solution ob;
    int m=3, n=7;
    cout<<"Unique Path for m: "<<m<<" and n: "<<n<<"|is: "<<ob.uniquePaths(m,n)<<endl;
    return 0;
}