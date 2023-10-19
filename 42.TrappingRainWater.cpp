#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        
        int l=0;
        int r=height.size()-1;
        int maxLeftHeight=height[l];
        int maxRightHeight=height[r];
       
        int result=0;

        while(l<r) {
            
            if(maxLeftHeight<=maxRightHeight) {
                l++;
                maxLeftHeight = max(maxLeftHeight, height[l]);
                result += maxLeftHeight - height[l];
            }
            else {
                r--;
                maxRightHeight=max(maxRightHeight,height[r]);
                result+=maxRightHeight-height[r];
            }
        }
        return result;
    }
};

int main()
{
    Solution ob;
    vector<int> input={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"RESULT IS: "<<ob.trap(input)<<endl;
    return 0;
}