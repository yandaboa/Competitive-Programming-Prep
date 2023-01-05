#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <climits>
#include <fstream>
#include <string.h>
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
map<pair<string, string>, int> places;

int main(){
    ifstream input("citystate.in");
    ofstream output("citystate.out");
    // cin.tie(0)->sync_with_stdio(0);
    input >> N;
    for (int i = 0; i < N; i++)
    {
        string cit, state; input >> cit >> state;
        cit = cit.substr(0, 2);
        places[mp(cit, state)]++;
        places[mp(state,cit)];
    }
    ll total = 0;
    for(auto a : places){
        // if(min(a.s, places[mp((a.f).s, (a.f).f)]) > 0){
        //     cout << (a.f).f << " " << (a.f).s << " | " << a.s << endl;
        // }
        if((a.f).f != (a.f).s){
            total += a.s*places[mp((a.f).s, (a.f).f)];
        }
    }
    output << total/2;

}