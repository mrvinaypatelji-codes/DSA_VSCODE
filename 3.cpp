#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int>nums(n);
	for(int i = 0;i<n;i++){
		cin >> nums[i];
	}
	
	vector<int>ans(n+1,0);
	for(int num:nums){
		ans[num]++;
	}
	int duplicate = -1,missing = -1;
	for(int i = 1;i<=n;i++){
		if(ans[i] == 2){
			cout << i << " ";
		}
		if(ans[i] == 0){
			cout << i << " ";
		}
	}
	return 0;
}