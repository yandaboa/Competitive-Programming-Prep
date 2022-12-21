#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int> > adjList;
vector<int> useList;

int main(){
    ifstream input("revegetate.in");
    ofstream output("revegetate.out");
    input >> N >> M;

    adjList.resize(N);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        input >> a >> b;
        a--;
        b--;
        if(a < b){
            int temp = a;
            a = b;
            b = temp;
        }

        adjList[a].push_back(b);
    }

    useList.resize(N);

    // for (int i = 0; i < adjList.size(); i++)
    // {
    //     for (int j = 0; j < adjList[i].size(); j++)
    //     {
    //         cout << adjList[i][j] << " ";

    //     }
        
    //     cout << endl;
    // }
    

    for(int i = 1; i <= N; i++){
        for (int j = 1; j <= 4; j++)
        {
            bool used = false;
            for (int x = 0; x < adjList[i - 1].size(); x++)
            {
                if(useList[adjList[i - 1][x]] == j){
                    used = true;
                    break;
                }
            }
            if(!used){
                output << j;
                useList[i - 1] = j;
                break;
            }
        }
    }
    
}