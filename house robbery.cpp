#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; 
	cin >> n;
	vector<int>nums(n);
	for(int i = 0;i<n;i++){
		cin  >> nums[i];
	}
	int curr = 0,pre2 = 0,pre1 = 0;
	
	for(int num : nums){
		curr = max(pre1,num+pre2);
		pre2 = pre1;
		pre1 = curr;
	}
	cout << pre1 << " ";
	return 0;
}