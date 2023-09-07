#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    void solveDFS(vector<vector<int>>& heights,int i,int j,vector<vector<bool>> &vis){
        vis[i][j]=true;

        //up
            if(i-1>=0 && vis[i-1][j]!=true && heights[i-1][j]>=heights[i][j]){
                solveDFS(heights,i-1,j,vis);
            }
        //down
            if(i+1<heights.size() && vis[i+1][j]!=true && heights[i+1][j]>=heights[i][j]){
                solveDFS(heights,i+1,j,vis);
            }
        //left
            if(j-1>=0 && vis[i][j-1]!=true && heights[i][j-1]>=heights[i][j]){
                solveDFS(heights,i,j-1,vis);
            }
        //right
            if(j+1<heights[0].size() && vis[i][j+1]!=true && heights[i][j+1]>=heights[i][j]){
                solveDFS(heights,i,j+1,vis);
            } 
       
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        if(heights.size()==0) return res;
        vector<vector<bool>> pecific(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>> atlantic(heights.size(),vector<bool>(heights[0].size(),false));
        
        int m=heights.size();
        int n=heights[0].size();

        for(int i=0; i<heights.size(); i++){
            solveDFS(heights,i,0,pecific);
            solveDFS(heights,i,n-1,atlantic);
        }
         for(int j=0; j<heights[0].size(); j++){
            solveDFS(heights,0,j,pecific);
            solveDFS(heights,m-1,j,atlantic);
        }
        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[0].size(); j++){
                if(pecific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }

        }
        return res;
    }
};

int main(){
    Solution ob;
    vector<vector<int>> heights={{1,2,2,3,5},{3,2,3,4,4},{3,2,3,4,4},{3,2,3,4,4},{5,1,1,2,4}};
    vector<vector<int>> res=ob.pacificAtlantic(heights);
    for(int i=0; i<res.size(); i++){
        cout<<"{";
        for(int j=0; j<res[0].size(); j++){
            cout<<res[i][j];
        }
        cout<<"}, ";
    }
    return 0;
}
