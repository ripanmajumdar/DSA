#include<iostream>
#include<string>
#include<set>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> uset;
        int j=0;
        int maxSize=0;
        int i=0;
        while(i<s.length()) {
            if(uset.count(s[i])==0){
                uset.insert(s[i]);
                maxSize=max(maxSize,(int)uset.size());
                i++;
            }
            else{
                uset.erase(s[j]);
                j++;
            }
        }
        return maxSize;
    }
};

int main()
{
    Solution ob;
    string input="abcabcbb";
    cout<<"RESULT IS: "<<ob.lengthOfLongestSubstring(input)<<endl;
    return 0;
}