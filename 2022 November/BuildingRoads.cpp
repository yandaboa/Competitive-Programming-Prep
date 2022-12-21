#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>
#include <set>
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

void setIO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int cities, roads;
vector<bool> visited;


void DFS(int a, vi adjList[]){
    if(visited[a]){
        return;
    } else {
        visited[a] = true;
        for (int i = 0; i < adjList[a].size(); i++)
        {
            DFS(adjList[a][i], adjList);
        }
        
    }
}

int main(){
    setIO();
    cin >> cities >> roads;
    vi roadLists[cities];
    visited.rsz(cities);
    for (int i = 0; i < roads; i++)
    {
        int a, b;
        cin >> a >> b;
        roadLists[a - 1].pb(b - 1);
        roadLists[b - 1].pb(a - 1);
    }
    int count = 0;
    vi comps;
    for(int i = 0; i < cities; i++){
        if(!visited[i]){
            DFS(i, roadLists);
            count++;
            comps.pb(i);
        }
    }
    cout << count - 1 << endl;
    for (int i = 0; i < sz(comps) - 1; i++)
    {
        cout << comps[i] + 1 << " " << comps[i + 1] + 1 << endl;
    }
    
}