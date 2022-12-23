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
vector<set<int> > adjLists;
vi vals;
vb vis;

int DFS(int a){
    if(vis[a]){
        return 0;
    } else {
        vis[a] = true;
        int sum = 1;
        for(auto a : adjLists[a]){
            sum += DFS(a);
        }
        vals[a] = sum - 1;
        return sum;
    }
}

int main() {
    cin >> N;
    adjLists.rsz(N);
    vis.rsz(N);
    vals.rsz(N);
    fill(all(vals), -1);
    for (int i = 1; i < N; i++)
    {  
        int a; cin >> a; a--;
        adjLists[a].insert(i);
        // adjLists[0].insert(i);
    }
    for (int i = 0; i < sz(adjLists); i++)
    {
        if(vals[i] == - 1){
            cout << DFS(i) - 1 << " ";
            fill(all(vis), false);
        } else {
            cout << vals[i] << " ";
        }
    }
}