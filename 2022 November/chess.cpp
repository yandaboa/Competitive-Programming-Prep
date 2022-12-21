#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
vector<vector<bool> > board;
ll total;

bool inDanger(pi place, vector<pi> queens){
    bool safe = true;
    for(int i = 0; i < sz(queens); ++i){
        if(place.f == queens[i].f || place.s == queens[i].s){
            safe = false;
        }
        if(abs(place.f - queens[i].f) == abs(place.s - queens[i].s)){
            safe = false;
        }
    }
    return !safe;
}

void placeQueens(int r, vector<pi> queens){ //come back and implement this with actual backtracking...
    if(r == 8){
        total++;
        return;
    }
    for (int  i = 0; i < 8; i++)
    {
        if(!board[r][i] && !inDanger(mp(r, i), queens)){
            queens.pb(mp(r, i));
            placeQueens(r + 1, queens);
            queens.pop_back();
        }
    }
    
}



int main(){
    board.rsz(8);
    //intake the board - finished
    for(int i = 0; i < 8; i++){
        string currLine;
        cin >> currLine;
        board[i].rsz(8);
        for (int j = 0; j < 8; j++)
        {
            if("." == currLine.substr(j, 1)){
                board[i][j] = false;
            } else {
                board[i][j] = true;
            }
        }
    }

    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    total = 0;
    vector<pi> empty;
    placeQueens(0, empty);
    cout << total;
}