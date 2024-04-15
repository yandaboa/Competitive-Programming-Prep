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
#include <stack>
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
vector<vector<long long> > grid;
vector<vector<long long> > sGrid;

void update(vll &arr, int a){
    for(int i = 0; i < N; i++){
        arr[i] += grid[a][i];
        // if(sGrid[a][i] == 1){
        //     update(arr, i);
        // }
    }
}

void fillIn(int a){
    int start = a + 1;
    vll currRow;
    currRow.rsz(N);
    for(int i = start; i < N; i++){
        if(currRow[i]%2 != grid[a][i]){
            sGrid[a][i] = 1;
            update(currRow, i);
        }
    }
    // for(int i = 0; i < N; i++){
    //     cout << currRow[i];
    // }
    // cout <<endl;
    // for(int i = a + 1; i < N; i++){
    //     cout << grid[a][i];
    // }
    // cout<<endl;
}

int main(){
	cin >> N;
	grid.rsz(N);
    sGrid.rsz(N);
	for (int i = 0; i < N; i++)
    {
        grid[i].rsz(N);
        sGrid[i].rsz(N);
    }
    for (int i = 0; i < N; i++)
    {
        string str; cin >> str;
        for (int j = 0; j < sz(str); j++)
        {
            grid[i][j+i+1] = str[j]-'0';
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < sz(grid[i]); j++)
    //     {
    //         cout << grid[i][j];
    //     }
    //     cout<< endl;
    // }

    for(int a = N-1; a > -1; a--){
        fillIn(a);
    }

    int ans = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(sGrid[i][j] > 0){
                ans++;
            }
            // cout << sGrid[i][j];
        }
    }
    cout << ans << endl;
    
}