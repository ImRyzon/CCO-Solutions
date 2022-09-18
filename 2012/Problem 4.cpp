#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MM = 1e5 + 1;
int dis[MM][81], len[MM];
int N, startX, startY, endX, endY;
bool isValid(int x, int y) {
    if (x < 1 || y < 1 || x > N || y > len[x]) return false;
    return !dis[x][y];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    scan(N);
    for (int i = 1; i <= N; i++) scan(len[i]);
    scan(startX); scan(startY); scan(endX); scan(endY);
    queue<pair<int, int>> q;
    q.push({startX, startY});
    dis[startX][startY] = 1;
    while (!q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();
        if (cell.first == endX && cell.second == endY) break;
        int adjX = cell.first, adjY = cell.second + 1;
        if (isValid(adjX, adjY)) {
            dis[adjX][adjY] = dis[cell.first][cell.second] + 1;
            q.push({adjX, adjY});
        } else if (cell.second == len[cell.first] && isValid(cell.first + 1, 1)) {
            dis[cell.first + 1][1] = dis[cell.first][cell.second] + 1;
            q.push({cell.first + 1, 1});
        }
        adjX = cell.first; adjY = cell.second - 1;
        if (isValid(adjX, adjY)) {
            dis[adjX][adjY] = dis[cell.first][cell.second] + 1;
            q.push({adjX, adjY});
        } else if (cell.second == 1 && isValid(cell.first - 1, len[cell.first - 1])) {
            dis[cell.first - 1][len[cell.first - 1]] = dis[cell.first][cell.second] + 1;
            q.push({cell.first - 1, len[cell.first - 1]});
        }
        adjX = cell.first - 1; adjY = cell.second;
        if (isValid(adjX, adjY)) {
            dis[adjX][adjY] = dis[cell.first][cell.second] + 1;
            q.push({adjX, adjY});
        } else if (cell.second > len[cell.first-1] && isValid(cell.first - 1, len[cell.first - 1])) {
            dis[cell.first - 1][len[cell.first - 1]] = dis[cell.first][cell.second] + 1;
            q.push({cell.first - 1, len[cell.first - 1]});
        }
        adjX = cell.first + 1; adjY = cell.second;
        if (isValid(adjX, adjY)) {
            dis[adjX][adjY] = dis[cell.first][cell.second] + 1;
            q.push({adjX, adjY});
        } else if (cell.second > len[cell.first + 1] && isValid(cell.first + 1, len[cell.first + 1])) {
            dis[cell.first + 1][len[cell.first + 1]] = dis[cell.first][cell.second] + 1;
            q.push({cell.first + 1, len[cell.first + 1]});
        }
    }
    printf("%d\n", dis[endX][endY] - 1);
}
