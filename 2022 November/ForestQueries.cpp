#include <vector>
#include <iostream>
#include <string>

using namespace std;

int n, q;
vector<vector<long long> > prefSum;

int main(){
    cin >> n >> q;

    prefSum.resize(n + 1);
    for(int i = 0; i < prefSum.size(); i++){
        prefSum[i].resize(n + 1, 0);
    }

    for(int i = 1; i <= n; i++){
        string temp;
        cin >> temp;
        for(int j = 1; j <= n; j++){
            string str = temp.substr(j - 1, 1);
            prefSum[i][j] = str.compare(".") == 0 ? prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1]  : prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1] + 1;
            // cout << prefSum[i][j] << " ";
        }
        // cout << endl;
    }

    for(int i = 0; i < q; i++){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << prefSum[y2][x2] - prefSum[y1 - 1][x2] - prefSum[y2][x1 - 1] + prefSum[y1 - 1][x1 - 1] << endl;
    }
}

//strcmp()