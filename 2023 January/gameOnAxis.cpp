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

int T, N, numOnPath;
vb willEnd, visited;
vi connect;
int invalid;
int pathLength;
int runInvalid;

void initPath(int a, vi& graph){
    if(a < 0 || a >= N || visited[a]){
        return;
    } else {
        visited[a] = true;
        numOnPath++;
        if(willEnd[a]){
            invalid += numOnPath;
            runInvalid += connect[a];
            invalid += runInvalid + 1;
        }
        initPath(graph[a], graph);
    }
}

bool dfs(int a, vi& graph) {
    if(a < 0 || a >= N){
        return true;
    }
    if(visited[a]){
        connect[a]+=pathLength;
        return willEnd[a];
    }
    // cout << a << ' ';
    visited[a] = true;
    pathLength++;
    willEnd[a] = dfs(graph[a], graph);
    return willEnd[a];
}

void solve(){
    cin >> N; vi graph; graph.rsz(N); willEnd.rsz(N); fill(all(willEnd), false); visited.rsz(N); fill(all(visited), false); connect.rsz(N); fill(all(connect), 0);
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        graph[i] = i + a;
    }
    for (int i = 0; i < N; i++)
    {
        // cout << i << endl;
        if(!visited[i]){
            pathLength = 0;
            dfs(i, graph);
        }
    }
    // cout << "works" << endl;
    fill(all(visited), false); numOnPath = 0;
    invalid = 0; runInvalid = 0;
    initPath(0, graph);
    int invalids = 0;
    for (int i = 0; i < sz(willEnd); i++)
    {
        // cout << willEnd[i] << " ";
        if(!willEnd[i]){
            invalids++;
        }
    }
    invalids *= numOnPath;
    invalids += invalid;
    ll total = 2*N + 1; total *= N;
    cout << total - invalids << endl;
}

int main(){
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve();
    }
    
}