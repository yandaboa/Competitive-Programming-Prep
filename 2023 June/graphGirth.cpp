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
#include <queue>
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

int N, M;

vvi adjList;
int ans;
vector<bool> visited;
vi depth;

void BFS(int a){
    // cout << a << endl;
    queue<pair<int, int> > q;
    q.push(mp(a, a));
    depth[a] = -1;
    while(!q.empty()){
        pair<int, int> curr = q.front(); q.pop();
        if(visited[curr.f]){
            // cout << curr.f << " " << curr.s << " " << depth[curr.f] << " " << depth[curr.s] << endl;
            ans = min(ans, depth[curr.f] + depth[curr.s] + 1);
            continue;
        }
        visited[curr.f] = true;
        depth[curr.f] = depth[curr.s] + 1;
        for (int i = 0; i < sz(adjList[curr.f]); i++)
        {
            if(adjList[curr.f][i] != curr.s){
                q.push(mp(adjList[curr.f][i], curr.f));
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;

    adjList.rsz(N);
    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    ans = INT_MAX;

    visited.rsz(N);
    depth.rsz(N);
    for (int i = 0; i < N; i++)
    {
        fill(all(visited), false);
        fill(all(depth), 0);
        BFS(i);
        // for (int i = 0; i < sz(depth); i++)
        //     {
        //         cout << depth[i] << endl;
        //     }
    }

    
    if(ans == INT_MAX){
        cout << -1;
    } else {
        cout << ans;
    }
}