#include "testlib.h"
#include <climits>
#include <cassert>
#include <set>
#include <queue>
#include <utility>
using namespace std;

int main(int argc, char* argv[]) {  // gen MAX_V MAX_E
    registerGen(argc, argv, 1);
    assert(argc == 3);
    int V = atoi(argv[1]);
    int E = atoi(argv[2]);
    assert(E <= V * (V - 1));
    cout << V << " " << E << " 1" << '\n';

    if(E / V > V / 2){ // 抽不要的
        set<pair<int, int>> edge_set;
        for(int i = 1; i <= V; i++){
            for(int j = 1; j <= V; j++){
                if(i != j) edge_set.insert({i, j});
            }
        }
        int remove_count = edge_set.size() - E;
        for(int i = 0; i < remove_count; i++){
            bool repeat_edge = 1;
            while(repeat_edge){
                int start = rnd.next(1, V), end = 0;
                bool repeat_node = 1;
                while(repeat_node){
                    end = rnd.next(1, V);
                    if(start != end) repeat_node = 0;
                }
                if(edge_set.count({start, end})){
                    edge_set.erase({start, end});
                    repeat_edge = 0;
                }
            }
        }
        for (const auto &s : edge_set) {
            cout << s.first << " " << s.second << "\n";
        }
    }
    else{ // 抽要的
        set<pair<int, int>> edge_set;
        for(int i = 0; i < E; i++){
            bool repeat_edge = 1;
            while(repeat_edge){
                int start = rnd.next(1, V), end = 0;
                bool repeat_node = 1;
                while(repeat_node){
                    end = rnd.next(1, V);
                    if(start != end) repeat_node = 0;
                }
                if(!edge_set.count({start, end})){
                    edge_set.insert({start, end});
                    repeat_edge = 0;
                    cout << start << " " << end << "\n";
                }
            }
        }
    }
    return 0;
}
