#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std::chrono;
using namespace std;

std::string binaryFileInput(std::string inputText){

    std::ofstream outFile;
    outFile.open("results.txt");

    //Load
    std::ifstream in(inputText, in.binary );
    in.seekg(0, in.end);
    std::string text(in.tellg(), 0);
    in.seekg(0);
    in.read(text.data(), text.size());

    std::string fileAsAString = text;

    //This is returning all of the file as one vector of charachters
    return fileAsAString;
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
    std::string inputAsAString = binaryFileInput(inputText);
    auto endLoad = high_resolution_clock::now();
    auto durationLoad = duration_cast<milliseconds>(endLoad - start);
    outFile<<"Loadtime: \n"<<durationLoad.count()<<" milliseconds\n";
//////////////////////////////////////////////////////////////////////////    
    
    //New vector to hold our stacks

    int colIndex=0, rowIndex=0;
    //for every char in the input file
    // for(int i=0; i<inputAsAString.size(); i++){
    //     if()
    // }

    // else{
    //     colIndex++;
    //     i+3; // this accounts for the for loop adding one which will be at the next char
    // }
    std::vector<std::vector<char>> vectorOfStacks;

    int i=1, fullyLoaded = -1;

    int endOfStackInput = inputAsAString.find_first_of('1')-4, 
        startOfInstructionInput = inputAsAString.find_first_of('m'),
        endOfFile = inputAsAString.size();

    outFile<<endOfStackInput<<endl;
    outFile<<startOfInstructionInput<<endl;
    outFile<<endOfFile<<endl;

    for(int i=1; i<endOfStackInput; i++){
        if(inputAsAString[i]=='\n'){
            outFile<<"new line at: "<<i<<endl;
            rowIndex++;
            colIndex= 0;
        }
        if(inputAsAString[i]=='['){
            colIndex++;
        }
        if(isalpha(inputAsAString[i])){
            outFile<<"Added: "<<inputAsAString[i]<<" col: "<<colIndex<<" row: "<<rowIndex<<endl;
        }
        else{
            outFile<<"i = "<<i<<" value is: "<<inputAsAString[i]<<endl;
        }
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