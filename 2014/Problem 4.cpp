#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define vt vector
#define pii pair<int, int>
#define pll pair<long, long>
#define pb push_back
#define eb emplace_back
#define emp emplace
#define popf pop_front
#define popb pop_back
#define mp make_pair
#define umap unordered_map
#define fill(x, a) memset(x, a, sizeof(x))
#define all(c) (c).begin(), (c).end()

void solve() {
    int n, p, cnt = 1, fuel = 0;
    vt<pii> planets;
    cin >> n >> p;
    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;
        if (i == p) {fuel += a; continue;};
        if (b > a) continue;
        if (fuel >= b) {fuel += (a-b); ++cnt;}
        else planets.eb(b, a);
    }
    sort(all(planets));
    for (int i = 0; i < planets.size(); i++) {
        if (fuel < planets[i].first) break;
        fuel += (planets[i].second - planets[i].first);
        ++cnt;
    }
    cout << fuel << endl << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TEST_CASES = 1;
    for (int i = 1; i <= TEST_CASES; i++) solve();
}
