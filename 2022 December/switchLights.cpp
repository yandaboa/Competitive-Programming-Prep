#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
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

int N, M, needed, area;
vector<vector<bool> > rooms, vis;
vector<vector<vector<pair<int, int> > > > switches;

void floodfill(int a, int b){
    if(a < 0 || a >= N || b < 0 || b >= N || !rooms[a][b] || vis[a][b]){
        return;
    }
    vis[a][b] = true;
    area++;
    for (int i = 0; i < sz(switches[a][b]); i++)
    {
        auto pr = switches[a][b][i];
        rooms[pr.f][pr.s] = true;
    }
    if(sz(switches[a][b])){
        needed++;
    }
    switches[a][b].clear();
    floodfill(a + 1, b); floodfill(a, b + 1); floodfill(a - 1, b); floodfill(a, b - 1);
}

int main(){
    ifstream input("lightson.in");
    ofstream output("lightson.out");
    input >> N >> M; rooms.rsz(N); vis.rsz(N); switches.rsz(N);
    for(int i = 0; i < N ; i++){
        rooms[i].rsz(N);
        vis[i].rsz(N);
        switches[i].rsz(N);
        for (int j = 0; j < sz(switches[i]); j++)
        {
            vpi empty;
            switches[i][j] = empty;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c, d;
        input >> a >> b >> c >> d; a--; b--; c--; d--;
        switches[a][b].pb(mp(c, d));
    }
    needed = 1;
    rooms[0][0] = true; 
    area = 0;
    while(needed){
        floodfill(0, 0);
        for (int i = 0; i < sz(vis); i++)
        {
            fill(all(vis[i]), false);
        }
        needed--;
    }
    area = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(rooms[i][j]){
                area++;
            }
        }
        
    }
    
    output << area;
}