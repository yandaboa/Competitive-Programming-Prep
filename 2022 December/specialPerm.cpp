#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
// #include <stdio.h>

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

int T;
vi sol;

bool build(int a, vb& used){
    if(sz(sol) == sz(used) - 1){
        return true;
    }
    if(a < 1 || a > sz(used) - 1 || used[a]){
        return false;
    } else {
        used[a] = true;
        sol.pb(a);
        map<int, int> increms;
        increms[0] = 2;
        increms[1] = -3;
        increms[2] = -4;
        increms[4] = -2;
        bool works = false; int index = 0;
        while(!works && index <= 5){
            works = build(a + increms[index], used);
            index++;
        }
        return works;
    }
}


int main(){
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N; cin >> N;
        vb used; used.rsz(N + 1);
        sol.clear();
        bool exist;
        if(N%2 == 0){
            exist = build(2, used);

        } else {
            exist = build(1, used);
        }
        if(exist){
            for (int i = 0; i < sz(sol); i++)
            {
                cout << sol[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
        
    }
    
}