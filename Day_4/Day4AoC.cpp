#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std::chrono;


std::vector<std::string> binaryFileInput(std::string inputText){

    std::ofstream outFile;
    outFile.open("results.txt");

    std::vector<std::string> vecOfLines;

    //Load
    std::ifstream in(inputText, in.binary );
    in.seekg(0, in.end);
    std::string text(in.tellg(), 0);
    in.seekg(0);
    in.read(text.data(), text.size());

    vecOfLines.push_back(text);

    return vecOfLines;
}

int main(int argc, char *argv[]) {

    //Designate results destination
    std::ofstream outFile;
    outFile.open("results.txt");
    outFile<<"Start...\n";

    //Start Timer
    auto start = high_resolution_clock::now();

    //Load input file into vector of strings
    std::string inputText = argv[1];
    std::vector<std::string> loadedVector = binaryFileInput(inputText);
    auto endLoad = high_resolution_clock::now();
    auto durationLoad = duration_cast<milliseconds>(endLoad - start);
    outFile<<"Loadtime: \n"<<durationLoad.count()<<" milliseconds\n";
//////////////////////////////////////////////////////////////////////////    
    
    
    //Operate on strings
    for(int i=0; i<loadedVector.size(); i++){
        //...loadedVector[i]
    }



/////////////////////////////////////////////////////////////////////////
    //Stop timer and print results
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop - start);
    outFile<<"\n\nRuntime: \n"<<duration1.count()<<" milliseconds\n";
    auto duration2 = duration_cast<microseconds>(stop - start);    
    outFile<<"Runtime: \n"<<duration2.count()<<" microseconds\n";

    return 0;
}