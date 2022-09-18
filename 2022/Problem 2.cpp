#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e6+5;
int n, b[M], b2[M], p[M], p2[M], u[M], lft[M], rit[M], buy[M]; ll ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> b[i]; b2[i] = b[i]; }
    for(int i=1; i<n; i++) { cin >> p[i]; p2[i] = p[i]; }
    for(int i=1; i<n; i++) cin >> u[i];
    for(int i=1; i<n; i++) {
        int num = min(p[i], b[i]); p[i]-=num; b[i]-=num;
        num = min(p[i], u[i]); p[i]-=num;
        num = min(p[i], b[i+1]); p[i]-=num; b[i+1]-=num;
        if(p[i] > 0) { cout << "NO\n"; return 0;}
    }
    memcpy(b, b2, sizeof(b)); memcpy(p, p2, sizeof(p));
    for(int i=1; i<n; i++) {
        int num = min(p[i], b[i]); p[i]-=num; b[i]-=num;  lft[i] = num;
        num = min(p[i], b[i+1]); p[i]-=num; b[i+1]-=num;  rit[i] = num;
        ans += p[i];    buy[i] = p[i];
    }
    memcpy(b, b2, sizeof(b)); memcpy(p, p2, sizeof(p));
    for(int i=n-1; i>=1; i--) {
        if(buy[i] > u[i]){
            int dif = buy[i] - u[i]; buy[i] -= dif; lft[i] += dif;
            buy[i-1] += dif; rit[i-1] -= dif;
        }
    }
    cout << "YES\n" << ans << "\n";
    for(int i=1; i<n; i++) cout << lft[i] << " " << buy[i] << " " << rit[i] << "\n";
}
