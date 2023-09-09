#include<iostream>
#include<unordered_set>
#include<vector>
#include<limits.h>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //boundary cases
        if(nums.size()==0) return 0;

        unordered_set<int> seq;
        int longestSeq=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            seq.insert(nums[i]);
        }
        for(auto it:seq){
            if(seq.find(it-1)==seq.end()){
                int cnt=1;
                int x=it;
                while(seq.find(x+1)!=seq.end()){
                    cnt++;
                    x++;
                }
                longestSeq = max(longestSeq,cnt);
            }
        }
     return longestSeq;
    }
};
int main(){
    Solution ob;
    vector<int> nums={100,4,200,1,3,2};
    cout<<"Longest Consecutive Sequence is : "<<ob.longestConsecutive(nums)<<endl;
    return 0;
}