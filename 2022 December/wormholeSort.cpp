#include <iostream>
#include <vector>
#include <limits>
#include <climits>
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

int N, M;
vi cows, widths;
vector<vpi> adjList;
vector<vi> connectedGraph;
vb vis;
set<int> visLocations, visCows;
bool different;

void connect(long long a){
    vi temp;
    fill(all(connectedGraph), temp);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < adjList[i].size(); j++)
        {
            if(adjList[i][j].s >= a){
                connectedGraph[i].pb(adjList[i][j].f);
            }
        }
    }
}

void DFS(int a){
    if(vis[a]){
        return;
    } else {
        visLocations.insert(a);
        visCows.insert(cows[a]);
        vis[a] = true;
        for (int i = 0; i < connectedGraph[a].size(); i++)
        {
            DFS(connectedGraph[a][i]);
        }
    }
}

bool check(){
    fill(all(vis), false);
    for (int i = 0; i < sz(vis); i++)
    {
        if(!vis[i]){
            DFS(i);
            for(set<int>::iterator itr = visLocations.begin(); itr != visLocations.end(); ++itr){
                // cout << "app" << *itr << " " << visCows.count(*itr) << endl;
                if(visCows.count(*itr) == 0){
                    return false;
                }
            }
            visCows.clear();
            visLocations.clear();
        }
    }
    return true;
    
}

int main(){

    ifstream input("wormsort.in");
    ofstream output("wormsort.out");
    input >> N >> M;
    vis.rsz(N);
    connectedGraph.rsz(N);
    for (int i = 0; i < N; i++)
    {
        int a;
        input >> a;
        cows.pb(a - 1);
    }

    adjList.resize(N);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        input >> a >> b >> c;
        a--;
        b--;
        adjList[a].pb(mp(b, c));
        adjList[b].pb(mp(a, c));
    }
    
    long long lo = 0, hi = pow(10, 9);
    while(lo < hi){
        long long mid = (lo + hi + 1)/2;
        connect(mid);
        if(check()){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    if(lo == pow(10, 9)){
        output << -1;
    } else {
        output << lo;
    }
}