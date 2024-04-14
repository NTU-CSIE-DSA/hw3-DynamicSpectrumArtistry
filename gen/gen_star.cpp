#include "testlib.h"
#include <climits>
#include <cassert>
#include <set>
#include <queue>
#include <utility>
using namespace std;

int main(int argc, char* argv[]) {  // gen_star MAX_V {in or out}
    registerGen(argc, argv, 1);
    assert(argc == 3);
    int V = atoi(argv[1]);
    string op = argv[2];
    cout << V << " " << V - 1 << " 1\n";
    vector<int> vertex;
    int center = rnd.next(1, V);
    for(int i = 1; i <= V; i++){
        if(i != center) vertex.push_back(i);
    }
    shuffle(vertex.begin() + 1, vertex.end());
    for(int i = 0; i < vertex.size(); i++){
        if(op == "in") cout << vertex[i] << " " << center << "\n";
        else cout << center << " " << vertex[i] << "\n";
    }
    return 0;
}
