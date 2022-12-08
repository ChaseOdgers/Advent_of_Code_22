#include <chrono>
#include <fstream>
#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <iterator>
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
    
    ifstream in(argv[1]);
    int foundAnsFlag=-1, ansAt=-1;
    string stringIn = binaryFileInput(argv[1]);

    string::iterator headPtr = stringIn.begin();
    string::iterator temp, temp2;



    for(int i=1; i<stringIn.size(); i++){
        headPtr++;
        temp = headPtr;
        //Check for match in previous 3
        cout<<i<<" headPtr ["<<*headPtr<<"]"<<endl;
        for(int j=0; j<3; j++){
            temp--;
            cout<<"\t\t"<<j<<" "<<*temp;
            if(temp == stringIn.begin()){
                cout<<" -BREAK, start"<<endl;
                break;
            }
            else if(*temp==*headPtr){
                cout<<"- BREAK, match"<<endl;
                headPtr++;
                i+=(3-j);
                break;
            }
            else{
                if(j==2){
                    foundAnsFlag = 1;
                    ansAt = i;
                }
            }
            cout<<endl;
        }
        if(foundAnsFlag>0){
            cout<<"\t\t\t\t\tANS: "<<ansAt<<endl;
            break;
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