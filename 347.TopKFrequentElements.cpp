#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>

using namespace std;
struct compare {
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.first<b.first;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size()==0) return res;

        unordered_map<int,int> umap;
        for(int i=0; i<nums.size(); i++){
        auto it=umap.find(nums[i]);
        if(it != umap.end()) {
            umap[nums[i]]++;
        }
        else {
            umap[nums[i]]=1;
        }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        for(auto it:umap) {
            pq.push(make_pair(it.second,it.first));
        }
        while(k>0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
    return res;
    }
};

int main(){
    Solution ob;
    vector<int> nums={1,1,1,2,2,3};
    int k =2;
    vector<int> res= ob.topKFrequent(nums,k);
    cout<<"[";
    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<"\b]"<<endl;
    return 0;
}
