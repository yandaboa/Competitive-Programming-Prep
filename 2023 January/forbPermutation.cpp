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

int T;

void solve(){
    int N, M, D; cin >> N >> M >> D;
    int pos[N + 1];
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a; pos[a] = i;
    }
    int arr[M];
    for (int i = 0; i < M; i++)
    {
        cin >> arr[i];
    }
    int minOps = INT_MAX;
    for (int i = 0; i < M - 1; i++)
    {
        if(pos[arr[i + 1]] < pos[arr[i]] || pos[arr[i]] + D < pos[arr[i + 1]]){
            cout << 0 << endl;
            return;
        }
        int temp1 = pos[arr[i + 1]] - pos[arr[i]];
        int temp2;
        if(pos[arr[i]] + D < N - 1){
            temp2 = pos[arr[i]] + D - pos[arr[i + 1]] + 1;
        } else {
            if(D + 1 < N) {
                temp2 = D - (pos[arr[i + 1]] - pos[arr[i]]) + 1;
            } else {
                temp2 = INT_MAX;
            }
        }
        minOps = min(minOps, temp1);
        minOps = min(minOps, temp2);
    }
    cout << minOps << endl;
    return;
    
}

int main(){
    cin >> T;
    while(T){
        solve();
        T--;
    }
    return 0;
}