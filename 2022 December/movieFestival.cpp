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

int N, M;
multiset<pair<ll, ll> > movies;
multiset<ll> watchers;

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        ll start, end; cin >> start >> end;
        movies.insert(mp(end, start));
    }
    for (int i = 0; i < M; i++)
    {
        watchers.insert(0);
    }
    

    int watched = 0;
    while(sz(movies) > 0){
        pair<ll, ll> val = *(movies.begin());
        auto lessThan = watchers.upper_bound(val.s);
        if(lessThan == watchers.begin()){
            movies.erase(movies.find(val));
        } else {
            movies.erase(movies.find(val)); lessThan--;
            watchers.erase(watchers.find(*lessThan));
            watchers.insert(val.f);
            watched++;
        }
    }
    cout << watched;
}