/*
Simple Classic Neural Newtork with backprogration
*/

/*TEST EARLY AND TEST OFTEN
2D array of Neurons make the computation very complicated.
*/

#include <iostream>
#include <vector>
#include<cstdlib>
#include<cassert>
#include<cmath>

using namespace std;
class Neuron;
typedef vector<Neuron> Layer;

// ***************************** struct Connection ********************************
struct Connection
{
    double weigth;
    double deltaWeight;
};


// ***************************** Class NEURON ********************************
class Neuron
{
    //PRIVATE METHODS
private:
    double outputVal;
    vector<Connection>outputWeights;
    static double randomWeight(void) { return rand() / double(RAND_MAX); };
    static double transformationFunction(double x);
    static double transformationFunctionDerivative(double x);
    unsigned index;
    //PUBLIC METHODS
public:
    Neuron(unsigned numOutputs, unsigned idx);
    void setOutputVal(double val) { outputVal = val; }
    double getOutVal(void) const { return outputVal; }
    void feedForward(const Layer& prevLayer);

};

Neuron::Neuron(unsigned numOutputs, unsigned idx) {
    for (unsigned c = 0;c < numOutputs;c++) {
        Connection connection;
        connection.weigth = randomWeight();
        outputWeights.push_back(Connection());
    }
    index = idx;
}

double Neuron::transformationFunction(double x) {
    return tanh(x);
}

double Neuron::transformationFunctionDerivative(double x) {
    return 1 - x * x;
}

void Neuron::feedForward(const Layer& prevLayer) {
    double sum = 0;
    for (unsigned i = 0;i < prevLayer.size();i++) {
        sum += prevLayer[i].getOutVal() * prevLayer[i].outputWeights[index].weigth;
    }
    outputVal = Neuron::transformationFunction(sum);
}



// ***************************** Class NET ******************************** 
class Net
{
private:
    vector<Layer> m_layers;
    double error;

public:
    Net(const vector<unsigned>& topology);
    void feedForward(const vector<double>& inputVals);
    void backProp(const vector<double>& targetVals);
    void getResults(const vector<double>& resultVals) const;
};

Net::Net(const vector<unsigned>& topology) {
    unsigned numLayers = topology.size();
    for (unsigned layerNum = 0;layerNum < numLayers;layerNum++) {
        m_layers.push_back(Layer());
        unsigned numOutputs = layerNum == numLayers - 1 ? 0 : topology[layerNum + 1];
        for (unsigned neuronNum = 0;neuronNum <= topology[layerNum];++neuronNum) {
            m_layers.back().push_back(Neuron(numOutputs, neuronNum));
        }
    }
};

void Net::feedForward(const vector<double>& inputVals) {
    assert(inputVals.size() == m_layers[0].size() - 1);
    // Assign Input Values to Input Neurons
    for (unsigned i = 0;i < inputVals.size();i++) {
        m_layers[0][i].setOutputVal(inputVals[i]);
    }

    // Feed Forward
    for (unsigned layerNum = 0;layerNum <= m_layers.size();layerNum++) {
        Layer& prevLayer = m_layers[layerNum - 1];
        for (unsigned neuron = 0;neuron < m_layers[layerNum].size() - 1;neuron++) {
            m_layers[layerNum][neuron].feedForward(prevLayer);
        }
    }
}
void Net::backProp(const vector<double>& targetVals) {

    // calculate overall net error (RMS of ouptut errors)
    Layer& outputLayer = m_layers.back();
    error = 0;
    for (unsigned i = 0;i < outputLayer.size();i++) {
        double delta = targetVals[i] - outputLayer[i].getOutVal();
        error += delta * delta;
    }
    error /= outputLayer.size() - 1;
    error = sqrt(error);

    // calculate outlayer gradient
    // calculate hidden layers gradient
    // for all layers output to first hidden layer
    //update all connection weight

}
void Net::getResults(const vector<double>& resultVals) const {};


// ***************************** Main ******************************** 
int main()
{
    vector<unsigned> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(1);
    Net myNet(topology);

    vector<double> inputVals;
    myNet.feedForward(inputVals);

    vector<double> targetVals;
    myNet.backProp(targetVals);

    vector<double> resultVals;
    myNet.getResults(resultVals);
    cout << "htis\n";
}