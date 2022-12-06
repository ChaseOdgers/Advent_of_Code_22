#include <ctime>
#include <iostream>
#include <fstream>
#include <unistd.h>

std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

int main(int argc, char *argv[]) {

    std::ofstream outFile;
    outFile.open("input_100000000.txt");

    srand((unsigned)time(NULL) * getpid());
    for(int i=0; i<100000000; i++){     
        outFile<<gen_random(50)<< "\n";
    }



    return 0;
}