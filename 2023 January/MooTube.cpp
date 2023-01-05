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

int N, Q;
int v, k;
int visited;
vector<vector<pi> > adj;

void DFS(int a, int fa){
    visited++;
    for (int i = 0; i < sz(adj[a]); i++)
    {
        if(adj[a][i].f != fa && adj[a][i].s >= k){
            DFS(adj[a][i].f, a);
        }
    }
}

int main(){
    ifstream input("mootube.in");
    ofstream output("mootube.out");
    input >> N >> Q;
    adj.rsz(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, w; input >> a >> b >> w; a--; b--;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    for (int i = 0; i < Q; i++)
    {
        input >> k >> v; v--;
        visited = 0;
        DFS(v, -1);
        output << visited - 1 << endl;
    }
}