#include "testlib.h"
#include <climits>
#include <cassert>
#include <set>
#include <queue>
#include <utility>
using namespace std;

int main(int argc, char* argv[]) {  // gen_dag MAX_V mode, 1 is singly and 2 is doubly
    registerGen(argc, argv, 1);
    assert(argc == 3);
    int V = atoi(argv[1]);
    int mode = atoi(argv[2]);
    vector<int> vertex;
    for(int i = 1; i <= V; i++) vertex.push_back(i);
    shuffle(vertex.begin() + 1, vertex.end());
    if(mode == 1){
        cout << V << " " << V - 1 << " 1\n";
        for(int i = 0; i < vertex.size() - 1; i++){
            cout << vertex[i] << " " << vertex[i + 1] << "\n";
        }
    }
    if(mode == 2){
        cout << V << " " << 2 * (V - 1) << " 1\n";
        for(int i = 0; i < vertex.size() - 1; i++){
            cout << vertex[i] << " " << vertex[i + 1] << "\n";
            cout << vertex[i + 1] << " " << vertex[i] << "\n";
        }
    }
    return 0;
}
