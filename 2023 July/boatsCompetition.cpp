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

int T, N;

void solve(){
    cin >> N;
    vi arr;
    for (int j = 0; j < N; j++)
    {
        int a; cin >> a; arr.pb(a);
    }
    sort(all(arr));
    if(sz(arr) == 1){
        cout << 0 << endl;
        return;
    } 
    int largest = arr[sz(arr) - 1] + arr[sz(arr) - 2];
    int mostPaired = 0;
    for (int i = largest; i > 0; i--)
    {
        int counter = 0;
        int l = 0, r = sz(arr) - 1;
        while(l < r){
            if(arr[l] + arr[r] == i){
                counter++; l++; r--;
                continue;
            }
            if(arr[l] + arr[r] > i){
                r--; continue;
            }
            if(arr[l] + arr[r] < i){
                l++; continue;
            }
        }
        if(counter > mostPaired){
            mostPaired = counter;
        }
    }
    cout << mostPaired << endl;
    
}

int main(){
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve();
    }
    
}