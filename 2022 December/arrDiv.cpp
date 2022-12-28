#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <climits>
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

int N, K;
vll arr;

bool works(ll a){
    ll sum = 0;
    ll subArrs = 1, index = 0;
    while(index < sz(arr)){
        if(arr[index] > a){
            return false;
        }
        sum += arr[index];
        if(sum > a){
            subArrs++;
            sum = arr[index];
        }
        index++;
        if(subArrs > K){
            return false;
        }
    }
    // subArrs++;
    // cout << endl << subArrs << endl;
    return !(subArrs > K);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    arr.rsz(N);
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    
    ll lo = 0, hi = pow(10, 15);
    while(lo < hi){
        ll mid = (lo + hi)/2;
        // cout << mid << endl;
        if(works(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo;
    // cout << works(8);
}