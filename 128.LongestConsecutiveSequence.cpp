#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;

        int res=0;
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i]-1)==st.end()){
                int cres=1;
                int n=nums[i]+1;
                while(st.find(n)!=st.end()){
                    cres++;
                    n++;
                }
                res=max(res,cres);
            }
        }
        return res;
    }
};
int main()
{
    Solution ob;
    vector<int> input={100,4,200,1,3,2};
    cout<<"RESULT IS: "<<ob.longestConsecutive(input);
    return 0;
}