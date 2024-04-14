#include "testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
    // This command initializes checker environment.
    registerTestlibCmd(argc, argv);
    // Now there are three global variables specifying testlib streams:
    // inf - stream with the testdata.
    // ouf - stream with the contestant output.
    // ans - stream with the jury answer.
    // All those streams provide the similar interface for reading data.

    // This function reads a single integer from the participant output that 
    // should be between -2000 and 2000. If it doesn't belong to the specified
    // range, checker finishes with verdict _pe and comment saying that [sum of numbers]
    // is outside of the specified range.
    
    // This function reads a single integer from the jury output. Here we suppose
    // that jury's answer is correct and we do not need to additionally verify it.
    
    double part_score = 0.4;
    int a1 = ans.readInt(); // We suppose that jury's answer is correct
    ans.readEoln();
    int a2 = ans.readInt();
    ans.readEoln();
    ans.readEof();

    int p1 = ouf.readInt();
    ouf.readEoln();
    if(ouf.seekEof()){
        ouf.readEof();
        if(p1 == a1) quitp(part_score);
        quitf(_wa, "Wrong");
    }

    int p2 = ouf.readInt();
    ouf.readEoln();
    ouf.readEof();
    
    if(p1 == a1){
        if(p2 == a2){
            quit(_ok, "Correct"); // This finishes checker with verdit OK.
        }
        else{
            quitp(part_score);
        }
    }
    else
        // quitf handles a comment like printf, i. e. you may use specifiers like
        // %d, %s etc in the comment.
        quitf(_wa, "Wrong");
}
