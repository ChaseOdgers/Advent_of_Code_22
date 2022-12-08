#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std::chrono;
using namespace std;

vector<int> loadInto2dVec(string input){
    string line;
    std::vector<int> vec;
    ifstream in;
    in.open(input);
    while(getline(in,line)){
        vec.push_back(line);
    }
    return vec;
}

void printBoard(vector<int> vec){
    int flag = -1;
    for(int row=0; row<vec.size(); row++){
        cout<<"row | "<<row<<" | ";
        for(int col=0; col<vec[row].size(); col++){
            cout<<" "<<vec[row][col];
        }
        cout<<endl;
    }
}

vector<int> markEdges(vector<int> vec){
    vector<int> answerKeyEdge=vec;
    for(int row=0; row<vec.size(); row++){
        for(int col=0; col<vec[row].size(); col++){
            //mark all edges as visible
            if((row == 0)||(col == 0)||(row == vec.size()-1)||(col== vec[row].size()-1)){
                answerKeyEdge[row][col] = -1;
            }
            else{
                answerKeyEdge[row][col] = vec[row][col];
            }
        }
    }
    return answerKeyEdge;
}

vector<int> markLeft(vector<int> vec){
    vector<int> answerKeyLeft=vec;
    int temp, int1, int2;
    for(int row=0; row<vec.size(); row++){
        for(int col=0; col<vec[row].size(); col++){
            if((row == 0)||(col == 0)||(row == vec.size()-1)||(col== vec[row].size()-1)){
            }

            else{
                for(int i=0; i<col; i++){
                    int1 = vec[row][i];
                    int2 = vec[row][col];
                    cout<<"1: "<<int1<<" 2: "<<int2;
                    if(int1 > int2){
                        vec[row][col] = 'b';
                    }
                }
            }
        }
    }
    return answerKeyLeft;
}

int main(int argc, char *argv[]) {
    //Start Timer
    auto start = high_resolution_clock::now();

    //-----LOAD DATA
    vector<int> vec = loadInto2dVec(argv[1]);
    vector<int> answerKeyLeft = vec;
    vector<int> answerKeyRight = vec;
    vector<int> answerKeyUp = vec;
    vector<int> answerKeyDown = vec;
    vector<int> answerKeyEdge = vec;
    char surround;
    int temp;
//////////////////////////////////////////////////////////////////////////

    // printBoard(vec);
    // cout<<"----------------------"<<endl;


    answerKeyEdge = markEdges(vec);
    cout<<"---------------------"<<endl;
    cout<<"Edges      0 1 2 3 4 "<<endl;
    cout<<"---------------------"<<endl;
    printBoard(answerKeyEdge);

    // answerKeyLeft = markLeft(vec);
    // cout<<"---------------------"<<endl;
    // cout<<"Left       0 1 2 3 4 "<<endl;
    // cout<<"---------------------"<<endl;
    // printBoard(answerKeyLeft);
    // for(int row=0; row<vec.size(); row++){
    //     for(int col=0; col<vec[row].size(); col++){
    //         //mark all edges as visible
    //         if((row == 0)||(col == 0)||(row == vec.size()-1)||(col== vec[row].size()-1)){
    //             answerKeyEdge[row][col] = 'v';
    //         }
    //         else{
    //             answerKeyEdge[row][col] = vec[row][col];
    //         }
    //         else{
    //             //check left
    //             for(int i=col; i>0; i--){
    //                 temp = static_cast<int>(vec[row][i]);
    //                 if(vec[row][col]>temp){
    //                     cout<<"Tree at: [r"<<row<<"]"<<" [c"<<col<<"]\t ["<<vec[row][i]<<"]"<<endl;
    //                     cout<<"\t...blocked by [r"<<row<<"] [c"<<i<<"] on left"<<endl;
    //                     answerKey[row][col] = 'z';
    //                 }
    //                 else{
    //                     answerKey[row][col] = 'b';
    //                 }
    //             }
                //check right
                // for(int i=col; i<vec[row].size(); i++){
                //     temp = static_cast<int>(vec[row][i]);
                //     if(vec[row][col]>temp){
                //         cout<<"Tree at: [r"<<row<<"]"<<" [c"<<col<<"]\t ["<<vec[row][i]<<"]"<<endl;
                //         cout<<"\t...blocked by [r"<<row<<"] [c"<<i<<"] on left"<<endl;
                //         answerKey[row][col] = 'v';
                //     }
                //     else{
                //         answerKey[row][col] = 'b';
                //     }
                // }
                //check down 
                // for(int i=row; i<vec.size(); i++){
                //     temp = static_cast<int>(vec[i][col]);
                //     if(vec[i][col]>temp){
                //         cout<<"Tree at: [r"<<row<<"]"<<" [c"<<col<<"]\t ["<<vec[row][i]<<"]"<<endl;
                //         cout<<"\t...blocked by [r"<<row<<"] [c"<<i<<"] on left"<<endl;
                //         answerKey[row][col] = '';
                //     }
                //     else{
                //         answerKey[row][col] = 'b';
                //     }
                // }
                //check down
                // for(int i=row; i>0; i--){
                //     temp = static_cast<int>(vec[i][col]);
                //     if(vec[i][col]>temp){
                //         cout<<"Tree at: [r"<<row<<"]"<<" [c"<<col<<"]\t ["<<vec[row][i]<<"]"<<endl;
                //         cout<<"\t...blocked by [r"<<row<<"] [c"<<i<<"] on left"<<endl;
                //         answerKey[row][col] = 'v';
                //     }
                //     else{
                //         answerKey[row][col] = 'b';
                //     }
                // }

    // cout<<"\n---------------------"<<endl;
    // cout<<"Input      0 1 2 3 4 "<<endl;
    // cout<<"---------------------"<<endl;
    // printBoard(vec);

    // cout<<"\n\n---------------------"<<endl;
    // cout<<"Output     0 1 2 3 4 "<<endl;
    // cout<<"---------------------"<<endl;
    // printBoard(answerKey);
    // cout<<"---------------------"<<endl;


/////////////////////////////////////////////////////////////////////////
    //Stop timer and print results
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop - start);
    cout<<"\nRuntime: \n"<<duration1.count()<<" milliseconds\n";
    auto duration2 = duration_cast<microseconds>(stop - start);    
    cout<<"Runtime: \n"<<duration2.count()<<" microseconds\n";

    return 0;
}