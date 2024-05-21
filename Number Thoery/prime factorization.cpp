//#prime factorization


#include<bits/stdc++.h>
using namespace std;

vector<int> primeFactorization(int n){
	//sieve of eratosthenes
	
	vector<int> spf(n+1,0);
	for(int i=2;i<=n;i++){
		spf[i]= i;
	}
	for(int i=2;i<=sqrt(n);i++){
		if(spf[i] == i){
			for(int j = i*i;j<=n;j+=i){
				if(spf[j] ==j) {
					spf[j] = i;
				}
			}
		}
	}
	vector<int>res;
	while(n!=1){
		res.push_back(spf[n]);
		n/=spf[n];
	}
	return res;
}
int main(){
	int num =45;
	vector<int> factors = primeFactorization(num);
    cout << "Prime factors of " << num << " are: ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;
    return 0;
}
