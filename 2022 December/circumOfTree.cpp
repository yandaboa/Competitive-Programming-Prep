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

int N, longestL, endN;
vvi adjList;

void DFS(int a, int from, int leng){

    if(leng >= longestL){
        longestL = leng;
        endN = a;
    }
    for (int i = 0; i < sz(adjList[a]); i++) {
        if(adjList[a][i] != from){
            DFS(adjList[a][i], a, leng + 1);
        }
    }
}

int main(){
    cin >> N; adjList.rsz(N);
    longestL = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adjList[a].pb(b); adjList[b].pb(a);
    }
    DFS(0, -1, 0);
    DFS(endN, -1, 0);
    cout << 3*longestL;
}