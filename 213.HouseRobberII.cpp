#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int robHelper(vector<int>& nums, int idx, vector<int> &dp){
        //base case
        if(idx==0) return nums[0];

        if(idx<0) return 0;

        //check value in dp
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take=nums[idx]+robHelper(nums,idx-2,dp);

        int notTake=robHelper(nums,idx-1,dp);

        return dp[idx]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        
       
       if(nums.size()==0) return 0;
       if(nums.size()==1) return nums[0];

        vector<int> tmp1;
        vector<int> tmp2;

        for(int i=0; i<nums.size(); i++){
            if(i!=0) tmp1.push_back(nums[i]);
            if(i!=nums.size()-1) tmp2.push_back(nums[i]);
        }
        vector<int> dp1(tmp1.size(),-1);
        vector<int> dp2(tmp2.size(),-1);

        return max(robHelper(tmp1,tmp1.size()-1,dp1),robHelper(tmp2,tmp2.size()-1,dp2));
    }
};

int main()
{
    Solution ob;
    vector<int> input={1,2,3,1};
    cout<<"RESULT IS: "<<ob.rob(input);
    return 0;
}