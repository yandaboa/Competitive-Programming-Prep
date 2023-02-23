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

int N, Q;
vi arr, fromLeft, fromRight;
map<char, int> alph;

int main(){
    cin >> N >> Q; string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; arr.rsz(N); fromLeft.rsz(N); fromRight.rsz(N);
    for (int i = 0; i < sz(str); i++)
    {
        alph[str[i]] = i;
    }
    string input; cin >> input;
    for (int i = 0; i < N; i++)
    {
        arr[i] = alph[input[i]];
        // cout << input[i] << " " << alph[input[i]] << endl;
    }
    int brushes = 1; set<int> painted; painted.insert(arr[0]);
    for (int i = 0; i < sz(arr); i++)
    {
        if(i > 0){
            if(arr[i] > arr[i - 1]){
                painted.insert(arr[i]);
                brushes++;
            }
            if(arr[i] < arr[i - 1]){
                vi remove;
                auto a = painted.upper_bound(arr[i]);
                for(auto itr = a; itr != painted.end(); itr++){
                    remove.pb(*itr);
                }
                for(int i = 0; i < sz(remove); i++){
                    painted.erase(remove[i]);
                }
                if(painted.count(arr[i]) < 1){
                    painted.insert(arr[i]);
                    brushes++;
                }
            }
        }
        // for(auto b = painted.begin(); b != painted.end(); b++){
        //     cout << *b << " ";
        // }
        // cout << endl;
        fromLeft[i] = brushes;
    }
    brushes = 1; painted.clear(); painted.insert(arr[sz(arr) - 1]);
    for (int i = sz(arr) - 1; i > - 1; i--)
    {
        if(i < sz(arr) - 1){
            if(arr[i] > arr[i + 1]){
                painted.insert(arr[i]);
                brushes++;
            }
            if(arr[i] < arr[i + 1]){
                vi remove;
                auto a = painted.upper_bound(arr[i]);
                for(auto itr = a; itr != painted.end(); itr++){
                    remove.pb(*itr);
                }
                for(int i = 0; i < sz(remove); i++){
                    painted.erase(remove[i]);
                }
                if(painted.count(arr[i]) < 1){
                    painted.insert(arr[i]);
                    brushes++;
                }
            }
        }
        // for(auto b = painted.begin(); b != painted.end(); b++){
        //     cout << *b << " ";
        // }
        // cout << endl;
        fromRight[i] = brushes;
    }

    // for (int i = 0; i < sz(fromLeft); i++)
    // {
    //     cout << fromLeft[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < sz(fromRight); i++)
    // {
    //     cout << fromRight[i] << " ";
    // }
    // cout << endl;
    for(int i = 0; i < Q; i++){
        int l, r; cin >> l >> r; l-=2;
        int sum = 0;
        if(l >= 0){
            sum += fromLeft[l];
        }
        if(r < sz(fromRight)){
            sum += fromRight[r];
        }
        cout << sum << endl;
    }
    
}