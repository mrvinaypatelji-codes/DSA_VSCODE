#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
    	cin >> nums[i];
	}

    vector<int> ans;

    for(int i = 0; i < n; i++) {
        int x = abs(nums[i]);
        nums[x - 1] = -abs(nums[x - 1]);
    }

    for(int i = 0; i < n; i++) {
        if(nums[i] > 0) {
            ans.push_back(i + 1);
        }
    }

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}