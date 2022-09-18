#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, g, a[11][11]; unordered_map<int, int> mp; char c; ll ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> g;
    for(int k=0; k<g; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> c;  a[i][j] = c == 'R';
            }
        }
        for(int i=0; i+1<n; i++){
            for(int j=0; j+1<n; j++){
                if(a[i][j]){
                    a[i][j]^=1; a[i+1][j]^=1; a[i][j+1]^=1; a[i+1][j+1]^=1;
                }
            }
        }
        int mask = 0;
        for(int i=0; i<n; i++) mask = mask<<1 | a[i][n-1];
        for(int i=0; i<n; i++) mask = mask<<1 | a[n-1][i];
        mp[mask]++;
    }
    for(auto e : mp){
        ans += 1LL*e.second*(e.second - 1)/2;
    }
    cout << ans << endl;
}
