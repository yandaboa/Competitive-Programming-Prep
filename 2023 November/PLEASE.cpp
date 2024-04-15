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
 
int N, M;
vector<vector<pair<int, int > > > adjList;
vb visited;
vector<vector<int> > depth;
queue<pair<int, vector<int> > > q;

void BFS(int a, vi b){
    // cout << a << ":" << endl;
    // cout << sz(b) << endl;
    // for(int i = 0; i < sz(b); i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    if(sz(b) == 0){

    } else if(sz(depth[a]) == 0){
        depth[a] = b;
    } else if(sz(depth[a]) != 0 && sz(depth[a]) == sz(b)){
        // cout << "here";
        bool bSmaller = false;
        for(int i = 0; i < sz(b); i++){
            if(depth[a][i] > b[i]){
                bSmaller = true;
                break;
            }
        }
        if(bSmaller){
            depth[a] = b;
        }
    } else if (sz(b) > sz(depth[a])){
        // cout << "hi";
        depth[a] = b;
    }
    for(int i = 0; i < sz(adjList[a]); i++){
        b.pb(adjList[a][i].s);
        q.push(mp(adjList[a][i].f, b));
    }
    b.clear();
}

int main(){
    cin >> N >> M; adjList.rsz(N); depth.rsz(N);
    for (int i = 0; i < M; i++)
    {
        int a, b, l; cin >> a >> b >> l; a--; b--;
        adjList[a].pb(mp(b, l));
    }

    for(int i = 0; i < sz(adjList); i++){
        for(int j = 0; j < sz(adjList[i]); j++){
            // cout << i + 1 << " " << adjList[i][j].f + 1<< " " << adjList[i][j].s << endl;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < sz(adjList[i]); j++){
            vi curr; curr.pb(adjList[i][j].s);
            q.push(mp(adjList[i][j].f, curr));
        }
        while(sz(q) > 0){
            BFS(q.front().f, q.front().s);
            q.pop();
        }
        int maxL = 0, maxI = -1;
        for(int j = 0; j < N; j++){
            if(sz(depth[j]) > maxL){
                maxI = j;
                maxL = sz(depth[j]);
            }
        }
        if(maxL == 0){
            cout << 0 << " " << 0 << endl;
            continue;
        }
        // cout << sz(depth[maxI]) << endl;
        ll sm = 0;
        for(int j = 0; j < sz(depth[maxI]); j++){
            sm += depth[maxI][j];
        }
        cout << maxL << " " << sm << endl;
        depth.clear();
        depth.rsz(N);
    }

    // for(int i = 0; i < sz(starts); i++){
    //     if(!visited[starts[i]]){
    //         DFS(starts[i], -1);
    //     }
    // }
    // for (int i = 0; i < N; i++)
    // {
    //     cout << depth[i] << " ";
    // }
    
}

