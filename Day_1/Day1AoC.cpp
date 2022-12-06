#include <iostream>
#include <fstream>
#include <vector>

int main(){
 
    std::ifstream inFile;
    inFile.open("p1_Input.txt");
    std::ofstream outFile;
    outFile.open("p1_Output.txt");
    

    int hungryElf=0;
    std::string line;
    std::vector<int> vecOfElf;
    

    while (std::getline(inFile, line)){

        if( vecOfElf.empty() ){ vecOfElf.push_back(std::stoi(line)); }

        else if( line.length() == 0 ){ vecOfElf.push_back(0); }

        else{ vecOfElf[vecOfElf.size()-1] += std::stoi(line); }
    }

    std::sort(vecOfElf.begin(), vecOfElf.end());

    outFile<<  " 1: "<<vecOfElf[vecOfElf.size()-1]
        <<"\nTotal: "
        <<  vecOfElf[vecOfElf.size()-1] +vecOfElf[vecOfElf.size()-2] +vecOfElf[vecOfElf.size()-3]<<"\n";

}