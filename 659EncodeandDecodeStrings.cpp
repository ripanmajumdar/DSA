#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
   string encode(vector<string> str) {
        // write your code here
        string res="";
        if(str.size()==0) return res;

        for(auto &s:str){
            res+=to_string(s.length())+"#"+s;
        }
        return res;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string str) {
        // write your code here
        int i=0;
        vector<string> res;
        while(i<str.size()){
            int j=i;
            while(str[j]!='#'){
                j++;
            }
         int len=stoi(str.substr(i,j));
         string tmp=str.substr(j+1,len);
         res.push_back(tmp);
         i=j+len+1;
        }
        return res;
    }
};

int main()
{
    Solution ob;
    vector<string> input={"lint","code","love","you"};
    cout<<"-----INPUT STRING----\n";
    for(int i=0; i<input.size(); i++){
        cout<<input[i];
    }
    cout<<endl;

    string encodedStr = ob.encode(input);
    cout<<"------ENCODED STRING---\n";
    cout<<encodedStr<<endl;
   
   vector<string> str = ob.decode(encodedStr);
    cout<<"------DECODED STRING---\n";
    for(int i=0; i<str.size(); i++){
        cout<<str[i];
    }
 return 0;
}