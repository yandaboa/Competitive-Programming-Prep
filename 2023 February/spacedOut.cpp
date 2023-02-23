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

int N;
vvi grid;
vb fromLeftEven, fromTopEven;

int main(){
    cin >> N; grid.rsz(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int a; cin >> a;
            grid[i].pb(a);
            // cout << grid[i][j] << " ";
        }
        // cout << endl;
    }
    
    //process the columns, from left
    int columnMax = 0; fromLeftEven.rsz(N);
    for (int i = 0; i < N; i++)
    {
        int evenSum = 0, oddSum = 0;
        for (int j = 0; j < N; j++)
        {
            if(j%2==0){
                evenSum += grid[j][i];
            } else {
                oddSum += grid[j][i];
            }
        }
        if(evenSum > oddSum){
            // cout << evenSum << " ";
            columnMax += evenSum;
            fromLeftEven[i] = true;
        } else {
            // cout << oddSum << ' ';
            columnMax += oddSum;
            fromLeftEven[i] = false;
        }
        // cout << endl;
    }
    int rowMax = 0; fromTopEven.rsz(N);
    for(int i = 0; i < N; i++){
        int evenSum = 0, oddSum = 0;
        for(int j = 0; j < N; j++){
            if(j%2==0){
                evenSum += grid[i][j];
            } else {
                oddSum += grid[i][j];
            }
        }
        if(evenSum > oddSum){
            rowMax += evenSum;
            fromTopEven[i] = true;
        } else {
            rowMax += oddSum;
            fromTopEven[i] = false;
        }
    } 
    if(rowMax > columnMax){
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++){
        //         if(fromTopEven[i]){
        //             if(j%2==0){
        //                 cout << 'C';
        //             } else {
        //                 cout << '.';
        //             }
        //         } else {
        //             if(j%2==0){
        //                 cout << '.';
        //             } else {
        //                 cout << 'C';
        //             }
        //         }
        //     }
        //     cout << endl;
        // }
        cout << rowMax;
    } else {
        // vector<vb> cows;
        // cows.rsz(N);
        // for(int i = 0; i < sz(cows); i++){
        //     cows[i].rsz(N);
        // }
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++){
        //         if(fromLeftEven[i]){
        //             cows[j][i] = j%2==0;
        //         } else {
        //             cows[j][i] = !(j%2==0);
        //         }
        //     }
        // }
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++){
        //         if(cows[i][j]){
        //             cout << 'C';
        //         } else {
        //             cout << '.';
        //         }
        //     }
        //     cout << endl;
        // }
        cout << columnMax;
    }
}