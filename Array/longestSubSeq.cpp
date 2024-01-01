#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int> v){
	sort(v.begin(),v.end());
	int i=1;
	int cnt=0;
	int tempCnt=1;
	while(i!=v.size()){
		if (v[i-1] == v[i]-1){
			tempCnt++;
//			cout<<"temp count:"<<tempCnt;
		}else{
//			cout<<"temp_cnt"<<tempCnt;
			tempCnt=1;
		}
		cnt =max(tempCnt,cnt);
		i++;
	}
	return cnt;
}
int main()
{
    vector<int> a = {100, 200, 1, 3, 2, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
