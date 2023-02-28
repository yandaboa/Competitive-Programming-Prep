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

int T, C, M, N;
vector<pair<pair<int, int>, int> > friends;
vector<pair<pair<int, int>, int> > cookiesGreater, muffinsGreater;

int c, m;

void balance(int a, int index){
    int lo = 1, hi = c;
    while(lo < hi){
        int mid = (lo + hi + 1)/2;
        if(mid*cookiesGreater[index].f.f + (a - mid)*cookiesGreater[index].f.s <= cookiesGreater[index].s){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    if (a - lo > M || lo*cookiesGreater[index].f.f + (a - lo)*cookiesGreater[index].f.s > cookiesGreater[index].s){
        c = -1;
    } else {
        c = lo;
        m = a - lo;
    }
}

bool check(){
    for (int i = 0; i < sz(muffinsGreater); i++)
    {
        if(c*muffinsGreater[i].f.f + m*muffinsGreater[i].f.s > muffinsGreater[i].s){
            // cout << "false: " << endl;
            return true;
        }
    }
    return false;
}

bool valid(int a){
    c = min(a - 1, C), m = a - c;
    for (int i = 0; i < sz(muffinsGreater); i++)
    {
        if(c*muffinsGreater[i].f.f + m*muffinsGreater[i].f.s > muffinsGreater[i].s){
            return false;
        }
    }
    for (int i = 0; i < sz(cookiesGreater); i++)
    {
        while(c*cookiesGreater[i].f.f + m*cookiesGreater[i].f.s > cookiesGreater[i].s){
            // cout << c << " " << m << endl;
            c--; m++;
            if(c == 0 || check() || m > M){
                return false;
            }
        }
    }
    // cout << c << " " << m << endl;
    return true;
}

void solve(){
    cin >> N >> C >> M;
    friends.clear(); muffinsGreater.clear(); cookiesGreater.clear();
    for (int i = 0; i < N; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        friends.pb(mp(mp(a, b), c));
    }
    for (int i = 0; i < sz(friends); i++)
    {
        if(friends[i].f.f >= friends[i].f.s){
            cookiesGreater.pb(friends[i]);
        } else {
            muffinsGreater.pb(friends[i]);
        }
    }
    // for(int i = 0; i < sz(cookiesGreater); i++){
    //     cout <<cookiesGreater[i].f.f << " " << cookiesGreater[i].f.s << " " << cookiesGreater[i].s << endl;
    // }
    // cout << endl;
    // for(int i = 0; i < sz(muffinsGreater); i++){
    //     cout << muffinsGreater[i].f.f << " " << muffinsGreater[i].f.s << " " << muffinsGreater[i].s << endl;
    // }
    // cout << endl;

    int lo = 2, hi = C + M;
    while(lo < hi){
        int mid = (lo + hi + 1)/2;
        // cout << lo << " " << hi << " " << mid << endl;
        if(valid(mid)){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << C + M - lo << endl;
    // cout << endl;
}

int main(){
    cin >> T;
    while(T){
        solve();
        T--;
    }
}