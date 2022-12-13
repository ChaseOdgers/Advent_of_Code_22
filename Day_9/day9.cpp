#include "day9.hpp"

//Class creation
Day9::Day9(){}
Day9::Day9(string input){
    inFileName = input;

    //Initialize the head vector
    headROW.push_back(0);
    headCOL.push_back(0);

    //initialize the tail vector
    tailROW.push_back(0);
    tailCOL.push_back(0);

    //mark start as visited
    visited.insert({0,0});
}
Day9::~Day9(){}

//Vector of tuple<int, char> - holds all the moves
void Day9::run(){
    ifstream in;
    in.open(inFileName);
    char c;
    int i;
    string line;
    while(getline(in,line)){
        c = line[0];
        i = stoi(line.substr(2));
        switch(c){
            case 'L':
                moveLeft(i);
                break;
            case 'R':
                moveRight(i);
                break;
            case 'D':
                moveDown(i);
                break;
            case 'U':
                moveUp(i);
                break;
        }
    }
}

//Handle moves from run()
void Day9::moveLeft(int i){
    //i is the ammount of spaces the head is to move
    for(int moveCount=0; moveCount<i; moveCount++){
        //increment the head 1 at a time
        headROW.push_back(headROW.back());
        headCOL.push_back(headCOL.back() - 1);

        //increment the tail after the heads first move
        newPrint(i, "Left", moveCount,1);
        // if(moveCount>0){tailUPDATE("Left");}
        tailUPDATE("Left");
        newPrint(i, "Left", moveCount,2);
    }
}
void Day9::moveRight(int i){
    //i is the ammount of spaces the head is to move
    for(int moveCount=0; moveCount<i; moveCount++){
        //increment the head 1 at a time
        headROW.push_back(headROW.back());
        headCOL.push_back(headCOL.back() + 1);

        //increment the tail after the heads first move
        newPrint(i, "Right", moveCount,1);
        // if(moveCount>0){tailUPDATE("Right");}
        tailUPDATE("Right");
        newPrint(i, "Right", moveCount,2);
    }
}
void Day9::moveUp(int i){
    //i is the ammount of spaces the head is to move
    for(int moveCount=0; moveCount<i; moveCount++){
        //increment the head 1 at a time
        headROW.push_back(headROW.back() + 1);
        headCOL.push_back(headCOL.back());

        //increment the tail after the heads first move
        newPrint(i, "Up", moveCount, 1);
        // if(moveCount>0){tailUPDATE("Up");}
        tailUPDATE("Up");
        newPrint(i, "Up", moveCount, 2);
    }
}
void Day9::moveDown(int i){
    for(int moveCount=0; moveCount<i; moveCount++){
        //increment the head 1 at a time
        headROW.push_back(headROW.back() - 1);
        headCOL.push_back(headCOL.back());

        //increment the tail after the heads first move
        newPrint(i, "Down", moveCount, 1);
        // if(moveCount>0){tailUPDATE("Down");}
        tailUPDATE("Down");
        newPrint(i, "Down", moveCount,2 );
    }
}

void Day9::tailUPDATE(string move){
    int rowH = headROW.back();
    int colH = headCOL.back();
    int rowT = tailROW.back();
    int colT = tailCOL.back();

    if((rowT) < (rowH - 1)){

        /*  incROW
            {{H H H H H},
            {x x x x x},
            {x x T x x},
            {x x x x x},
            {x x x x x};}
        */
        tailROW.push_back(tailROW.back()+1);

        /*  incCOL 
            {x x x H H}
            {x x x x x}
            {x x T x x}
            {x x x x x}
            {x x x x x}  */
        if(colT < colH){
            tailCOL.push_back(tailCOL.back()+1);
            visited.insert({tailROW.back(),tailCOL.back()});
        }

        /*  decCOL
            {H H x x x}
            {x x x x x}
            {x x T x x}
            {x x x x x}
            {x x x x x}    */        
        else if(colT > colH){
            tailCOL.push_back(tailCOL.back()-1);
            visited.insert({tailROW.back(),tailCOL.back()});
        }

        /*  colT stay
            {x x H x x}
            {x x x x x}
            {x x T x x}
            {x x x x x}
            {x x x x x}    */
        else{
            tailCOL.push_back(tailCOL.back());
            visited.insert({tailROW.back(),tailCOL.back()});
        }
    }

    else if(rowT > (rowH + 1)){
        /*  decROW 
            {x x x x x}
            {x x x x x}
            {x x T x x}
            {x x x x x}
            {x H H H x}     */        
        tailROW.push_back(tailROW.back()-1);

        /*  incCOL
            {x x x x x}
            {x x x x x}
            {x x T x x}
            {x x x x x}
            {x x x H x}    */
        if(colT < colH){
            tailCOL.push_back(tailCOL.back()+1);
            visited.insert({tailROW.back(),tailCOL.back()});
        }

        /*  decCOL
            {x x x x x}
            {x x x x x}
            {x x T x x}
            {x x x x x}
            {x H x x x}    */
        else if(colT > colH){
            tailCOL.push_back(tailCOL.back()-1);
            visited.insert({tailROW.back(),tailCOL.back()});
        }

        /*  colT stay
            {x x x x x}
            {x x x x x}
            {x x T x x}
            {x x x x x}
            {x x H x x}    */
        else{
            tailCOL.push_back(tailCOL.back());
            visited.insert({tailROW.back(),tailCOL.back()});
        }
    }

    else if(colT < (colH - 1)){
        
        /*  incCOl
            {x x x x x}
            {x x x x H}
            {x x T x H}
            {x x x x H}
            {x x x x x}    */
        tailCOL.push_back(tailCOL.back()+1);

        /*  incROW 
            {x x x x x}
            {x x x x H}
            {x x T x x}
            {x x x x x}
            {x x x x x}    */
        if(rowT < rowH){   
            tailROW.push_back(tailROW.back()+1);
            visited.insert({tailROW.back(),tailCOL.back()});
        }

        /*  decROW
            {x x x x x}
            {x x x x x}
            {x x T x x}
            {x x x x H}
            {x x x x x}    */
        else if(rowT > rowH){
            tailROW.push_back(tailROW.back()-1);
            visited.insert({tailROW.back(),tailCOL.back()});
        }

        /*  rowT stay
            {x x x x x}
            {x x x x x}
            {x x T x H}
            {x x x x x}
            {x x x x x}    */
        else{
            tailROW.push_back(tailROW.back());
            visited.insert({tailROW.back(),tailCOL.back()});
        }
    }

    else if(colT > (colH + 1)){
        
        /*  decCOL    
            {x x x x x}
            {H x x x x}
            {H x T x x}
            {H x x x x}
            {x x x x x}    */
        tailCOL.push_back(tailCOL.back()-1);

        /*  incROW
            {x x x x x}
            {H x x x x}
            {x x T x x}
            {x x x x x}
            {x x x x x}    */
        if(rowT < rowH){
            tailROW.push_back(tailROW.back()+1);
            visited.insert({tailROW.back(),tailCOL.back()});
        }

        /*  decROW
            {x x x x x}
            {x x x x x}
            {x x T x x}
            {H x x x x}
            {x x x x x}    */
        else if(rowT > rowH){
            tailROW.push_back(tailROW.back()-1);
            visited.insert({tailROW.back(),tailCOL.back()});
        }

        /*  rowT stay
            {x x x x x}
            {x x x x x}
            {H x T x x}
            {x x x x x}
            {x x x x x}    */
        else{
            tailROW.push_back(tailROW.back());
            visited.insert({tailROW.back(),tailCOL.back()});
        }
    
    }

    else{}

}

void Day9::newPrint(int in, string move, int moveCount, int place){
    if(place == 1){
        if(moveCount == 0){cout<<endl<<move<<" "<<in<<endl;}
        cout<<"\t"<<moveCount<<" - |Head r:"<<headROW.back()<<" c:"<<headCOL.back()<<" ";
        cout<<" |Tail r:"<<tailROW.back()<<" c:"<<tailCOL.back()<<endl;
    }
    if(place == 2){
        cout<<"\t\t\t          r:"<<tailROW.back()<<" c:"<<tailCOL.back()<<" <-updated"<<endl;
    }
}

int Day9::getSetSize(){
    return visited.size();
}

void Day9::print8()
{ 
  // Iterating over unordered set elements
  for (auto currentPair : visited)
  {
    // Each element is a pair itself
    pair<int, int> pr = currentPair;
  
    cout << "[ ";
  
    // Printing pair elements
    cout << pr.first << "  " << 
            pr.second;
    cout << " ]";
    cout << "\n";
  }
}