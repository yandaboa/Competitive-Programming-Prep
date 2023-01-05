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

int N, M;
string str;
vector<vi> adj;
char pref;
int a, b;

bool DFS(int a, int fa, bool present){
    if(str[a] == pref){
        present = true;
    }
    if(a == b){
        if(present){
            return true;
        } else {
            return false;
        }
    }
    bool children = false;
    for (int i = 0; i < sz(adj[a]); i++)
    {
        if(adj[a][i] != fa){
            children = children || DFS(adj[a][i], a, present);
        }
    }
    return children;
}

int main(){
    ifstream input("milkvisits.in");
    ofstream output("milkvisits.out");
    input >> N >> M >> str;
    adj.rsz(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b; input >> a >> b ; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 0; i < M; i++)
    {
        input >> a >> b >> pref; a--; b--;
        if(DFS(a, -1, false)){
            output << "1";
        } else {
            output << "0";
        }
    }
    
}