#include <iostream>
#include <vector>
#include <limits>
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
//cin.tie(0)->sync_with_stdio(0);

int N;
vi ogBosses, newBosses;
vvi adjList, secondGraph;
vb visited;
bool hasCycle;
vi order;

void secondDFS(int a){
    if(visited[a]){
        return;
    } else {
        order.pb(a);
        visited[a] = true;
        for (int i = 0; i < sz(secondGraph[a]); i++)
        {
            secondDFS(secondGraph[a][i]);
        }
    }
}

void DFS(int a){
    if(visited[a]){
        hasCycle = true;
        return;
    } else {
        // order.pb(a);
        visited[a] = true;
        for (int i = 0; i < sz(adjList[a]); i++)
        {
            DFS(adjList[a][i]);
            
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N; ogBosses.rsz(N); newBosses.rsz(N);
    int ogInd; secondGraph.rsz(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> ogBosses[i];
        if(ogBosses[i] == -1){
            ogInd = i + 1;
        } else {
            secondGraph[ogBosses[i]].pb(i + 1);
        }
    }
    adjList.rsz(N + 1);
    int newInd;
    for (int i = 0; i < N; i++)
    {
        cin >> newBosses[i];
        if(newBosses[i] != -1){
            adjList[newBosses[i]].pb(i + 1);
        } else {
            newInd = i + 1;
        }
    }
    hasCycle = false;
    visited.rsz(N + 1);
    DFS(newInd);
    if(hasCycle || ogInd != newInd){
        cout << -1;
    }

    fill(all(visited), false);
    secondDFS(ogInd);
    int changed = 0;
    string changes = "";
    for (int i = 0; i < sz(order); i++)
    {
        int val = order[i] - 1;
        if(ogBosses[val] != newBosses[val]){
            changed++;
        }
    }
    cout << changed << endl;
    for (int i = 0; i < sz(order); i++)
    {
        int val = order[i] - 1;
        if(ogBosses[val] != newBosses[val]){
            cout << val + 1 << " " << newBosses[val] << endl;
        }
    }
}