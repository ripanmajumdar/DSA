#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool helper(vector<int>& nums, int i,vector<int> &dp){
        //base case
        if(i==nums.size()-1) return true;

        if(i>=nums.size()) return false;
        
        if(dp[i]!=-1) return dp[i];

        int n=nums[i];
        while(n){
            if(helper(nums,i+n,dp)){
                 return dp[i]=true;
            }
            n--;
         }
         return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        //DP array for memory
        vector<int> dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
};
int main(){
    Solution ob;
    vector<int> nums={2,3,1,1,4};
    cout<<"Output[canJump]: "<<ob.canJump(nums)<<endl;
    return 0;
}
