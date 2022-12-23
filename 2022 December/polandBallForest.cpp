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

int N;
vb visited;
vvi adjList;

void DFS(int a){
    if(visited[a]){
        return;
    } else {
        visited[a] = true;
        for (int i = 0; i < sz(adjList[a]); i++)
        {
            DFS(adjList[a][i]);
        }
        
    }
}

int main(){
    cin >> N;
    adjList.rsz(N);
    visited.rsz(N);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a; a--;
        adjList[i].pb(a);
        adjList[a].pb(i);
    }
    int trees = 0;
    for (int i = 0; i < sz(visited); i++)
    {
        if(!visited[i]){
            trees++;
            DFS(i);
        }
    }
    cout << trees;
}