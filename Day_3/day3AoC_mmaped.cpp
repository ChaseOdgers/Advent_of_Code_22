#include <streambuf>
#include <string>
#include <istream>
#include <iterator>
#include <chrono>
using namespace std;

string readFile2(const string &fileName)
{
    ifstream ifs(fileName.c_str(), ios::in | ios::binary | ios::ate);

    ifstream::pos_type fileSize = ifs.tellg();
    ifs.seekg(0, ios::beg);

    vector<char> bytes(fileSize);
    ifs.read(bytes.data(), fileSize);

    return string(bytes.data(), fileSize);
}

int main(){
    std::string str(std::istreambuf_iterator<char>{ifs}, {});
}