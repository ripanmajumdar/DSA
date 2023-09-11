#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        //base case
        if(intervals.size()<=1) return true;
        int res=0;
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<intervals.size()-1; i++){
            if(intervals[i][1]<intervals[i+1][0]){
                return false;
            }
        }
        return true;;
    }
};

int main()
{
    Solution ob;
    vector<vector<int>> intervals={{0,30},{5,10},{15,20}};
    bool res=ob.canAttendMeetings(intervals);
    cout<<"RESULT :"<<res<<endl;
    return 0;
}
