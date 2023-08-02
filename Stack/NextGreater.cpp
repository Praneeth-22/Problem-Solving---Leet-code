#include <bits/stdc++.h>
using namespace std;

		vector<int> findNextGreater(vector<int> &v){
			stack <int> st;
			int n = v.size();
			vector<int> ret (n,-1);
	
			for(int iter = 2*n-1 ;iter>=0;iter--){
					while(st.top() <= v[iter%n] && !st.empty()){
						st.pop();
					} 
					if(iter<n){
						cout << "stack top "<<st.top();
						if(!st.empty()) ret[iter] = st.top();
					}
					st.push(v[iter%n]);
			}
			for(int i=0;i<ret.size();i++) cout <<ret[i];
			return ret;
		}

int main(){
	vector<int> v {5,7,1,2,6,0};
	cout<<"---";
	vector<int> res = findNextGreater(v);

	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	return 0;
}

