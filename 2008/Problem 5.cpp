#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define vt vector
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define eb emplace_back
#define emp emplace
#define popf pop_front
#define popb pop_back
#define mp make_pair
#define umap unordered_map
#define fill(x, a) memset(x, a, sizeof(x))
#define all(c) (c).begin(), (c).end()
#define printArr(x) for (int i : (x)) cout << i << " "; cout << "\n"
#define sizeArr(t) (sizeof(t)/sizeof((t)[0]))
#define ell "\n"

void solve() {
    int n, total = 0, mosti = 0; cin >> n;
    vt<int> use; map<int,int> input;
    for (int i = 0, a, b; i < n; i ++) {
        cin >> a >> b; total += a * b;
        if (input.find(b) == input.end()) input[b] = a;
        else input[b] += a;
    }
    for (const auto &ent: input) {
        int b = ent.first, a = ent.second, nexta = a-(a & -a);
        while (nexta){
            use.push_back((a & -a)*b);
            a -= (a & -a);
            nexta = a-(a & -a);
        }
        for (int i2 = 0; pow(2,i2) < a; i2++) use.push_back((int)(pow(2,i2))*b);
        use.push_back(b);
    }
    bool p[total / 2 + 1]; fill(p, false); p[0]= true;
    for (int currentc : use) {
        for(int i2 = mosti + currentc ; i2 - currentc >= 0; --i2)
            if (i2 < total / 2 + 1 && p[i2 - currentc]) {p[i2]= true; mosti = max(mosti, i2);}
    }
    cout << abs(total - 2 * mosti) << ell;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TEST_CASES = 1;
    for (int i = 1; i <= TEST_CASES; i++) solve();
}
