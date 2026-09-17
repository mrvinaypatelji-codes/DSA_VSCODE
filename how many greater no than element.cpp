#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int>nums(n,0);
	for(int i = 0;i<n;i++){
		cin >> nums[i];
	}
	
	vector<int>result;
	int count = 0;
	for(int i = 0;i<n;i++){
		int temp = nums[i];
		for(int j = 0;j<n;j++){
			if(temp > nums[j]){
				count++;
			}
		}
		result.push_back(count);
		count = 0;
	}
	for(int k = 0;k<result.size();k++){
		cout << result[k] << " ";
	}
	return 0;
}