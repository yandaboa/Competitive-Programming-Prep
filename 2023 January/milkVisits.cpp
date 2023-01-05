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

string str;
int N, M;
vector<vector<int> > adj;
vb visited;
vi comp;

void DFS(int a, int fa, int compNum){
    // cout << "" + str[a] << " " << "" +str[fa] << endl;
    if(fa > -1 && str[a] != str[fa]){
        return;
    } else {
        if(visited[a]){
            return;
        }
        comp[a] = compNum;
        visited[a] = true;
        for (int i = 0; i < sz(adj[a]); i++)
        {
            DFS(adj[a][i], a, compNum);
        }
        
    }
}

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    ifstream input("milkvisits.in");
    ofstream output("milkvisits.out");
    input >> N >> M;
    input >> str;
    adj.rsz(N); visited.rsz(N); comp.rsz(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b; input >> a >> b; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    

    int counter = 1;
    for (int i = 0; i < N; i++)
    {
        if(!visited[i]){
            // cout << "traveled";
            DFS(i, -1, counter);
            counter++;
        }
    }
    // for (int i = 0; i < sz(comp); i++)
    // {
    //     output << comp[i] << " ";
    // }
    // cout << endl;
    

    for (int i = 0; i < M; i++)
    {
        int a, b; char pref; input >> a >> b >> pref; a--; b--;
        if(comp[a] == comp[b]){
            if(str[a] == pref){
                output << "1";
            } else {
                output << "0";
            }
        } else {
            output << "1";
        }
    }
    output.close();
    
} 