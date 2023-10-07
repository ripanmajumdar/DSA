#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;
class Solution {
public:
    void DFS(unordered_map<int,list<int>> &edge,vector<int> &visited,int node) {
        visited[node]=true;

        for(auto it:edge[node]){
            if(!visited[it]) {
                DFS(edge,visited,it);
            }
        }
    }
    int noOfConnectedComponent(vector<vector<int>>&es, int v) {
        //base case
        if(es.size()==0) return 0;

     unordered_map<int,list<int>> edge;
     for(int i=0; i<es.size(); i++){
        edge[es[i][0]].push_back(es[i][1]);
        edge[es[i][1]].push_back(es[i][0]);
     }

    vector<int> visited(v,false);
    int res=0;

    for(int i=0; i<v; i++){
        if(!visited[i]) {
            res++;
            DFS(edge,visited,i);
        }
    }
    return res;;
    }
};

int main()
{
    Solution ob;
    vector<vector<int>> edges={{0,1},{1,2},{3,4}}; 
    int res=ob.noOfConnectedComponent(edges,5);
    cout<<"RESULT :"<<res<<endl;
    return 0;
}
