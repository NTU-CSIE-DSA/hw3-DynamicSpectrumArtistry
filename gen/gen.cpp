#include "testlib.h"
#include <climits>
#include <cassert>
#include <set>
#include <queue>
#include <utility>
using namespace std;

int main(int argc, char* argv[]) {  // gen MAX_V MAX_E SCC_count
    registerGen(argc, argv, 1);
    assert(argc == 4);
    int V = atoi(argv[1]);
    int E = atoi(argv[2]);
    int SCC = atoi(argv[3]);
    // 加點隨機東東，不然數字太好看會被猜？
    SCC += rnd.next(-2, 2);
    assert(E <= V * (V - 1));
    cout << V << " "; // 還沒輸出E和mode，最後記得！
    vector<vector<int>> SCC_Graph;
    set<pair<int, int>> Edge;
    for(int i = 0; i < SCC; i++) SCC_Graph.push_back({});
    // 先決定哪些點在哪個顏色裡面
    for(int i = 1; i <= V; i++){
        int color = rnd.next(0, SCC - 1);
        SCC_Graph[color].push_back(i);
    }
    // 打亂順序之後造環
    for(int i = 0; i < SCC; i++){
        if(SCC_Graph[i].size() == 0) continue;
        shuffle(SCC_Graph[i].begin() + 1, SCC_Graph[i].end());
        for(int j = 0; j < SCC_Graph[i].size() - 1; j++){
            Edge.insert({SCC_Graph[i][j], SCC_Graph[i][j + 1]});
        }
        if(SCC_Graph[i].size() > 1) Edge.insert({SCC_Graph[i][SCC_Graph[i].size() - 1], SCC_Graph[i][0]});
    }
    // 建邊 => 先指定SCC1->SCC2，再分別從1和2各抓一個node出來，1和2可以接受一樣，不然SCC內都是單純的環
    int failed = 0; // 如果一直選到重複的邊就算了
    while(Edge.size() < E && failed <= 10000){
        int SCC1 = rnd.next(0, SCC - 1);
        int SCC2 = rnd.next(0, SCC - 1);
        // 只能小->大 or 一樣，不然會少SCC
        if(SCC1 > SCC2){
            int tmp = SCC1;
            SCC1 = SCC2;
            SCC2 = tmp;
        }
        // 檢查是否為空
        if(SCC_Graph[SCC1].size() == 0 || SCC_Graph[SCC2].size() == 0) continue;
        // 如果 SCC1 = SCC2 但裡面東西不夠，也要出來
        if(SCC_Graph[SCC1].size() == 1 && SCC1 == SCC2) continue;
        int s = rnd.any(SCC_Graph[SCC1]);
        int e = rnd.any(SCC_Graph[SCC2]);
        if(s != e && Edge.count({s, e}) == 0) Edge.insert({s, e});
        else failed += 1;
    }
    cout << Edge.size() << " 1\n";
    for(const auto &s : Edge){
        cout << s.first << " " << s.second << "\n";
    }
    return 0;
}
