#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size()==0) return res;

        sort(intervals.begin(),intervals.end());
        for(int i=0; i<intervals.size(); i++){
        if(res.empty() || res.back()[1]<intervals[i][0]){
            res.push_back(intervals[i]);
        }
        else{
            res.back()[1] = max(res.back()[1],intervals[i][1]);
        }
       }
       return res;
    }
};

int main()
{
    Solution ob;
    vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res=ob.merge(intervals);
    for(int i=0; i<res.size(); i++){
        cout<<"{";
        for(int j=0; j<res[0].size(); j++){
            cout<<res[i][j];
        }
        cout<<"}, ";
    }
    cout<<endl;
    return 0;
}
