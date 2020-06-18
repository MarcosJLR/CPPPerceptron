#pragma once

#include <vector>
#include <functional>
#include <random>

namespace neural
{
    template <typename T>
    class Perceptron
    {
    public:
        // Initialize the perceptron with a given size and a given sigma function
        // and all synaptic weights in zero
        Perceptron(uint tSize, std::function<T(T)> tSigma, T tEtha) 
            : mSize(tSize), mSigma(tSigma), mWeights(mSize), mEtha(tEtha) {}

        // Initialize perceptron with random weights given by a randFunction
        Perceptron(uint tSize, std::function<T(T)> tSigma, T tEtha, std::function<T()> randFunction)
            : mSize(tSize), mSigma(tSigma), mWeights(mSize), mEtha(tEtha) 
        {
            for(uint i = 0; i < mSize; i++)
            {
                mWeights[i] = randFunction();
            }
        }            

        // Get value of feeding input vector X to this perceptron
        T evaluate(const std::vector<T>& X);

        // Train this perceptron feeding vector X and knowing
        // the desired output for X
        // Return value represents if synaptic weights were changed
        bool train(const std::vector<T>& X, const T desiredOutput);

        // Train this perceptron for an epoch given the input
        // Return value represents if synaptic weights were changed
        bool trainEpoch(const std::vector<std::pair<std::vector<T>, T>>& input);
    
        // Train this perceptron for a given number of epochs or until it 
        // classifies everything right
        void trainFor(const std::vector<std::pair<std::vector<T>, T>>& input, 
                      const uint maxEpoch = 50);

    private:
        uint mSize;                 // Size of the Weights Vector
        std::function<T(T)> mSigma; // Activation Function
        std::vector<T> mWeights;    // Synaptic Weights
        T mEtha;                    // Learning Etha factor
    };

    // Sign function: Returns 1 if x > 0 and 0 otherwise
    template<typename T>
    T sgn(T x)
    {
        return x > static_cast<T>(0) ? static_cast<T>(1) : static_cast<T>(0);
    }

    double getRandomInit();
};