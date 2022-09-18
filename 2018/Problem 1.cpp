#include <bits/stdc++.h>
using namespace std;
int N, dp[1001][1001], a[1001], b[1001]; string g, h;
int main(){
    cin >> N >> g;
    for(int i=1; i<=N; i++) cin >> a[i];
    cin >> h;
    for(int i=1; i<=N; i++) cin >> b[i];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(g[i-1]!=h[j-1] && ( (g[i-1]=='W' && a[i] > b[j]) || (g[i-1]=='L' && a[i] < b[j]) ) ){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i] + b[j]);
            }
        }
    }
    cout << dp[N][N] << "\n";
}
