#include "testlib.h"
#include <climits>
#include <cassert>
#include <set>
#include <queue>
#include <utility>
using namespace std;

int main(int argc, char* argv[]) {  // gen_dag MAX_V MAX_E
    registerGen(argc, argv, 1);
    assert(argc == 3);
    int V = atoi(argv[1]);
    int E = atoi(argv[2]);
    vector<int> vertex;
    set<pair<int, int>> Edge;
    for(int i = 1; i <= V; i++) vertex.push_back(i);
    shuffle(vertex.begin() + 1, vertex.end());
    int failed = 0;
    while(Edge.size() < E && failed <= 10000){
        int p1 = rnd.next(0, V - 1);
        int p2 = rnd.next(0, V - 1);
        if(p1 > p2){
            int tmp = p1;
            p1 = p2;
            p2 = tmp;
        }
        p1 = vertex[p1];
        p2 = vertex[p2];
        if(p1 == p2 || Edge.count({p1, p2})){
            failed += 1;
            continue;
        }
        Edge.insert({p1, p2});
    }
    cout << V << " " << Edge.size() << " 1\n";
    for(const auto &s : Edge) {
        std::cout << s.first << " " << s.second << "\n";
    }
    return 0;
}
