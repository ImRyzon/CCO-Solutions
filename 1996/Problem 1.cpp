#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define vt vector
#define pb push_back
#define emp emplace
#define popf pop_front
#define popb pop_back
#define mp make_pair
#define umap unordered_map
#define fill(x, a) memset(x, a, sizeof(x))
#define all(c) (c).begin(), (c).end()

void solve() {
    int l, cnt = 0;
    cin >> l;
    int train[l];
    for (int i = 0; i < l; i++) cin >> train[i];
    for (int i = 0; i < l - 1; i++) {
        for (int j = 0; j < l - i - 1; j++) {
            if (train[j] > train[j+1]) {
                swap(train[j], train[j+1]);
                cnt++;
            }
        }
    }
    cout << "Optimal train swapping takes " << cnt << " swaps." << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TEST_CASES;
    cin >> TEST_CASES;
    for (int i = 1; i <= TEST_CASES; i++) solve();
}
