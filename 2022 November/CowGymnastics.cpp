#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int K, N;
vector<vector<bool> > relArr;

int main(){
    ifstream input("gymnastics.in");
    ofstream output("gymnastics.out");
    input >> K >> N;
    relArr.resize(N);
    for(int i = 0; i < N; i++){
        relArr[i].resize(N);
    }

    for(int i = 0; i < K; i++){
        vector<int> curr;
        for(int j = 0; j < N; j++){
            int temp;
            input >> temp;
            curr.push_back(temp);
        }

        for(int j = 0; j < N; j++){
            for (int x = j + 1; x < N; x++)
            {
                if(i == 0){
                    relArr[curr[j] - 1][curr[x] - 1] = true;
                }
                relArr[curr[x] - 1][curr[j] - 1] = false;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(relArr[i][j]){
                count++;
            }
        }
        
    }
    output << count;
    
}