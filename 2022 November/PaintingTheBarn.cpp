#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int N, desiredSum;
vector<vector<int> > changes, prefSum;

int main(){
    ifstream input("paintbarn.in");
    ofstream output("paintbarn.out");

    input >> N >> desiredSum;

    changes.resize(1002);
    for(int i = 0 ; i < changes.size(); i++){
        changes[i].resize(1002, 0);
    }
    prefSum.resize(1002);
    for(int i = 0 ; i < prefSum.size(); i++){
        prefSum[i].resize(1002);
    }

    for(int i = 0 ; i < N; i++){
        int a, b, c, d;
        input >> a >> b >> c >> d;

        c--;
        d--;
        changes[a][b]++;
        changes[a][d + 1]--;
        changes[c + 1][b]--;
        // for(int j = a; j <= c; j++){
        //     changes[j][d + 1]--;
        // }
        // for(int j = b; j <= d; j++){
        //     changes[c + 1][j]--;
        // }
        changes[c + 1][d + 1]++;
    }

    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < 10; j++){
    //         cout << changes[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int count = 0;
    for(int i = 1; i < prefSum.size(); i++){
        for(int j = 1; j < prefSum[0].size(); j++){
            prefSum[i][j] = prefSum[i-1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1] + changes[i - 1][j - 1];
            if(prefSum[i][j] == desiredSum){
                count++;
            } 
        }
    }
    // cout << endl;

    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < 10; j++){
    //         cout << prefSum[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    output<< count;

}