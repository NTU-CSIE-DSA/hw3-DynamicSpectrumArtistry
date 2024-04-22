#include "testlib.h"
#include <climits>
#include <cassert>
#include <set>
#include <queue>
#include <utility>
using namespace std;

int main(int argc, char* argv[]) {  // gen_k V
    registerGen(argc, argv, 1);
    assert(argc == 2);
    int V = atoi(argv[1]);
    int E = V * (V - 1);
    cout << V << " " << E << " 1\n";
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(i != j) cout << i << " " << j << "\n";
        }
    }
    return 0;
}
