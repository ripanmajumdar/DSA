#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //base case
        if(intervals.size()<=1) return 0;
        int res=0;
        sort(intervals.begin(), intervals.end());
        int endVal = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(endVal>intervals[i][0]){
                res++;
                endVal =min(endVal,intervals[i][1]);
            }
            else{
                endVal = intervals[i][1];
            }
        }
        return res;
    }
};

int main()
{
    Solution ob;
    vector<vector<int>> intervals={{1,2},{2,3},{3,4},{1,3}};
    int res=ob.eraseOverlapIntervals(intervals);
    cout<<"RESULT :"<<res<<endl;
    return 0;
}
