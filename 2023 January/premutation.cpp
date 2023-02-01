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

int T;

int main(){
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N; cin >> N;
        vi rightOf; rightOf.rsz(N + 1); fill(all(rightOf), -1);
        vvi undecided; undecided.rsz(N + 1);
        for (int j = 0; j < N; j++)
        {
            vi arr;
            for (int b = 0; b < N - 1; b++)
            {
                int v; cin >> v; arr.pb(v);
            }
            for (int b = 0; b < sz(arr); b++)
            {
                int index;
                if(b == 0){
                    index = 0;
                } else {
                    index = arr[b - 1];
                }
                if(rightOf[arr[b]] != - 1){
                    continue;
                }
                if(sz(undecided[arr[b]]) > 0 && find(all(undecided[arr[b]]), index) != undecided[arr[b]].end()){
                    rightOf[arr[b]] = index;
                } else {
                    undecided[arr[b]].pb(index);
                }
            }
        }
        for (int x = 0; x < sz(rightOf); x++)
        {
            // cout << rightOf[x] << " ";
        }
        // cout << endl;
        
        int used = 1, start;
        for (int j = 0; j < sz(rightOf); j++)
        {
            if(rightOf[j] == 0){
                start = j;
            }
        }
        cout << start << " ";
        if(N == 3){
            while(used < N){
                for (int j = 0; j < sz(undecided); j++)
                {
                    if(sz(undecided[j]) < 2){
                        continue;
                    }
                    if(undecided[j][0] == start || undecided[j][1] == start){
                        cout << j << " ";
                        start = j;
                        used++;
                        break;
                    }
                }
                
            }

        } else {
            while(used < N){
            for(int j = 0; j < sz(rightOf); j++){
                    if(rightOf[j] == start){
                        cout << j << " ";
                        start = j;
                        used++;
                        break;
                    }
                }
            }
        }
        
        cout << endl;
    }
    
}