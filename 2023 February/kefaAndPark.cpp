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
vi arr;
vvi edges;
vb visited;
int viable;

void DFS(int a, int cats, int maxConsecutive){
    if(visited[a]){
        return;
    }
    visited[a] = true;
    if(arr[a] == 0){
        cats = 0;
    } else {
        cats++;
    }
    maxConsecutive = max(maxConsecutive, cats);
    int children = 0;
    for (int i = 0; i < sz(edges[a]); i++)
    {
        if(!visited[edges[a][i]]){
            DFS(edges[a][i], cats, maxConsecutive);
            children++;
        }
    }
    if(children == 0 && maxConsecutive <= M){
        // cout << a << endl;
        viable++;
    }
}

int main() {
    viable = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int a; cin >> a; arr.pb(a);
    }
    edges.rsz(N); visited.rsz(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    DFS(0, 0, 0);
    // for (int i = 0; i < sz(visited); i++)
    // {
    //     cout << visited[i];
    // }
      
    cout << viable;
}