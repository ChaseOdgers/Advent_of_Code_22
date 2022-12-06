#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <chrono>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std::chrono;


void myApproach(std::string inputText){
        auto start = high_resolution_clock::now();
        std::vector<std::string> vecOfLines;

//Start Timer
    std::ofstream outFile;
    outFile.open("myResults.txt");

    std::ifstream inFile;
    inFile.open(inputText);
//My approach
    std::string line;

    while (std::getline(inFile, line)){
        // std::cout<<line<<std::endl;
        vecOfLines.push_back(line);
    }

//Timing purposes
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop - start);
    outFile<<"\n\nRuntime: \n"<<duration1.count()<<" milliseconds\n";
    
    auto duration2 = duration_cast<microseconds>(stop - start);
    
    outFile<<"Runtime: \n"<<duration2.count()<<" microseconds\n";
    auto duration3 = duration_cast<nanoseconds>(stop - start);
    outFile<<"Runtime: \n"<<duration3.count()<<" nanoseconds\n";
}

////https://cplusplus.com/forum/beginner/269195/ user:dutch's comment

void stackOverflowApproach(std::string inputText){

    std::ofstream outFile;
    outFile.open("stackOverflowResults.txt");
std::vector<std::string> vecOfLines;
    auto start = high_resolution_clock::now();

    std::ifstream in( "input_50000.txt", in.binary );
    in.seekg(0, in.end);
    std::string text(in.tellg(), 0);
    in.seekg(0);
    in.read(text.data(), text.size());

    vecOfLines.push_back(text);

//Timing purposes
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop - start);
    outFile<<"\n\nRuntime 2: \n"<<duration1.count()<<" milliseconds\n";
    
    auto duration2 = duration_cast<microseconds>(stop - start);
    
    outFile<<"Runtime 2: \n"<<duration2.count()<<" microseconds\n";
    auto duration3 = duration_cast<nanoseconds>(stop - start);
    outFile<<"Runtime 2: \n"<<duration3.count()<<" nanoseconds\n";
}

int main(int argc, char *argv[]) {

    std::string inputText = argv[1];

    myApproach(inputText);
    stackOverflowApproach(inputText);

    return 0;
}