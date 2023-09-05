/*You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security systems connected and it will automatically contact the police
 if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house,
 return the maximum amount of money you can rob tonight without alerting 
 the police.*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        int res=0;
        vector<int> loot(nums.size());
        loot[0]=nums[0];
        loot[1]=max(nums[0],nums[1]);
        for(int i=2; i<nums.size(); i++){
            loot[i]=max(loot[i-1],nums[i]+loot[i-2]);
        }
        return loot.back();
    }
};
int main()
{
    Solution ob;
    vector<int> input={2,7,9,3,1};
    cout<<"RESULT IS: "<<ob.rob(input);
    return 0;
}