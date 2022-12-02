/*Day2AoC.cpp*/
#include <iostream>
#include <fstream>
#include <vector>

int main(){
 
    std::ifstream inFile;
    inFile.open("p2_Input.txt");
    std::ofstream outFile;
    outFile.open("p2_Output.txt");

    int total=0;
    std::string line;

    while (std::getline(inFile, line)){
            //rock = 1, paper = 2, scissors =3
            //a(rock)x(scissors) +3 +0
            if(line == "A X"){
                total += 3;
            }
            
            //a(rock)y(rock) +1 +3
            if(line == "A Y"){
                    total += 4;
            }

            //a(rock)z(paper) +2 +6
            if(line == "A Z"){
                total += 8;
            }

            //b(paper)x(rock) +1 +0
            if(line == "B X"){
                total += 1;
            }

            //b(paper)y(paper) +2 +3
            if(line == "B Y"){
                    total += 5;
            }

            //b(paper)z(scissors) +3 +6
            if(line == "B Z"){
                    total += 9;
            }

            //c(scissors)x(paper) +2 +0
            if(line == "C X"){
                    total += 2;
            }

            //c(scissors)y(scissors) +3 +3
            if(line == "C Y"){
                total += 6;
            }

            //c(scissors)z(rock) = +1 +6
            if(line == "C Z"){
                total += 7;
            }
        }
        outFile<<"Total: "<<total<<"\n";
}