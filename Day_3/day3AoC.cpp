#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std::chrono;


int main(){

    //Start run timer
    auto start = high_resolution_clock::now();

    //Initiate io
    std::ifstream inFile;
    inFile.open("day3_input.txt");

    //Declare variables
    int total=0, total2=0, linecount= 0, groupCase=0;
    std::string line, half1, half2, groupOfElves[2];
    std::vector<char> commonLetter;


    //Find letters in string that are in both compartments, add values to total
    while (std::getline(inFile, line)){

        //Part 1
        half1 = line.substr(0,line.size()/2);
        half2 = line.substr(line.size()/2,line.size());
        for(auto i:half2){
            if(half1.find_first_of(i) != std::string::npos){
                if(int(i)-96 <0){ total+=int(i)-38; }
                else{ total+=int(i)-96; }
                break;
            }
        }

        //Part 2
        if(linecount%3 < 2){ groupOfElves[linecount%3] = line; }

        if(linecount%3 == 2){
            for(auto letter:groupOfElves[0]){
                //Add the common letter between 2 first strings to vector 
                if(groupOfElves[1].find_first_of(letter) != std::string::npos){
                    commonLetter.push_back(letter);
                }
            }

            //Check vector of letters common between 1st two strings against the third
            for(auto letter:commonLetter){
                if(line.find_first_of(letter) != std::string::npos){
                    if(int(letter)-96 <0){ total2+=int(letter)-38; }
                    else{ total2+=int(letter)-96; }
                    commonLetter.clear();
                    break;
                }
            }
        }
        linecount++;
    }

    std::cout<<"Total: "<<total<<std::endl;
    std::cout<<"Total 2: "<<total2<<std::endl;

    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop - start);
    std::cout<<"\nRuntime:\n."<<duration1.count()<<" milliseconds\n";
}