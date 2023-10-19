#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        //base case
        if(height.size()==0) return 0;

        int maxArea=0;
        int l=0;
        int r=height.size()-1;
        while(l<r) {
            int w=min(height[l],height[r]);
            
            int curArea=(r-l)*w;

            maxArea=max(maxArea,curArea);
            if(height[l]<height[r]) {
                l++;
            }
            else{
                r--;
            }
        }
    return maxArea;        
    }
};

int main()
{
    Solution ob;
    vector<int> input={1,8,6,2,5,4,8,3,7};
    cout<<"RESULT IS: "<<ob.maxArea(input)<<endl;
    return 0;
}