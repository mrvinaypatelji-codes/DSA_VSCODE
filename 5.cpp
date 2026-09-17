#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>nums(n);
	for(int i = 0; i<n; i++) {
		cin >> nums[i];
	}
	long xor1 = 0;
	for(int i = 0; i<n; i++) {
		xor1 = xor1^nums[i];
	}
	int rightmost = xor1 & (-xor1);
	int a = 0,b = 0;
	for(int i = 0; i<n; i++) {
		if(rightmost & nums[i]) {
			b = b^nums[i];
		} else {
			a = a^nums[i];
		}
	}
//	return a << b;
	cout << a << " " << b;
	return 0;
}