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
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int> >;
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

int N, Q;
vi parent, height;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 0){
        join(b, c);
    } else {
        if(find(b) == find(c)){
            cout << "1";
        } else {
            cout << "0";
        }
        cout << endl;
    }
}

int find(int a){
    if(parent[a] != a){
        parent[a] = find(parent[a]);
    }
    return parent[a];
}

void join(int a, int b){
    int rootA = find(a);
    int rootB = find(b);
    if(height[rootA] >= height[rootB]){
        parent[rootB] = rootA;
        height[rootA] = max(height[rootA], height[rootB] + 1);
    } else {
        parent[rootA] = rootB;
        height[rootB] = max(height[rootB], height[rootA] + 1);
    }
}

int main(){
    cin >> N >> Q;
    parent.rsz(N);
    height.rsz(N);
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
        height[i] = 0;
    }
    
    for (int i = 0; i < Q; i++)
    {
        solve();
    }
    
}