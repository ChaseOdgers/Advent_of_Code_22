#ifndef DAY9_HPP
#define DAY9_HPP

#include <vector>
#include <fstream>
#include <string>
#include <unordered_set>
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;


class Day9
{
    private:
        struct hashFunction{
            size_t operator()(const pair<int ,int> &x) const {
                return x.first ^ x.second;
            }
        };

        struct Node{
            int nodeNum;
            vector<int> row;
            vector<int> col;
            unordered_set<pair<int, int>,hashFunction> visited;

            Node *next;

        };

        string inFileName;
        Node* head,tail;
        unordered_set<pair<int, int>,hashFunction> visited;

    public:
        Day9();
        Day9(string input, int numTails);
        ~Day9();

        void headUPDATE(char c, int i);
        bool tailUPDATE(Node* head, Node* tail);

        void run();

        void moveLeft(int i);
        void moveRight(int i);
        void moveUp(int i);
        void moveDown(int i);

        void printResults();

            // Helper function to create a new node
        Node* newNode(const std::vector<int> &row, const std::vector<int> &col, int nodeNum)
        {
            Node *temp = new Node;
            temp->nodeNum = nodeNum;
            temp->row = row;
            temp->col = col;
            temp->next = nullptr;
            return temp;
        }
};

#endif