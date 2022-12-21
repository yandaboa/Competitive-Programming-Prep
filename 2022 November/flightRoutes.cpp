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

int n, m, alreadyVisited, missed, second;
vector<vi> adjList, adjListReverse;
vector<bool> visited;
bool connected = true;

void DFS(int a){
    if(visited[a]){
        return;
    } else {
        visited[a] = true;
        // cout << a << " ";
        for (int i = 0; i < adjList[a].size(); i++)
        {
            DFS(adjList[a][i]);
        }
    }
}

void DFSReverse(int a){
    if(visited[a]){
        return;
    } else {
        visited[a] = true;
        // cout << a << " ";
        for (int i = 0; i < adjListReverse[a].size(); i++)
        {
            DFSReverse(adjListReverse[a][i]);
        }
    }
}


int main(){
    cin >> n >> m;
    alreadyVisited = 0;
    adjList.rsz(n);
    adjListReverse.rsz(n);
    visited.rsz(n);
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        adjList[a - 1].pb(b - 1);
        adjListReverse[b - 1].pb(a - 1);
    }

    DFS(0);
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            cout << "NO" << endl;
            cout << 1 << " " << i + 1;
            return 0;
        }
    }
    
    fill(all(visited), false);
    DFSReverse(0);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << i + 1 << " " << 1;
            return 0;
        }
    }
    cout << "YES";

    // bool all = true;
    // for (int i = 0; i < n; i++)
    // {
    //     if(!canBe[i]){
    //         all=false;
    //         cout << "NO" << endl << 1 << " " << i + 1; 
    //         break;
    //     }
    // }
    
}