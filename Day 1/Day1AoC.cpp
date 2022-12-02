/*
Chase Odgers
chasewodgers@gmail.com
Description: Advent of Code Challenge, Day 1
01/12/2022
*/
#include <iostream>
#include <fstream>
#include <vector>

int main(){
    /*
    Initiate I/O
    */
    std::ifstream inFile;
    inFile.open("p1_Input.txt");
    std::ofstream outFile;
    outFile.open("p1_Output.txt");
    
    /*
    Declare variables
    */
    int hungryElf=0;
    std::string line;
    std::vector<int> vecOfElf;
    
    /*
    Begin iterating line by line
        - "line" var holds the read in line
    */
    while (std::getline(inFile, line)){
        /*
        Cond. 1: Load in first line
        */
        if( vecOfElf.empty() ){ vecOfElf.push_back(std::stoi(line)); }

        /*
        Cond. 2: Empty line
            - Check if 
        */
        else if( line.length() == 0 ){ vecOfElf.push_back(0); }

        /*
        Cond. 3: Add more calories to the current elfs total
        */
        else{ vecOfElf[vecOfElf.size()-1] += std::stoi(line); }
    }

    /*
    Sort the vector of elves from small to large
    */
    std::sort(vecOfElf.begin(), vecOfElf.end());

    /*
    Print the results
    */
    outFile
        <<  " 1: "<<vecOfElf[vecOfElf.size()-1]
        <<"\n 2: "<<vecOfElf[vecOfElf.size()-2]
        <<"\n 3: "<<vecOfElf[vecOfElf.size()-3]
        <<"\nTotal: "
        <<  vecOfElf[vecOfElf.size()-1] +vecOfElf[vecOfElf.size()-2] +vecOfElf[vecOfElf.size()-3]
        <<"\n";

}
