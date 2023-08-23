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

int H, W;
vector<vector<char> > ogGrid;
vvi numGrid, adjList;
int highest;
vector<pair<int, int> > connections;
stack<pair<int, pair<int, int> > > toExplore;
vi dist;


void traverse(char a, int b, int x, int y){
    if(x >= H || x < 0 || y >= W || y < 0 || numGrid[x][y] != 0 || ogGrid[x][y] == '.'){
        return;
    }
    if(ogGrid[x][y] != a){
        toExplore.push(mp(b, mp(x, y)));
        return;
    }
    numGrid[x][y] = b;
    traverse(a, b, x + 1, y);
    traverse(a, b, x, y + 1);
    traverse(a, b, x - 1, y);
    traverse(a, b, x, y - 1);
}

void BFS(int a, int b){
    dist[a] = b;
    for (int i = 0; i < sz(adjList[a]); i++)
    {
        if(dist[adjList[a][i]] == 0 || dist[adjList[a][i]] > b + 1){
            BFS(adjList[a][i], b + 1);
        }
    }
}

int main(){
    cin >> H >> W;
    ogGrid.rsz(H); numGrid.rsz(H);
    for (int i = 0; i < H; i++)
    {
        numGrid[i].rsz(W);
        string str; cin >> str;
        ogGrid[i].rsz(W);
        for (int j = 0; j < W; j++)
        {
            ogGrid[i][j] = str[j];
        }
    }
    highest = 1;
    traverse(ogGrid[0][0], highest, 0, 0);
    while(sz(toExplore) > 0){
        pair<int, pair<int, int> > curr = toExplore.top(); toExplore.pop();
        if(numGrid[curr.s.f][curr.s.s] == 0){
            highest++;
            connections.pb(mp(curr.f, highest));
            traverse(ogGrid[curr.s.f][curr.s.s], highest, curr.s.f, curr.s.s);
        }
    }

    // for (int i = 0; i < H; i++)
    // {
    //     for (int j = 0; j < W; j++)
    //     {
    //         cout << numGrid[i][j];
    //     }
    //     cout << endl;
        
    // }
    
    adjList.rsz(highest);
    for (int i = 0; i < sz(connections); i++)
    {
        adjList[connections[i].f - 1].pb(connections[i].s - 1);
        adjList[connections[i].s - 1].pb(connections[i].f - 1);
    }

    dist.rsz(highest);
    BFS(0, 1);

    int maxVal = -1;

    for (int i = 0; i < sz(dist); i++)
    {
        maxVal = max(maxVal, dist[i]);
    }
    cout << maxVal;
    

    // for (int i = 0; i < sz(adjList); i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < sz(adjList[i]); j++)
    //     {
    //         cout << adjList[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
}