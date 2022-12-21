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

//count number of components - each multiplies ways by 2
//multiple that by 2^x, x is number of pastures by themselves - no relationships
//if this doesn't satisfy all test cases, check for scenarios where answer is 0, impossible to plant pastures

int N, M, comps;
vvi adjList;
vb visited;

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
    ifstream input("revegetate.in");
    ofstream output("revegetate.out");
    input >> N >> M;
    adjList.rsz(N);
    visited.rsz(N);

    for (int i = 0; i < M; i++)
    {
        char s;
        int a, b;
        input >> s >> a >> b;
        a--;
        b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    for (int i = 0; i < sz(visited); i++)
    {
        if(!visited[i]){
            DFS(i);
            comps++;
        }
    }
    
    output << "1";
    for (int i = 0; i < comps; i++)
    {
        output << "0";
    }
}