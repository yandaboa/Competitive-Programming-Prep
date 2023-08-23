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

int N, Q;

vi parent;

int find(int a){
    if(parent[a] != a){
        parent[a] = find(parent[a]);
    }
    return parent[a];
}

void join(int a, int b){
    
}

int main(){
    cin >> N >> Q;
    parent.rsz(N);
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }
    
}