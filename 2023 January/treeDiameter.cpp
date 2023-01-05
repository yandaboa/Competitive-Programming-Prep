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

int N;
vvi adj;
vi arrToLeaf;

int toLeaf(int a, int fa){
    int maxV = 0;
    if(arrToLeaf[a] != 0){
        return arrToLeaf[a];
    }
    for (int i = 0; i < sz(adj[a]); i++)
    {
        if(fa != adj[a][i]){
            maxV = max(maxV, toLeaf(adj[a][i], a) + 1);
        }
    }
    arrToLeaf[a] = maxV;
    return maxV;
}

int maxLength(int a, int n){
    priority_queue<int> lengths;
    for (int i = 0; i < sz(adj[a]); i++)
    {
        if(adj[a][i] != n){
            lengths.push(toLeaf(adj[a][i], a) + 1);
        }
        // lengths.push(toLeaf(adj[a][i], a) + 1);

    }
    int ans = 0, i = 0;
    while(!lengths.empty() && i < 2){
        ans += lengths.top(); lengths.pop();
        i++;
    }
    cout << a << " " << ans << endl;
    for(auto b : adj[a]){
        if(b != n){
            ans = max(ans, maxLength(b, a));
        }
    }
    return ans;
}

int main(){ 
    cin >> N; adj.rsz(N); arrToLeaf.rsz(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int maxDist = 0;
    cout << maxLength(0, -1);
}