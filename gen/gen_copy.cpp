#include "testlib.h"
#include <climits>
#include <cassert>
#include <set>
#include <queue>
#include <utility>
using namespace std;

int main(int argc, char* argv[]) {  // gen_copy 1-01
    registerGen(argc, argv, 1);
    assert(argc == 2);
    string filename = argv[1];
    filename = "../tests/" + filename + ".in";
    ifstream inputFile(filename);
    vector<string> lines;
    assert(inputFile.is_open());

    std::string line;
    while (getline(inputFile, line)) { // 逐行讀取檔案
        lines.push_back(line); // 將每一行存入向量
    }

    inputFile.close(); // 關閉檔案

    lines[0].replace(lines[0].end() - 1, lines[0].end(), "2");

    for (const auto& updatedLine : lines) { // 將更新後的內容寫入新檔案
        cout << updatedLine << "\n";
    }
    return 0;
}
