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

int N, steps;
vvi arr;
vb visited;

void DFS(int a){
    visited[a] = true;
    int counter = 1, neighbors = 0;
    for (int i = 0; i < sz(arr[a]); i++)
    {
        if(!visited[arr[a][i]]){
            DFS(arr[a][i]);
            neighbors++;
        }
    }
    steps += neighbors;
    while(counter < neighbors + 1){
        counter *= 2;
        steps++;
    }
}

int main(){
    cin >> N; arr.rsz(N); steps = 0; visited.rsz(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b; cin >> a >> b;
        arr[a - 1].pb(b - 1);
        arr[b - 1].pb(a - 1);
    }
    DFS(0);
    cout << steps;
    return 0;
}