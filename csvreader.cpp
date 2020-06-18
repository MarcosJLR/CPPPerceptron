#include "csvreader.hpp"

namespace neural
{
	std::vector<std::pair<std::vector<double>, int>> CSVReader::getData()
	{
		std::ifstream file(filename);

		std::vector<std::pair<std::vector<double>, int>> dataList;

		std::string line = "";

		while(getline(file, line))
		{
			dataList.push_back(parseLine(line));
		}

		file.close();

		return dataList;
	}

	std::pair<std::vector<double>, int> CSVReader::parseLine(const std::string& line)
	{
		std::vector<double> inputVector;
		int digit = -1;
		int number = 0;
		bool numStarted = false;

		for(int i = 0; i < (int)line.size(); i++)
		{
			if(isdigit(line[i]))
			{
				number = number * 10 + line[i] - '0';
				numStarted = true;
			}
			else if(numStarted)
			{
				if(digit == -1)
				{
					digit = number;
				}
				else{
					inputVector.push_back(static_cast<double>(number) / 255.0);
				}
				numStarted = false;
				number = 0;
			}
		}

		if(numStarted)
		{
			inputVector.push_back(static_cast<double>(number) / 255.0);
		}

		inputVector.push_back(1.0);

		return {inputVector, digit};
	}
};