#pragma once 

#include "perceptron.hpp"

namespace neural
{
    class DigitReader
    {
    public:
        DigitReader(double etha)
        {
            for(uint i = 0; i < 10; i++)
            {
                mPerceptrons[i] = new Perceptron<double>(785, sgn<double>, etha, getRandomInit);
            }
        }

        bool train(const std::vector<std::pair<std::vector<double>, int>>& input);

        void trainFor(const std::vector<std::pair<std::vector<double>, int>>& input,
                      const uint maxEpoch = 50);

        int evaluate(const std::vector<double>& X);

        int test(const std::vector<std::pair<std::vector<double>, int>>& input);

    private:
        Perceptron<double>* mPerceptrons[10];
    };
};