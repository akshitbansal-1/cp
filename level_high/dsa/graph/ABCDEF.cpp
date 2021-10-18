//https://www.spoj.com/problems/ABCPATH/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v;
int h, w;
int dfs(int i, int j, vector<vector<int> > &vis, char prev) {
    if (i >= h || i < 0 || j >= w || j < 0 || v[i][j] != prev + 1) return 0;
    if (vis[i][j] != 1) return vis[i][j];
    // cout<<v[i][j];
    vector<int> v1;
    v1.push_back(dfs(i + 1, j, vis, v[i][j]));
    v1.push_back(dfs(i, j + 1, vis, v[i][j]));
    v1.push_back(dfs(i - 1, j, vis, v[i][j]));
    v1.push_back(dfs(i, j - 1, vis, v[i][j]));
    v1.push_back(dfs(i - 1, j - 1, vis, v[i][j]));
    v1.push_back(dfs(i + 1, j + 1, vis, v[i][j]));
    v1.push_back(dfs(i + 1, j - 1, vis, v[i][j]));
    v1.push_back(dfs(i - 1, j + 1, vis, v[i][j]));
    int x = *max_element(v1.begin(), v1.end());
    vis[i][j] = x + 1;
    return vis[i][j];
}
int main() {
    int i = 1;
    while (true) {
        cin>>h>>w;
        if (h == 0 && w == 0) break;
        v.assign(h, "");
        for (int i = 0; i < h; i++) {
            cin>>v[i];
        }
        vector<vector<int> > vis(h, vector<int>(w, 1));
        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (vis[i][j] == 1) {
                    dfs(i, j, vis, v[i][j] - 1);
                }
                if (v[i][j] == 'A')
                    ans = max(ans, vis[i][j]);
            }
        }
        cout<<"Case "<<i++<<": "<<ans<<endl;
    }
}