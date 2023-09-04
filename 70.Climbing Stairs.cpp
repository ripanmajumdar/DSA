/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct 
ways can you climb to the top?
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
    unordered_map<int,int> dp;

    int solveClimbStairs(int n){

        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
       int steps=0;
       if(n==0){
           steps=1;
       }
       else if(n<0){
           steps=0;
       }
       else{
           steps = solveClimbStairs(n-1) + solveClimbStairs(n-2);
       }
       dp[n]=steps; 
       return steps;
    }
    int climbStairs(int n) {
        if(!n) return 0;

        return solveClimbStairs(n);
    }
};

int main(){
    int n=5;
    Solution ob;
    cout<<"Input : "<<n<<endl;
    cout<<"Output : "<<ob.climbStairs(n)<<endl;
    return 0;
}