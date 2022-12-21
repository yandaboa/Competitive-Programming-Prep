#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>
#include <set>
#include <fstream>
#include <string>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

using namespace std;

long long N, M, minX, maxX, minY, maxY;
vector<pair<ll, ll> > cowCoords;
vector<vi> adjList;
vector<bool> visited;

void DFS(int a){
    if(visited[a]){
        return;
    } else {
        visited[a] = true;
        minX = min(minX, cowCoords[a].f);
        maxX = max(maxX, cowCoords[a].f);
        minY = min(minY, cowCoords[a].s);
        maxY = max(maxY, cowCoords[a].s);
        // cout << cowCoords[a].f << "," << cowCoords[a].s << endl;
        for(int i = 0; i < adjList[a].size(); i++){
            DFS(adjList[a][i]);
        }
    }
}

int main(){
    ifstream input("fenceplan.in");
    ofstream output("fenceplan.out");

    input >> N >> M;
    minX = LONG_MAX;
    maxX = LONG_MIN;
    minY = LONG_MAX;
    maxY = LONG_MIN;
    for(ll i = 0, x, y; i < N; i++){
        input >> x >> y;
        cowCoords.pb(mp(x, y));
        cout << x << "," << y;
    }
    adjList.rsz(N);
    for(ll i = 0, a, b; i < M; i++){
        input >> a >> b;
        adjList[a - 1].pb(b - 1);
        adjList[b - 1].pb(a - 1);
    }

    visited.rsz(N);
    long long smallestPerim = LONG_MAX;
    for(ll i = 0; i < N; i++){
        if(!visited[i]){
            // cout << endl;
            DFS(i);
            // cout << maxX << " " << minX << " " << maxY << " " << minY << endl;
            // cout << endl;
            smallestPerim = min(smallestPerim, 2*(maxX - minX) + 2*(maxY - minY));
            minX = LONG_MAX;
            maxX = LONG_MIN;
            minY = LONG_MAX;
            maxY = LONG_MIN;
        }
    }
    output << smallestPerim;
}