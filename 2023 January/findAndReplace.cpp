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

int T, cycles;

void DFS(int a, vi& visited, int start, map<char, char>& swapTo){
    if(visited[a] == start){
        // cout << "inc";
        cycles++;
        return;
    } else if (visited[a] != 0){
        return;
    }
    visited[a] = start;
    // cout << start << endl;
    if(swapTo.find(char(a + int('A'))) != swapTo.end()){
        // cout << "next " << swapTo[char(a + int('A'))] << endl;
        DFS(int(swapTo[char(a + int('A'))]) - 'A', visited, start, swapTo);
    }
}

void solve(){
    map<char, char> swapTo;
    string og, targ; cin >> og >> targ;
    bool allSame = true, possible = true;
    for (int i = 0; i < sz(og); i++)
    {
        if(og[i] != targ[i]){
            if(swapTo.find(og[i]) != swapTo.end() && swapTo[og[i]] != targ[i]){
                possible = false;
                break;
            }
            swapTo[og[i]] = targ[i];
            allSame = false;
        } else {
            if(swapTo.find(og[i]) != swapTo.end()){
                possible = false;
                break;
            }
        }
    }
    // for(auto a : swapTo){
    //     cout << (a).f << " -> " << (a).s << endl;
    // }

    if(allSame){
        cout << 0 << endl;
        return;
    }
    if(!possible){
        cout << -1 << endl;
        return;
    }

    vi visited; visited.rsz(58); cycles = 0;
    for (int i = 0; i < sz(visited); i++)
    {
        if(visited[i] == 0 && (i < 26 || i > 31)){
            DFS(i, visited, i + 1, swapTo);
        }
    }
    // for (int i = 0; i < sz(visited); i++)
    // {
    //     cout << char(i + int('A')) << " " <<  visited[i] << endl;
    // }
    
    cout << sz(swapTo) + cycles << endl;
    
}

int main(){
    // string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // for (int i = 0; i < sz(alph); i++)
    // {
    //     cout << int(alph[i])-'A' << " ";
    // }
    
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }
    
}