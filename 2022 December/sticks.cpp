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

vi arr;

int N;
int main(){
    cin >> N;
    arr.rsz(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    int mid = arr[sz(arr)/2];
    ll cost = 0;
    for (int i = 0; i < sz(arr); i++)
    {
        cost += abs(arr[i] - mid);
    }
    
    cout << cost;
}