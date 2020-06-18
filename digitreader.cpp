#include "digitreader.hpp"

namespace neural
{
    bool DigitReader::train(const std::vector<std::pair<std::vector<double>, int>>& input)
    {
        bool changed = false;
        for(auto& [X, d] : input)
        {
            for(int i = 0; i < 10; i++)
            {
                bool change = mPerceptrons[i]->train(X, i == d ? 1.0 : 0.0);
                changed = changed || change;
            }
        }
        return changed;
    }

    void DigitReader::trainFor(const std::vector<std::pair<std::vector<double>, int>>& input,
                               const uint maxEpoch)
    {
        for(uint i = 0; i < maxEpoch; i++)
        {
            if(!train(input)) break;
        }
    }

    int DigitReader::evaluate(const std::vector<double>& X)
    {
        int count = 0;
        int answer = -1;

        for(int i = 0; i < 10; i++)
        {
            double x = mPerceptrons[i]->evaluate(X);
            if(x == 1.0)
            {
                count++;
                answer = i;
            }
        }

        return count == 1 ? answer : -1;
    }

    int DigitReader::test(const std::vector<std::pair<std::vector<double>, int>>& input)
    {
        int count = 0;
        for(auto& [X, d] : input)
        {
            if(evaluate(X) == d)
            {
                count++;
            }
        }

        return count;
    }
};