#include "day9.hpp"

//Constructors/destructor
Day9::Day9(){}
Day9::Day9(string input, int numTails){
    inFileName = input;

    //Initialize the head node
    vector<int> row({0}), col({0});

    head = newNode(row, col,0);
    head->visited.insert({0,0});

    //Initialize the rest of the nodes (numTails - 1 bc we already created the first node)
    Node *curr = head;
    for(int i=1; i<numTails; i++){
        curr->next = newNode(row,col,i);
        curr->next->visited.insert({0,0});
        curr = curr->next;
    }

/*
    Print the number of nodes created
    // int nodeCount=0;
    // for (Node *curr = head; curr != nullptr; curr = curr->next){
    //     cout<<nodeCount<<endl;
    //     nodeCount++;
    // }

    //Initialize the head vector
    // headROW.push_back(0);
    // headCOL.push_back(0);

    // //initialize the tail vector
    // tail->row.push_back(0);
    // tail->col.push_back(0);

    //mark start as visited
    // visited.insert({0,0});

*/
}
/*
    prevent leaving nodes in memory
*/
Day9::~Day9(){
    Node* current = head;
    while( current != nullptr ) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

/*
    Run reads line by line from argv[1] in main
    - calls respective move(left/right/up/down) with the ammount of spaces the head is to move
*/
void Day9::run(){
    ifstream in;
    in.open(inFileName);
    char c;
    int i;
    string line;
    while(getline(in,line)){
        c = line[0];
        i = stoi(line.substr(2));
        headUPDATE(c, i);
    }
}

void Day9::headUPDATE(char c, int i){
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

/*
move(left/right/up/down) take in int of spaces to move from run()
    -moves head accordingly
    -updates tail after the head moves
*/
void Day9::moveLeft(int i){
    for(int moveCount=0; moveCount<i; moveCount++){

        head->row.push_back(head->row.back());
        head->col.push_back(head->col.back()-1);
        head->visited.insert({head->row.back(),head->col.back()});

        while(!tailUPDATE(head, head->next));
    }
}
void Day9::moveRight(int i){
    for(int moveCount=0; moveCount<i; moveCount++){

        head->row.push_back(head->row.back());
        head->col.push_back(head->col.back()+1);
        head->visited.insert({head->row.back(),head->col.back()});

        while(!tailUPDATE(head, head->next));

    }
}
void Day9::moveUp(int i){
    for(int moveCount=0; moveCount<i; moveCount++){

        head->row.push_back(head->row.back() + 1);
        head->col.push_back(head->col.back());
        head->visited.insert({head->row.back(),head->col.back()});

        while(!tailUPDATE(head, head->next));
    }
}
void Day9::moveDown(int i){
    for(int moveCount=0; moveCount<i; moveCount++){

        head->row.push_back(head->row.back() - 1);
        head->col.push_back(head->col.back());
        head->visited.insert({head->row.back(),head->col.back()});

        while(!tailUPDATE(head, head->next));
    }
}

/*
    Checks tails relation to head, moving tail if necessary
    if tail moves the move is added to the unordered_set 'visited' 
*/
bool Day9::tailUPDATE(Node* prev, Node* tailIN){
    if(tailIN == nullptr){
        return true;
    }
    
    else{
        int rowH = prev->row.back();
        int colH = prev->col.back();
        int rowT = tailIN->row.back();
        int colT = tailIN->col.back();

        /*  incROW
            {{H H H H H},
            {x x x x x},
            {x x T x x},
            {x x x x x},
            {x x x x x};}
        */
        if((rowT) < (rowH - 1)){

            tailIN->row.push_back(tailIN->row.back()+1);

            /*  incCOL 
                {x x x H H}
                {x x x x x}
                {x x T x x}
                {x x x x x}
                {x x x x x}  */
            if(colT < colH){
                tailIN->col.push_back(tailIN->col.back()+1);
                tailIN->visited.insert({tailIN->row.back(),tailIN->col.back()});
            }

            /*  decCOL
                {H H x x x}
                {x x x x x}
                {x x T x x}
                {x x x x x}
                {x x x x x}    */        
            else if(colT > colH){
                tailIN->col.push_back(tailIN->col.back()-1);
                tailIN->visited.insert({tailIN->row.back(),tailIN->col.back()});
            }

            /*  colT stay
                {x x H x x}
                {x x x x x}
                {x x T x x}
                {x x x x x}
                {x x x x x}    */
            else{
                tailIN->col.push_back(tailIN->col.back());
                tailIN->visited.insert({tailIN->row.back(),tailIN->col.back()});
            }
        }

        /*  decROW 
            {x x x x x}
            {x x x x x}
            {x x T x x}
            {x x x x x}
            {x H H H x}     */        
        else if(rowT > (rowH + 1)){
            tailIN->row.push_back(tailIN->row.back()-1);

            /*  incCOL
                {x x x x x}
                {x x x x x}
                {x x T x x}
                {x x x x x}
                {x x x H x}    */
            if(colT < colH){
                tailIN->col.push_back(tailIN->col.back()+1);
                tailIN->visited.insert({tailIN->row.back(),tailIN->col.back()});
            }

            /*  decCOL
                {x x x x x}
                {x x x x x}
                {x x T x x}
                {x x x x x}
                {x H x x x}    */
            else if(colT > colH){
                tailIN->col.push_back(tailIN->col.back()-1);
                tailIN->visited.insert({tailIN->row.back(),tailIN->col.back()});
            }

            /*  colT stay
                {x x x x x}
                {x x x x x}
                {x x T x x}
                {x x x x x}
                {x x H x x}    */
            else{
                tailIN->col.push_back(tailIN->col.back());
                tailIN->visited.insert({tailIN->row.back(),tailIN->col.back()});
            }
        }

        /*  incCOl
            {x x x x x}
            {x x x x H}
            {x x T x H}
            {x x x x H}
            {x x x x x}    */
        else if(colT < (colH - 1)){
            
            tailIN->col.push_back(tailIN->col.back()+1);

            /*  incROW 
                {x x x x x}
                {x x x x H}
                {x x T x x}
                {x x x x x}
                {x x x x x}    */
            if(rowT < rowH){   
                tailIN->row.push_back(tailIN->row.back()+1);
                tailIN->visited.insert({tailIN->row.back(),tailIN->col.back()});
            }

            /*  decROW
                {x x x x x}
                {x x x x x}
                {x x T x x}
                {x x x x H}
                {x x x x x}    */
            else if(rowT > rowH){
                tailIN->row.push_back(tailIN->row.back()-1);
                tailIN->visited.insert({tailIN->row.back(),tailIN->col.back()});
            }

            /*  rowT stay
                {x x x x x}
                {x x x x x}
                {x x T x H}
                {x x x x x}
                {x x x x x}    */
            else{
                tailIN->row.push_back(tailIN->row.back());
                tailIN->visited.insert({tailIN->row.back(),tailIN->col.back()});
            }
        }

        /*  decCOL    
        {x x x x x}
        {H x x x x}
        {H x T x x}
        {H x x x x}
        {x x x x x}    */
        else if(colT > (colH + 1)){

            tailIN->col.push_back(tailIN->col.back()-1);

            /*  incROW
                {x x x x x}
                {H x x x x}
                {x x T x x}
                {x x x x x}
                {x x x x x}    */
            if(rowT < rowH){
                tailIN->row.push_back(tailIN->row.back()+1);
                tailIN->visited.insert({tailIN->row.back(),tailIN->col.back()});
            }

            /*  decROW
                {x x x x x}
                {x x x x x}
                {x x T x x}
                {H x x x x}
                {x x x x x}    */
            else if(rowT > rowH){
                tailIN->row.push_back(tailIN->row.back()-1);
                tailIN->visited.insert({tailIN->row.back(),tailIN->col.back()});
            }

            /*  rowT stay
                {x x x x x}
                {x x x x x}
                {H x T x x}
                {x x x x x}
                {x x x x x}    */
            else{
                tailIN->row.push_back(tailIN->row.back());
                tailIN->visited.insert({tailIN->row.back(),tailIN->col.back()});
            }
        
        }

        else{}

        return (tailUPDATE(tailIN, tailIN->next));
    }
}

/*
    returns the ammount of tail->visited spaces from unordered_set 'tail->visited'
*/
void Day9::printResults(){
    for (Node *curr = head; curr != nullptr; curr = curr->next){
        cout<<"\nnode: "<<curr->nodeNum<<endl;
        cout<<"Node visited count: "<<curr->visited.size()<<endl;
    }
}
