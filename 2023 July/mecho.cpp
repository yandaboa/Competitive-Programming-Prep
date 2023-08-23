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
#include <queue>
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

int N, S;
vi dx, dy;
pi end;
vector<vector<char> > field;
vvi fromHive;


void BFS(int a, int b, vvi& fromMecho, int ad){
    queue<pair<pair<int, int>, int> > q;
    q.push(mp(mp(a, b), 0));

    while(!q.empty()){
        pair<pi, int> curr = q.front(); q.pop();
        if(field[curr.f.f][curr.f.s] == 'T'){
            continue;
        }
        if(fromHive[curr.f.f][curr.f.s] < curr.s/S + ad + (curr.s%S == 0 ? 0 : 1)){
            continue;
        }
        if(curr.s%S == 0){
            if(fromHive[curr.f.f][curr.f.s] == curr.s/S + ad + (curr.s%S == 0 ? 0 : 1)){
                continue;
            }
        }
        if(fromMecho[curr.f.f][curr.f.s] > curr.s){
            fromMecho[curr.f.f][curr.f.s] = curr.s;
            for (int i = 0; i < 4; i++)
            {
                if(curr.f.f + dx[i] < 0 || curr.f.f + dx[i] >= N || curr.f.s + dy[i] < 0 || curr.f.s >= N){
                    continue;
                }
                q.push(mp(mp(curr.f.f + dx[i], curr.f.s + dy[i]), curr.s + 1));
            }
        }
    }
}

int main(){
    cin >> N >> S;
    dx = {-1, 1, 0, 0};
    dy = {0, 0, -1, 1};
    vi row(N, INT_MAX);
    fromHive.rsz(N);
    field.rsz(N);
    for (int i = 0; i < N; i++)
    {
        fromHive[i] = row;
        field[i].rsz(N);
    }

    pi start, end;
    vpi hive;

    for (int i = 0; i < N; i++)
    {
        string str; cin >> str;
        for (int j = 0; j < N; j++)
        {
            field[i][j] = str[j];
            if(str[j] == 'M'){
                start = mp(i, j);
            }
            if(str[j] == 'D'){
                end = mp(i, j);
            }
            if(str[j] == 'H'){
                hive.pb(mp(i, j));
            }
        }
    }

    queue<pair<pair<int, int>, int> > q;
    for (int i = 0; i < sz(hive); i++)
    {
        q.push(mp(hive[i], 0));
    }

    while(!q.empty()){
        pair<pi, int> curr = q.front(); q.pop();
        if(field[curr.f.f][curr.f.s] != 'G' && field[curr.f.f][curr.f.s] != 'H'){
            continue;
        }
        if(fromHive[curr.f.f][curr.f.s] > curr.s){
            fromHive[curr.f.f][curr.f.s] = curr.s;
            for (int i = 0; i < 4; i++)
            {
                if(curr.f.f + dx[i] < 0 || curr.f.f + dx[i] >= N || curr.f.s + dy[i] < 0 || curr.f.s + dy[i] >= N){
                    continue;
                }
                q.push(mp(mp(curr.f.f + dx[i], curr.f.s + dy[i]), curr.s + 1));
            }
        }
    }

    int lo = 0, hi = INT_MAX/2;
    while(lo < hi){
        int mid = (lo + hi + 1)/2;
        vi row(N, INT_MAX);
        vvi fromMecho(N);
        for (int i = 0; i < N; i++)
        {
            fromMecho[i] = row;
        }
        BFS(start.f, start.s, fromMecho, mid);
        // for (int i = 0; i < sz(fromMecho); i++)
        // {
        //     for (int j = 0; j < N; j++)
        //     {
        //         cout << fromMecho[i][j]/S + mid + (fromMecho[i][j]%S == 0 ? 0 : 1) << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        if(fromMecho[end.f][end.s] == INT_MAX){
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    cout << lo << endl; 

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << fromHive[i][j] << " ";
    //     }
    //     cout << endl;
    // }


}