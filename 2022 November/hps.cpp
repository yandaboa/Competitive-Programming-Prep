#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int numMoves;
vector<vector<int> > moves;

int main(){
    ifstream input("hps.in");
    ofstream output("hps.out");

    input >> numMoves;
    moves.resize(3);
    moves[0].resize(numMoves + 1); //H
    moves[1].resize(numMoves + 1); //P
    moves[2].resize(numMoves + 1); //S

    moves[0][0] = 0;
    moves[1][0] = 0;
    moves[2][0] = 0;

    for(int i = 1; i <= numMoves; i++){
        string currMove;
        input >> currMove;

        if(currMove.compare("H") == 0){
            moves[0][i] = moves[0][i - 1]+1;
            moves[1][i] = moves[1][i - 1];
            moves[2][i] = moves[2][i - 1];
        } else if (currMove.compare("P") == 0){
            moves[0][i] = moves[0][i - 1];
            moves[1][i] = moves[1][i - 1] + 1;
            moves[2][i] = moves[2][i - 1];
        } else {
            moves[0][i] = moves[0][i - 1];
            moves[1][i] = moves[1][i - 1];
            moves[2][i] = moves[2][i - 1] + 1;
        }
    }
    int most = 0;

    for(int i = 1; i < moves[0].size(); i++){
        most = max(most, (moves[0][i] - moves[0][0] + moves[1][moves[1].size() - 1] - moves[1][i]));
        most = max(most, (moves[0][i] - moves[0][0] + moves[2][moves[2].size() - 1] - moves[2][i]));
        most = max(most, (moves[1][i] - moves[1][0] + moves[0][moves[0].size() - 1] - moves[0][i]));
        most = max(most, (moves[1][i] - moves[1][0] + moves[2][moves[2].size() - 1] - moves[2][i]));
        most = max(most, (moves[2][i] - moves[2][0] + moves[0][moves[1].size() - 1] - moves[0][i]));
        most = max(most, (moves[2][i] - moves[2][0] + moves[1][moves[1].size() - 1] - moves[1][i]));
    }

    output << most;
    
}

    