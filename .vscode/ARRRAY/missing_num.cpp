#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n - 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = ans ^ i;
    }

    for (int x : arr) {
        ans = ans ^ x;
    }

    cout << ans;

    return 0;
}