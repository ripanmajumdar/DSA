#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        if(nums.size()==0) return res;

        res.resize(nums.size());

        //Product of left elements
        res[0]=1;
        for(int i=1; i<nums.size(); i++){
            res[i]=nums[i-1]*res[i-1];      
        }

        //Product of right elements
        int prod=1;
        for(int i=nums.size()-1; i>=0; i--){
            res[i]=prod*res[i];
            prod=nums[i]*prod;     
        }
       return res;
     }
};

int main(){
    Solution ob;
    vector<int> nums={1,2,3,4};
    vector<int> res= ob.productExceptSelf(nums);
    cout<<"[";
    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<"\b]"<<endl;
    return 0;
}
