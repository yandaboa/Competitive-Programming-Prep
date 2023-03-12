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

int T, N;

void solve(){
    cin >> N;
    vi arr; arr.rsz(N);
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a; a = abs(a); a--;
        arr[a]++;
    }
    int totalLikes = 0, totalRemoves = 0;
    for (int i = 0; i < sz(arr); i++)
    {
        if(arr[i] > 0){
            totalLikes++;
        }
        if(arr[i] == 2){
            totalRemoves++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if(i + 1 <= totalLikes){
            cout << i + 1 << " ";
        } else {
            cout << totalLikes - (i - totalLikes + 1) << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        int base = i%2==0 && (i + 1) < totalRemoves*2? 1 : 0;
        int leftOver = (N - i - 1) - (totalLikes - totalRemoves);
        if(leftOver < 0){
            base += abs(leftOver);
        }
        cout << base << ' ';
    }
    
    cout << endl;
}

int main(){
    cin >> T;
    while(T){
        solve();
        T--;
    }
}