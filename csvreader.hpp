#pragma once 

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

namespace neural
{
	class CSVReader
	{
	public:
		CSVReader(std::string filename)
			: filename(filename) {}

		std::vector<std::pair<std::vector<double>, int>> getData();

		std::pair<std::vector<double>, int> parseLine(const std::string& line);

	private:
		std::string filename;
	};
};