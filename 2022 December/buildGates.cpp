#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
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

int N;
vector<vb> visited;
set<pair<int, pair<int, int> > > vertFences, horzFences;

void floodfill(int a, int b, int ga, int gb){
    if(a < 0 || a >= sz(visited) || b < 0 || b >= sz(visited[a]) || visited[a][b]){
        return;
    }
    if(a != ga || gb != b){
        int vrtxX = max(a, ga);
        int vrtxY = max(b, gb);
        if(a != ga){
            if(vertFences.find(mp(vrtxX, mp(vrtxY, vrtxY + 1)))!=vertFences.end()){
                return;
            }
        } else {
            if(horzFences.find(mp(vrtxY, mp(vrtxX, vrtxX + 1))) != horzFences.end()){
                return;
            }
        }
    }
    visited[a][b] = true;
    floodfill(a + 1, b, a, b); floodfill(a, b + 1, a, b); floodfill(a-1, b, a, b); floodfill(a, b-1, a, b);
}

void printfield(){
    for (int i = 0; i < sz(visited); i++)
    {
        for (int j = 0; j < sz(visited[i]); j++)
        {
            if(visited[i][j]){
                cout << "*";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    
}

int main(){
    ifstream input("gates.in");
    ofstream output("gates.out");
    input >> N;
    string moves; input >> moves; pair<int, int> currPosition = mp(N + 1, N + 1); visited.rsz(2*N + 3);
    for (int i = 0; i < sz(visited); i++)
    {
        visited[i].rsz(2*N + 3);
    }
    
    for (int i = 0; i < sz(moves); i++)
    {
        if(moves[i] == 'N'){
            vertFences.insert(mp(currPosition.f, mp(currPosition.s, currPosition.s + 1)));
            currPosition.s++;
            // cout << currPosition.f << " " << currPosition.s << endl;
        } else if (moves[i] == 'S'){
            vertFences.insert(mp(currPosition.f, mp(currPosition.s - 1, currPosition.s)));
            currPosition.s--;
            // cout << currPosition.f << " " << currPosition.s << endl;

        } else if(moves[i] == 'E'){
            horzFences.insert(mp(currPosition.s, mp(currPosition.f, currPosition.f + 1)));
            currPosition.f++;
            // cout << currPosition.f << " " << currPosition.s << endl;

        } else {
            horzFences.insert(mp(currPosition.s, mp(currPosition.f - 1, currPosition.f)));
            currPosition.f--;
            // cout << currPosition.f << " " << currPosition.s << endl;

        }
    }

    int comps = 0;
    
    for (int i = 0; i < sz(visited); i++)
    {
        for (int j = 0; j < sz(visited[i]); j++)
        {
            if(!visited[i][j]){
                floodfill(i, j, i, j);
                comps++;
                // cout << endl; printfield();
            }
        }
        
    }
    output << comps - 1;
    
}