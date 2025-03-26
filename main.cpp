/*
Simple Classic Neural Newtork with backprogration
*/

/*TEST EARLY AND TEST OFTEN*/

#include <iostream>
#include <vector>
using namespace std;

class Net
{
private:
    /* data */
public:
    Net(const vector<unsigned> topology) {};
    void feedForward(const vector<double> &inputVals) {};
    void backProp(const vector<double> &targetVals) {};
    void getResults(const vector<double> &resultVals) const {};
};

int main()
{
    vector<unsigned> topology;
    vector<double> inputVals;

    Net myNet(topology);
    myNet.feedForward(inputVals);
    myNet.backProp(targetVals);
    myNet.getResults(resultVals);
}