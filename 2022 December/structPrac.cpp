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

struct Edge {
    int from, to, weight;

    Edge(int a, int b, int w){
        from = a;
        to = b;
        weight = w;
    }

};
bool operator < (const Edge& x, const Edge& y) {
    if(x.weight == y.weight){
        return x.to < y.to;
    }
    return x.weight < y.weight;
}

int main(){
    int N; cin >> N; vector<Edge> edges;
    for (int i = 0; i < N; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.pb(Edge(a,b,w));
    }
    sort(all(edges));
    for(int i = 0; i < sz(edges); i++){
        Edge a = edges[i];
        cout << a.from << " -> " << a.to << " | " << a.weight << endl;
    }
}