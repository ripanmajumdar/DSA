#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
class Solution {
public:
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.size()==0) return res;

        unordered_map<string, vector<string>> umap;
        for(int i=0; i<strs.size(); i++){
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            umap[tmp].push_back(strs[i]);
        }
        for(auto i:umap){
            vector<string> temp;
            for(auto j:i.second) {
                temp.push_back(j);
            }
            res.push_back(temp);
        }
        return res;
    }
};
int main(){
    Solution ob;
    vector<string> strs={"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res= ob.groupAnagrams(strs);
    for(int i=0; i<res.size(); i++) {
        cout<<"[";
        for(int j=0; j<res[i].size(); j++) {
            cout<<res[i][j]<<",";
        }
        cout<<"\b]"<<endl;
    }
    return 0;
}
