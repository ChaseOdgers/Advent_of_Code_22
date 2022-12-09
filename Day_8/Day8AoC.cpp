#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std::chrono;
using namespace std;

vector<vector<int>> loadVec(string input){
    ifstream in;
    vector<vector<int>> vec;
    in.open(input);
    string line;
    vector<int> tempVec;
    char c;
    int temp,row=0,col=0;
    vec.push_back(tempVec);
    while(in.get(c)){
        temp = int(c)-48;
        if(temp == -38){
            vec.push_back(tempVec);
            row++;
        }
        else{
            vec[row].push_back(temp);
        }
    }
    return vec;
}

void printBoard(vector<vector<int>> vec){
    cout<<"\t| col:";
    for(int i=0; i<vec[0].size(); i++){
        cout<<"\t"<<i;
    }
    cout<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    for(int i=0; i<vec.size(); i++){
        cout<<"Row: "<<i<<"\t|";
        for(int j=0; j<vec[i].size(); j++){
            cout<<"\t"<<vec[i][j];
        }
        cout<<endl;
    }
}

vector<vector<int>> genLeft(vector<vector<int>> vec,bool flag){
    vector<vector<int>> leftBoard=vec;

    if(flag == false){
        for(int row=0; row<vec.size(); row++){
            for(int col=0; col<vec[row].size(); col++){
                for(int i=col-1; i>=0; i--){
                    if(vec[row][i]>= vec[row][col]){
                        leftBoard[row][col] = -1;
                    }
                }
            }
        }
        return leftBoard;
    }

    if(flag==true){
        for(int row=0; row<vec.size(); row++){
            for(int col=0; col<vec[row].size(); col++){
                for(int i=col-1; i>=0; i--){
                    if(vec[row][i]>= vec[row][col]){
                        leftBoard[row][col] = -1;
                    }
                }
            }
        }
        return leftBoard;        
    }
}

vector<vector<int>> genRight(vector<vector<int>> vec,bool flag){
    vector<vector<int>> rightBoard=vec;

    if(flag == false){
        for(int row=0; row<vec.size(); row++){
            for(int col=0; col<vec[row].size(); col++){
                for(int i=col+1; i<vec[row].size(); i++){
                    if(vec[row][i] >= vec[row][col]){
                        rightBoard[row][col] = -1;
                    }
                } 
            }
        }
        return rightBoard;
    }

    if(flag==true){
        for(int row=0; row<vec.size(); row++){
            for(int col=0; col<vec[row].size(); col++){
                for(int i=col+1; i<vec[row].size(); i++){
                    if(vec[row][i] >= vec[row][col]){
                        rightBoard[row][col] = -1;
                    }
                } 
            }
        }
        return rightBoard;        
    }
}

vector<vector<int>> genUp(vector<vector<int>> vec,bool flag){
    vector<vector<int>> upBoard=vec;
    
    if(flag == false){
        for(int row=0; row<vec.size(); row++){
            for(int col=0; col<vec[row].size(); col++){
                for(int i=row-1; i>=0; i--){
                    if(vec[i][col] >= vec[row][col]){
                        upBoard[row][col] = -1;
                    }
                }
            }
        }
        return upBoard;
    }

    if(flag==true){
        for(int row=0; row<vec.size(); row++){
            for(int col=0; col<vec[row].size(); col++){
                for(int i=row-1; i>=0; i--){
                    if(vec[i][col] >= vec[row][col]){
                        upBoard[row][col] = -1;
                    }
                }
            }
        }
        return upBoard;
    }
}

vector<vector<int>> genDown(vector<vector<int>> vec,bool flag){
    vector<vector<int>> downBoard=vec;
    int distance=0;
    
    if(flag == false){
        for(int row=0; row<vec.size(); row++){
            for(int col=0; col<vec[row].size(); col++){
                for(int i=row+1; i<vec.size(); i++){
                    if(vec[i][col] >= vec[row][col]){
                        downBoard[row][col] = -1;
                    }
                }
            }
        }
        return downBoard;
    }

    if(flag==true){
        for(int row=0; row<vec.size(); row++){
            for(int col=0; col<vec[row].size(); col++){
                for(int i=row+1; i<vec.size(); i++){
                    if(vec[i][col] >= vec[row][col]){
                        downBoard[row][col] = -distance;
                    }
                }
                distance =0;
            }
        }
        return downBoard;
    }
}

int main(int argc, char *argv[]) {
    //Start Timer
    auto start = high_resolution_clock::now();

//////////////////////////////////////////////////////////////////////////

    vector<vector<int>> vec = loadVec(argv[1]);
    vector<vector<int>> leftBoard;
    vector<vector<int>> rightBoard;
    vector<vector<int>> upBoard;
    vector<vector<int>> downBoard;
    vector<vector<int>> visible = vec;

    leftBoard = genLeft(vec,1);
    rightBoard = genRight(vec,1);
    upBoard = genUp(vec,1);
    downBoard = genDown(vec,true);
    printBoard(downBoard);

    int visCount=0;

    for(int row=0; row<vec.size(); row++){
        for(int col=0; col<vec[row].size(); col++){
            if(leftBoard[row][col] >= 0){
                visible[row][col] = -1;
            }
            if(rightBoard[row][col] >= 0){
                visible[row][col] = -1;
            }
            if(upBoard[row][col] >= 0){
                visible[row][col] = -1;    
            }
            if(downBoard[row][col] >= 0){
                visible[row][col] = -1;
            }
        }
    }

    for(int row=0; row<vec.size(); row++){
        for(int col=0; col<vec[row].size(); col++){
            {
                if(visible[row][col]==-1){
                    visCount++;
                }
            }
        }
    }

    cout<<"\n\nVisible-\t"<<visCount<<endl;

/////////////////////////////////////////////////////////////////////////
    //Stop timer and print results
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop - start);
    cout<<"\nRuntime: \n"<<duration1.count()<<" milliseconds\n";
    auto duration2 = duration_cast<microseconds>(stop - start);    
    cout<<"Runtime: \n"<<duration2.count()<<" microseconds\n";

    return 0;
}