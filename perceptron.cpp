#include "perceptron.hpp"

namespace neural
{
    template<typename T>
    T Perceptron<T>::evaluate(const std::vector<T>& X)
    {
        T dotProduct = static_cast<T>(0);
        for(uint i = 0; i < mSize; i++)
        {
            dotProduct += mWeights[i] * X[i];
        }

        return mSigma(dotProduct);
    }

    template<typename T>
    bool Perceptron<T>::train(const std::vector<T>& X, const T desiredOutput)
    {
        T y = evaluate(X);
        if(y != desiredOutput)
        {
            for(uint i = 0; i < mSize; i++)
            {
                mWeights[i] += mEtha * (desiredOutput - y) * X[i];
            }

            return true;
        }

        return false;
    }

    template<typename T>
    bool Perceptron<T>::trainEpoch(const std::vector<std::pair<std::vector<T>, T>>& input)
    {
        bool changed = false;
        for(auto& [X, d] : input)
        {
            bool change = train(X, d);
            changed |= change;
        }

        return changed;
    }

    template<typename T>
    void Perceptron<T>::trainFor(const std::vector<std::pair<std::vector<T>, T>>& input, 
                                 const uint maxEpoch)
    {
        for(uint i = 0; i < maxEpoch; i++)
        {
            if(!trainEpoch(input)) break;
        }
    }
}