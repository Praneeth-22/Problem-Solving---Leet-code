#include<bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr,int n){
	int low=0,mid=0,high = n-1;
	while(mid <= high){
		if(arr[mid] == 0){
//			swap(arr[low++],arr[mid++]);
			int temp;
			temp = arr[low];
			arr[low] = arr[mid];
			arr[mid] = temp;
			mid++;
			low++;
		}
		else if(arr[mid] == 1) mid++;
		else{
			int temp;
			temp = arr[mid];
			arr[mid] = arr[high];
			arr[high] = temp;
			high--;
		}
	}
}
int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
