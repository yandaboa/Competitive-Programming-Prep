// #include <iostream>
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

int N, K;

vi distB, distF;
vvi adjList;
vb visited;
int ans;

void DFS(int a){
    if(visited[a]){
        return;
    }
    if(distB[a] >= distF[a]){
        ans++;
        visited[a] = true;
        return;
    }
    visited[a] = true;
    for (int i = 0; i < sz(adjList[a]); i++)
    {
        DFS(adjList[a][i]);
    }
    
}

int main(){
    ifstream input("atlarge.in");
    ofstream output("atlarge.out");

    input >> N >> K; K--;

    adjList.rsz(N); distB.rsz(N); distF.rsz(N); visited.rsz(N);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b; input >> a >> b; a--; b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    queue<pair<int, int> > q;
    q.push(mp(K, 1));
    while(!q.empty()){
        pair<int, int> curr = q.front(); q.pop();
        if(distB[curr.f] != 0){
            continue;
        }
        distB[curr.f] = curr.s;
        for (int i = 0; i < sz(adjList[curr.f]); i++)
        {
            q.push(mp(adjList[curr.f][i], curr.s + 1));
        }
    }
    for (int i = 0; i < N; i++)
    {
        if(sz(adjList[i]) == 1){
            q.push(mp(i, 1));
        }
    }
    // cout << sz(q);
    while(!q.empty()){
        pair<int, int> curr = q.front(); q.pop();
        if(distF[curr.f] != 0){
            continue;
        }
        distF[curr.f] = curr.s;
        for (int i = 0; i < sz(adjList[curr.f]); i++)
        {
            q.push(mp(adjList[curr.f][i], curr.s + 1));
        }
    }
    ans = 0;
    DFS(K);
    output << ans;
}