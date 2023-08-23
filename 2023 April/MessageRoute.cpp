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
#include <sstream>
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

int N, M;
vvi adjList;
vector<int> fastestReach, from;
queue<pair<int, pair<int, int> > > q;

void BFS(int last, int a, int plength){
    plength++;
    if(fastestReach[a] <= plength){
        return;
    }
    fastestReach[a] = plength;
    from[a] = last;
    for (int i = 0; i < sz(adjList[a]); i++)
    {
        q.push(mp(a, mp(adjList[a][i], plength)));
    }
}

vi sequence;

void DFS(int a){
    sequence.pb(a);
    if(from[a] == -1){
        return;
    }
    DFS(from[a]);
}

int main(){
    cin >> N >> M; adjList.rsz(N); fastestReach.rsz(N); fill(all(fastestReach), INT_MAX); from.rsz(N);

    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    BFS(-1, 0, 0);
    while(sz(q) > 0){
        pair<int, pair<int, int>> ne = q.front(); q.pop();
        // cout << ne.f << endl;
        BFS(ne.f, ne.s.f, ne.s.s);
    }
    if(fastestReach[N - 1] == INT_MAX){
        cout << "IMPOSSIBLE";
    } else {
        cout << fastestReach[N - 1] << endl;
        DFS(N - 1);
        for (int i = sz(sequence) - 1; i > -1; i--)
        {
            cout << sequence[i] + 1 << " ";
        }
        
    }
} 