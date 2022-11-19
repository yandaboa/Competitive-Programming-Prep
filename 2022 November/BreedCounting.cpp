#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int cowNum, querieNum;
vector<int> cows;
vector<vector<int> > prefSum;

int main(){

    ifstream input("bcount.in");
    ofstream output("bcount.out");

    input >> cowNum >> querieNum;
    cows.resize(cowNum);
    prefSum.resize(3);
    prefSum[0].resize(cowNum + 1);
    prefSum[1].resize(cowNum + 1);
    prefSum[2].resize(cowNum + 1);

    for(int i = 0; i < cowNum ; i++){
        int temp;
        input >> temp;
        cows[i] = temp;
    }

    //build prefix sum array
    prefSum[0][0] = 0;
    prefSum[1][0] = 0;
    prefSum[2][0] = 0;

    for(int i = 1; i < prefSum[0].size(); i++){
        prefSum[cows[i - 1] - 1][i] = prefSum[cows[i - 1] - 1][i - 1] + 1;
        if(cows[i - 1] == 1){
            prefSum[1][i] = prefSum[1][i - 1];
            prefSum[2][i] = prefSum[2][i - 1];

        }
        if(cows[i - 1] == 2){
            prefSum[0][i] = prefSum[0][i - 1];
            prefSum[2][i] = prefSum[2][i - 1];
        }
        if(cows[i - 1] == 3){
            prefSum[0][i] = prefSum[0][i - 1];
            prefSum[1][i] = prefSum[1][i - 1];
        }
        
        // cout << cows[i - 1] << " | " << prefSum[0][i] << " " << prefSum[1][i] << " " << prefSum[2][i] << endl;
    }

    //process queries and give output

    for(int i = 0; i < querieNum; i++){
        int a, b;
        input >> a >> b;
        output << prefSum[0][b] - prefSum[0][a - 1] << " " << prefSum[1][b] - prefSum[1][a - 1] << " " << prefSum[2][b] - prefSum[2][a - 1] << endl;
    }

    input.close();
    output.close();
}