#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;
class Solution {
public:
    bool hasCycle(unordered_map<int,list<int>> &edge,vector<int> &visited,int cur,int parent){
        if(visited[cur]) return true;

        visited[cur]=true;
        for(auto it:edge[cur]){
            if(it!=parent && hasCycle(edge,visited,it,cur)){
                return true;
            }
        }
    return false;
    }
    int isValidTree(vector<vector<int>>&es, int v) {
        //base case
        if(es.size()==0) return true;

     unordered_map<int,list<int>> edge;
     for(int i=0; i<es.size(); i++){
        edge[es[i][0]].push_back(es[i][1]);
        edge[es[i][1]].push_back(es[i][0]);
     }

    vector<int> visited(v,false);
    if(hasCycle(edge,visited,0,-1)){
        return false;
    }
    for(int i=0; i<visited.size(); i++){
        if(!visited[i]) return false;
    }

        return true;
    }
};

int main()
{
    Solution ob;
    vector<vector<int>> edges={{0,1},{0,2},{0,3},{1,4}}; //result must true
    //vector<vector<int>> edges={{0,1},{0,2},{0,3},{1,4},{4,2}}; //result must false
    int res=ob.isValidTree(edges,5);
    cout<<"RESULT :"<<res<<endl;
    return 0;
}
