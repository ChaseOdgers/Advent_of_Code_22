/*Day2AoC.cpp*/
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <chrono>
using namespace std::chrono;

int main(){
    auto start = high_resolution_clock::now();
    std::ifstream inFile;
    inFile.open("p2_Input.txt");
    std::ofstream outFile;
    outFile.open("p2_output_optimized.txt");

    int total=0;
    std::string line;

    std::unordered_map<std::string, int> umap2;

    umap2["A X"] = 3;
    umap2["A Y"] = 4;
    umap2["A Z"] = 8;
    umap2["B X"] = 1;
    umap2["B Y"] = 5;
    umap2["B Z"] = 9;
    umap2["C X"] = 2;
    umap2["C Y"] = 6;
    umap2["C Z"] = 7;

    while (std::getline(inFile, line)){
            total += umap2.at(line);
        }

    auto stop = high_resolution_clock::now();
    
    //Timing purposes
    //Print Results    
    // outFile<<"Day2AoC_optimized.cpp\n";
    outFile<<"Total: "<<total<<"\n";

    //Timing purposes
    auto duration1 = duration_cast<milliseconds>(stop - start);
    outFile<<"\n\nRuntime: \n"<<duration1.count()<<" milliseconds\n";
    
    auto duration2 = duration_cast<microseconds>(stop - start);
    
    outFile<<"Runtime: \n"<<duration2.count()<<" microseconds\n";
    auto duration3 = duration_cast<nanoseconds>(stop - start);
    outFile<<"Runtime: \n"<<duration3.count()<<" nanoseconds\n";
}