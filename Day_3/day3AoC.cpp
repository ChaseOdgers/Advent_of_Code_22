#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std::chrono;

int main(){

    //Timer Start
    // auto start = high_resolution_clock::now();

    //Initiate file io
    std::ifstream inFile;
    inFile.open("day3_input.txt");
    std::ofstream outFile;
    outFile.open("day3_output.txt");

    //Declare vars
    int total=0, h1=0,h2=0;
    std::string line, half1, half2;
    std::vector<char> vecHalf1, vecAns;

/*
    - Problem statement
    - Rucksack has 2 compartments
    - Each item maps to 1 of the compartments
    - 1 misplaced item per rucksack
    - Each rucksack is 1 line, each char on line is 1 item
    - 1st half of line = compartment 1 second half is compartment 2
    - Lowercase = 1-26
    - Uppercase = 27-52
    
    Q1: what item appears in both compartments
*/

    //Read input line by line
    while (std::getline(inFile, line)){
        half1 = line.substr(0,line.size()/2);
        half2 = line.substr(line.size()/2,line.size());
        for(auto i:half2){
            if(half1.find_first_of(i) != std::string::npos){
                vecAns.push_back(i);
                break;
            }
        }
    }
    for(auto i:vecAns){
        if(int(i)-96 <0){
            std::cout<<"Letter: "<<i<<" Dec:"<<int(i)-64+26<<std::endl;

            total+=int(i)-64+26;
            //abs(i)
        }
        else{
            std::cout<<"Letter: "<<i<<" Dec:"<<int(i)-96<<std::endl;
            total+=int(i)-96;
        }
    }

 std::string alphabet = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0; i<=52; i++){
        outFile<<i<<" "<<alphabet[i]<<"\n";
    }

std::cout<<"Total: "<<total<<std::endl;
}