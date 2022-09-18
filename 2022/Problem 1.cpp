#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 3003;
int N, K, Q, vis[MM], ans[MM], a[MM]; multiset<int> adj[MM]; bool cycle;
void dfs(int u){
    vis[u] = 1;
    for(int v : adj[u]){
        if(vis[v] == 1) { cycle = true; return; }
        if(!vis[v]) dfs(v);
    }
    vis[u] = 2;
}
bool find_cycle() {
    fill(vis, vis+K+1, 0); cycle = 0;
    for(int i=1; i<=K; i++){
        if(!vis[i]) dfs(i);
        if(cycle) return 1;
    }
    return 0;
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K >> Q;
    for(int i=1; i<=N; i++) cin >> a[i];
    for(int l=1, r=1; l<=N; l++) {
        for( ; r<=N; r++) {
            if(find_cycle()) break;
            adj[a[r + (r&1)]].insert(a[r + (r&1 ^ 1)]);
        }
        int cur = a[l+(l&1)], nxt = a[l+(l&1^1)];
        ans[l] = r;  adj[cur].erase(adj[cur].find(nxt));
    }
    for(int i=1, x, y; i<=Q; i++){
        cin >> x >> y;
        cout << (y < ans[x]? "YES\n" : "NO\n");
    }
}
