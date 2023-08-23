#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <climits>
#include <string.h>
#include <fstream>
#include <stack>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi= vector<vector<int> >;
using vll = vector<long long>;
using vpi = vector<pair<int, int> >;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
//cin.tie(0)->sync_with_stdio(0);

int H, W;
vector<vector<char> > grid;
vvi depth;
int dx[4]{-1, 1, 0, 0}, dy[4]{0, 0, 1, -1};

int main(){
    cin >> H >> W;
    grid.rsz(H);
    depth.rsz(H);
    for (int i = 0; i < H; i++)
    {  
        grid[i].rsz(W);
        depth[i].rsz(W);
        string str; cin >> str;
        for (int j = 0; j < W; j++)
        {
            grid[i][j] = str[j];
        }
    }
    depth[0][0] = 1;
    deque<pair<int, int> > traverse;
    traverse.push_front(mp(0, 0));
    while(traverse.size() > 0){
        pair<int, int> curr = traverse.front(); traverse.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int x = curr.f + dx[i];
            int y = curr.s + dy[i];
            if(x < 0 || x >= H || y < 0 || y >= W){
                continue;
            }
            if(grid[x][y] == '.' || depth[x][y] != 0){
                continue;
            }
            if(grid[x][y] != grid[curr.f][curr.s]){
                depth[x][y] = depth[curr.f][curr.s] + 1;
                traverse.push_back(mp(x, y));
            } else {
                depth[x][y] = depth[curr.f][curr.s];
                traverse.push_front(mp(x, y));
            }
        }
    }

    int maxV = -1;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            maxV = max(depth[i][j], maxV);
        }
    }
    cout << maxV;

}