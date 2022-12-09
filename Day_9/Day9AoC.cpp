#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std::chrono;
using namespace std;

vector<tuple<char,int>> loadvec(string fileName){
    ifstream in;
    in.open(fileName);
    vector<tuple<char, int>> vec;
    char c;
    int i;
    string line;
    while(getline(in,line)){
        c = line[0];
        i = atoi(&line[2]);
        vec.push_back(make_tuple(c,i));
    }
    return vec;
}

void printVec(vector<tuple<char,int>> vec){
    for(const auto & i:vec){
        cout<<"char: "<<get<0>(i)<<" int: "<<get<1>(i)<<endl;
    }
}

void updateLocation(char c, int i){
    cout<<"Char: "<<c<<" Int: "<<i<<endl;
}

int main(int argc, char *argv[]) {
    //Timer Start
    std::ofstream outFile;
    outFile.open("results.txt");
    auto start = high_resolution_clock::now();
//////////////////////////////////////////////////////////////////////////
 
    vector<tuple<char, int>> vec = loadvec(argv[1]);
    printVec(vec);
    for(const auto & i:vec){
        updateLocation(get<0>(i),get<1>(i));
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