#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int K, N;
vector<vector<int> > firstPairs;


int main() {
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    fin >> K >> N;
    vector<int> temp;
    for(int i = 0; i < N; i++){
        int curr;
        fin >> curr;
        curr--;
        cout << curr << " ";
        temp.push_back(curr);
    }
    cout << endl;

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            vector<int> temp2;
            temp2.push_back(temp[i]);
            temp2.push_back(temp[j]);
            cout << temp[i] << " " << temp[j] << endl;
            firstPairs.push_back(temp2);
        }
    }

    cout << "all pairs" << firstPairs.size() << endl;
    for(int i = 0; i < K - 1; i++){
        cout << endl;
        vector<int> temp2(N, 0);
        for(int j = 0; j < N; j++){
            int curr;
            fin >> curr;
            curr--;
            temp2[curr] = j;
            cout << curr << " ";
        }
        for(int j = 0; j < firstPairs.size(); j++){
            if(temp2[firstPairs[j][0]] > temp2[firstPairs[j][1]]){
                cout << endl;
                cout << temp2[firstPairs[j][0]] << " " << temp2[firstPairs[j][1]] << endl;
                cout << firstPairs[j][0] << " " << firstPairs[j][1] << endl;
                firstPairs.erase(firstPairs.begin()+j);
            }
        }
    }
    fout << firstPairs.size();
    return 0;
}