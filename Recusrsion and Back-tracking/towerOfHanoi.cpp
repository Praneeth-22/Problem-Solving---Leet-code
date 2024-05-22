#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n,char src,char help,char dest){
	if(n>0){
		//towerOfHanoi(from:src,helper:dest,destination:help)
		towerOfHanoi(n-1,src,dest,help);
		cout<<"Move from" <<src<<"->"<<dest<<endl;
		//towerOfHanoi(from:help,helper:src,destination:dest)
		towerOfHanoi(n-1,help,src,dest);
	}
}
int main(){
	towerOfHanoi(3,'A','B','C');
	return 0;
}
