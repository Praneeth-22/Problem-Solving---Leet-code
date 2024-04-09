#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        //
        unordered_map<char,int> mp;
        int cnt=0,l=0,r=0,n = s.length();
        while(r<n){
        	mp[s[r]]++;
			while(mp.size() > k){
				mp[s[l]]--;
				if(mp[s[l]] ==0) mp.erase(mp.find(s[l]));
				l++;
			}
		
			cnt = max(cnt,(r-l+1));
			r++;
		}
        return cnt;
    }
};
int main(){
	Solution s;
	cout<<s.longestSubstring("aaabbccd",2);
	return 0;
}
