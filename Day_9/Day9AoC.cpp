#include "day9.hpp"

int main(int argc, char* argv[]) {

    if(argc<2){
        cout<<"Not enough arguments entered"<<endl;
        return 0;
    }

    //argv[1] is input file, argv[2] is mode flag
    //argv[2] (mode) = 0 no print, 1 just moves, 2 verbose
    Day9 obj(argv[1],*argv[2]);

    //Load all the moves from the file input
    obj.loadvec();

    //load a vector<vector<char>> with '-' that will track moves and answers
    obj.loadBoards();
    
    //Process the moves from vec, updating boards & printing at each move
    obj.processVec();

    //Print the positions that T visited
    obj.printAnsBoard();

    cout<<"Tail visited: "<<obj.getTailVisited()<<" positions"<<endl;

    return 0;
}