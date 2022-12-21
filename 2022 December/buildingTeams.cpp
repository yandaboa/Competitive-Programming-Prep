#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

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
vvi adjList;
vb vis;
bool possible;
vi team;

void DFS(int a, int tm){
    if(vis[a]){
        return;
    } else {
        vis[a] = true;
        team[a] = tm;
        for (int i = 0; i < adjList[a].size(); i++)
        {
            if(team[adjList[a][i]] != min(1, 1 - tm) && team[adjList[a][i]] != 2){
                possible = false;
            }
            DFS(adjList[a][i], min(1, 1 - tm));
        }
    }
}

int main(){
    cin >> N >> M;
    adjList.rsz(N);
    possible = true;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    vis.rsz(N);
    team.rsz(N);
    fill(all(team), 2);
    for (int i = 0; i < N; i++)
    {
        if(!vis[i]){
            DFS(i, 1);
        }
    }
    if(possible){
        for (int i = 0; i < N; i++)
        {
            cout << team[i] + 1<< " ";
        }
        
    } else {
        cout << "IMPOSSIBLE";
    }
    
}