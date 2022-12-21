#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <tuple>
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

int N;
multiset<pair<int, pair<int,int> > > guests;
vi roomAns;

int main(){
    cin >> N;
    roomAns.rsz(N);
    for (int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b; guests.insert(mp(a, mp(b, i)));
    }
    int room = 0;
    while(sz(guests) > 0){
        room++;
        auto ptr = guests.begin();
        vector<pair<int, pair<int, int> > > toErase;
        while(ptr != guests.end()){
            auto currGuest = *ptr;
            // cout << currGuest.f << " " << currGuest.s.f << " " << currGuest.s.s << endl;
            toErase.pb(currGuest);
            roomAns[currGuest.s.s] = room;
            auto search = mp(currGuest.s.f, mp(INT_MAX, INT_MAX));
            ptr = guests.upper_bound(search);
        }
        for (int i = 0; i < sz(toErase); i++)
        {
            guests.erase(guests.find(toErase[i]));
        }
    }
    cout << room << endl;
    for (int i = 0; i < sz(roomAns); i++)
    {
        cout << roomAns[i] << " ";
    }
    
}