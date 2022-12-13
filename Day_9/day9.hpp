#ifndef DAY9_HPP
#define DAY9_HPP

#include <vector>
#include <fstream>
#include <string>
#include <set>
#include <unordered_set>
#include <iostream>
#include <utility>
using namespace std;

class Day9
{
    public:
        Day9();
        Day9(string input);
        ~Day9();

        void headUPDATE(int row, int col);

        void tailUPDATE(string move);

        void run();

        void moveLeft(int i);
        void moveRight(int i);
        void moveUp(int i);
        void moveDown(int i);

        void newPrint(int in, string move, int moveCount,int place);

        int getSetSize();

        void print8();

        struct hashFunction
        {
            size_t operator()(const pair<int ,int> &x) const
            {
                return x.first ^ x.second;
            }
        };


    private:
        int m_value;
        bool isFirstMove = true;
        string inFileName;
        vector<int> headROW,tailROW, headCOL,tailCOL;
        unordered_set<pair<int, int>,hashFunction> visited;
};

#endif // MYCLASS_H