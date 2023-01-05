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

int N;
vi arr;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a; arr.pb(a);
    }
    int l = 0, r = 1;
    int maxSum = 0;
    int sum = arr[l];
    set<int> inInterval; inInterval.insert(arr[l]);
    while(r < sz(arr)){
        maxSum = max(maxSum, sum - *inInterval.rbegin());
        sum += arr[r];
        inInterval.insert(arr[r]);
        if(sum <= 0){
            if(r == sz(arr) - 1){
                break;
            }
            l = r + 1;
            r+=2;
            inInterval.clear();
            sum = arr[l]; inInterval.insert(arr[l]);
        } else {
            r++;
        }
    }
    maxSum = max(maxSum, sum - *inInterval.rbegin());
    cout << maxSum;
}