#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int>nums(2*n);
	for(int i =0;i<2*n;i++){
		cin >> nums[i];
	}
	vector<int>result;
	for(int j = 0;j<2*n;j++){
		result.push_back(nums[j]);
		result.push_back(nums[j+n]);
	}
	for(int k = 0;k<2*n;k++){
		cout << result[k] << " ";
	}
	return 0;
	
}