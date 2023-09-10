#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        for(int i=0; i<n; i++){
            if(intervals[i][0]>newEnd){
                ans.push_back(newInterval);
                copy(intervals.begin()+i,intervals.end(),back_inserter(ans));
                return ans;
            }
            else if(newStart>intervals[i][1]){
                ans.push_back(intervals[i]);
            }
            //Overlapping interval
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            
        }
        ans.push_back(newInterval);
        return ans;
    }
};

int main(){
    Solution ob;
    vector<vector<int>> intervals={{1,3},{6,9}};
    vector<int> newi={2,5};
    vector<vector<int>> res=ob.insert(intervals,newi);
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
