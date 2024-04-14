#include "testlib.h"
#include <assert.h>
#include <unordered_set>
using namespace std;

int main() {
    registerValidation();
    int V = inf.readInt(1, 1e3);
    inf.readSpace();
    int E = inf.readInt(1, 1e6);
    inf.readSpace();
    int mode = inf.readInt(1, 2);
    inf.readEoln();
    ensure(E <= V * (V + 1));
    ensure(mode == 2);
    set<pair<int, int>> edge_set;
    for(int i = 0; i < E; i++){
        int start = inf.readInt(1, V);
        inf.readSpace();
        int end = inf.readInt(1, V);
        inf.readEoln();
        ensure(start != end);
        ensure(!edge_set.count({start, end}));
        edge_set.insert({start, end});
    }
    inf.readEof();
    return 0;
}
