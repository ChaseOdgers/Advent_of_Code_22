#include "day9.hpp"

int main(int argc, char* argv[]) {

    if(argc<2){
        cout<<"Not enough arguments entered"<<endl;
        return 0;
    }

    /*
        argv[1] is input file, argv[2] is mode flag
        argv[2] (mode) = 0 no print, 1 just moves, 2 verbose
    */
    Day9 obj(argv[1]);

    //Load all the moves from the file input
    obj.run();

    cout<<"size: "<<obj.getSetSize()<<endl;

    // obj.print8();

    return 0;
}