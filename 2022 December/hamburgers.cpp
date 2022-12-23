//do a binary search and dont be a dumbass and do stupid brute force shit
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

vll req, have, prices;
ll amount;

bool work(ll a){
    vll need; need.rsz(3); ll amt = 0;
    for (int i = 0; i < 3; i++)
    {
        need[i] = req[i]*a;
        need[i] = max((ll)0, need[i] - have[i]);
        amt += need[i]*prices[i];
    }
    return !(amt > amount);
}

int main(){
    string str; cin >> str; req.rsz(3); have.rsz(3); prices.rsz(3);
    for (int i = 0; i < sz(str); i++)
    {
        if(str[i] == 'B'){
            req[0]++;
        } else if(str[i] == 'S'){
            req[1]++;
        } else {
            req[2]++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> have[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> prices[i];
    }
    cin >> amount;

    ll lo = 0, hi = pow(10, 13);
    while(lo < hi){
        ll mid = (lo + hi + 1)/2;
        if(work(mid)){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo;
}