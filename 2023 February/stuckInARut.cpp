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

vector<pair<pair<int, int>, bool>> cows;
vvi cowStopped;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char temp; cin >> temp;
        bool facingNorth; int x, y; cin >> x >> y; facingNorth = 'N' == temp;
        cows.pb(mp(mp(x, y), facingNorth));
    }
    cowStopped.rsz(sz(cows));
    for (int i = 0; i < sz(cowStopped); i++)
    {
        int soonest = INT_MAX, stoppedBy = -1, closest = INT_MAX;
        for (int j = 0; j < sz(cows); j++)
        {
            if(i == j){
                continue;
            }
            if(cows[i].f.f == cows[j].f.f && cows[i].f.s == cows[j].f.s){
                continue;
            }
            if(cows[i].s == cows[j].s){//both facing same direction
                if(cows[i].s){//facing north, so the x has to be the same for collision
                    if(cows[i].f.f == cows[j].f.f && cows[i].f.s < cows[j].f.s){
                        if(cows[j].f.s - cows[i].f.s < soonest){ soonest = cows[j].f.s - cows[i].f.s; stoppedBy = j; closest = 0;}
                    }
                } else {
                    if(cows[i].f.s == cows[j].f.s && cows[i].f.f < cows[j].f.f){
                        if(cows[j].f.f - cows[i].f.f < soonest){ soonest = cows[j].f.f - cows[i].f.f; stoppedBy = j; closest = 0;}
                    }
                }
            } else { //facing different directions
                if(cows[i].s){// facing north, so i goes up, and j goes right
                    if(cows[i].f.s >= cows[j].f.s || cows[j].f.f > cows[i].f.f){continue;}
                    int yDiff = cows[j].f.s - cows[i].f.s;
                    int xDiff = cows[i].f.f - cows[j].f.f;
                    if(yDiff > xDiff){
                        if(yDiff < soonest){
                            soonest = yDiff; stoppedBy = j; closest = xDiff;                       
                        } else if (yDiff == soonest){
                            if(xDiff < closest){
                                stoppedBy = j; closest = xDiff;                       
                            }
                        }

                    }
                } else { //facing east, so i goes right, j goes up
                    if(cows[i].f.f >= cows[j].f.f || cows[j].f.s > cows[i].f.s){continue;}
                    int xDiff = cows[j].f.f - cows[i].f.f;
                    int yDiff = cows[i].f.s - cows[j].f.s;
                    if(xDiff > yDiff){
                        if(xDiff < soonest){
                            soonest = xDiff; stoppedBy = j; closest = yDiff;
                        } else if (xDiff == soonest){
                            if(yDiff < closest){
                                stoppedBy = j; closest = yDiff;
                            }
                        }
                    }
                }
            }
        }
        if(stoppedBy != -1)}{
            cowStopped[stoppedBy].pb(i);
        }
    }
    for (int i = 0; i < sz(); i++)
    {
        /* code */
    }
    

    vb visited; visited.rsz(N); vi numStopped; numStopped.rsz(N);
    for (int i = 0; i < sz(visited); i++)
    {
        if(!visited[i]){

        }
    }
    
    
}