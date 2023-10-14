#include<iostream>
#include<vector>
#include<string>

using namespace std;
struct Node {
        Node *link[26];
        bool isWord = false;
        string word;
       }; 

class Solution {
public:
    Node *root;
    Solution() {root = new Node();}

    //Trie insert function
    void insert(string word) {
        Node *node = root;
        for(int i=0; i<word.length(); i++) {
            char ch = word[i];
            if(node->link[ch-'a'] == NULL) {
                //Create new trie node
                Node *tmp=new Node();
                node->link[ch-'a']=tmp;
            }
            node = node->link[ch-'a'];
        }
        node->isWord=true;
        node->word=word;
    }

    //DFS function to traverse in the board
    void DFS(vector<vector<char>> &board,int i, int j, int r, int c, vector<string> &ans, Node *node) {
        char ch = board[i][j];
        if(ch=='$' || node->link[ch-'a']==NULL) {
            return;
        }
        node = node->link[ch-'a'];
        if(node->isWord=true) {
            ans.push_back(node->word);
            node->isWord=false;
        }
        board[i][j]='$'; //just temporary updating $ with current character to marking visited 
        if(i>0){
            DFS(board,i-1,j,r,c,ans,node);
        }
        if(i<r-1){
            DFS(board,i+1,j,r,c,ans,node);
        }
        if(j>0){
            DFS(board,i,j-1,r,c,ans,node);
        }
        if(j<c-1){
            DFS(board,i,j+1,r,c,ans,node);
        }
        board[i][j]=ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //Insert all words into Trie
        for(int i=0; i<words.size(); i++) {
            insert(words[i]);
        }
        
        vector<string> ans;
        //Using DFS search word in the board
        int r = board.size();
        int c = board[0].size();

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                DFS(board,i,j,r,c,ans,root);
            }
        }
    return ans;
    }
};

int main(){
    Solution ob;
    vector<vector<char>> board={{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};

    vector<string> res=ob.findWords(board,words);

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<"\n";
    }
    return 0;
}
