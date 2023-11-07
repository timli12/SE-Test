#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(int distance, const vector<int>& x, const vector<int>& y, int n, int m){
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && y[j] < x[i] - distance) {
            j++;
        }
        if (j >= m || y[j] > x[i] + distance) {
            return false;
        }
        j++;
    }
    return true;
}

int main(){
    int n, m;
    int l = 0, r = 1000000000, res = -1;
    cin >> n >> m;
    vector<int> x(n), y(m);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < m; i++) cin >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    while (l <= r){
        int mid = l + (r - l) / 2;
        if (isValid(mid, x, y, n, m)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
    return 0;
}
