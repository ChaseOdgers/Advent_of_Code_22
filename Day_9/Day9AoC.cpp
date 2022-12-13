#include "day9.hpp"

int main(int argc, char* argv[]) {

    if(argc<2){
        cout<<"Not enough arguments entered"<<endl;
        return 0;
    }

    //Start Timer
    auto start = high_resolution_clock::now();
////////////////////////////////////////////////////////////

    //Part 1
    /*
        argv[1] is input file, argv[2] is mode flag
        argv[2] (mode) = 0 no print, 1 just moves, 2 verbose
    */
    Day9 obj(argv[1],stoi(argv[2]));



    // /*
    //     Load all the moves from the file input
    // */
    obj.run();

    obj.printResults();


////////////////////////////////////////////////////////
    //Stop timer and print results
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop - start);
    cout<<"\nRuntime: \n"<<duration1.count()<<" milliseconds\n";
    auto duration2 = duration_cast<microseconds>(stop - start);    
    cout<<"Runtime: \n"<<duration2.count()<<" microseconds\n";

    return 0;
}