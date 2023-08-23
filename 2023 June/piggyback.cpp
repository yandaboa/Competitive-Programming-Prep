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

int b[40000], e[40000], p[40000];
vvi adjList;

ll bVal, eVal, pVal, N, M;

void BFS(int a, int (&arr)[40000]){
    queue<pair<int, int> > q;
    q.push(mp(a, 1));

    while(!q.empty()){
        pair<int, int> curr = q.front(); q.pop();
        if(arr[curr.f] == 0){
            arr[curr.f] = curr.s;
            for (int i = 0; i < sz(adjList[curr.f]); i++)
            {
                q.push(mp(adjList[curr.f][i], curr.s + 1));
            }
        }
    }
}

int main(){
    ifstream input("piggyback.in");
    ofstream output("piggyback.out");

    input >> bVal >> eVal >> pVal >> N >> M;
    adjList.rsz(N);
    for (int i = 0; i < M; i++)
    {
        int a, b; input >> a >> b; a--; b--;
        adjList[a].pb(b); adjList[b].pb(a);
    }
    BFS(0, b);
    BFS(1, e);
    BFS(N - 1, p);

    ll maxV = __LONG_LONG_MAX__;
    for (int i = 0; i < N; i++)
    {
        maxV = min(maxV, bVal*(b[i]-1) + eVal*(e[i] - 1) + pVal*(p[i] - 1));
    }
    output << maxV;
}