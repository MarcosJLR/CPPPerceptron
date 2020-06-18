#include <iostream>

#include "perceptron.hpp"
#include "digitreader.hpp"
#include "csvreader.hpp"

using namespace std;

int main()
{
	cout << "\nReading training data...\n";
	neural::CSVReader trainingReader("mnist_train.csv");
	cout << "Training data read succesfully!\n";

	cout << "\nReading testing data...\n";
	neural::CSVReader testingReader("mnist_test.csv");
	cout << "Testing data read succesfully!\n";

	auto trainingInputList = trainingReader.getData();
	auto testingInputList = testingReader.getData();

	neural::DigitReader network0(0.001);
	neural::DigitReader network1(0.01);
	neural::DigitReader network2(0.1);

	cout << "\nTraining network 0 with learning factor 0.001...\n";
	network0.trainFor(trainingInputList);
	cout << "Training for network 0 finished succesfully!\n";

	cout << "\nTraining network 1 with learning factor 0.01...\n";
	network1.trainFor(trainingInputList);
	cout << "Training for network 1 finished succesfully!\n";

	cout << "Training network 2 with learning factor 0.1...\n";
	network2.trainFor(trainingInputList);
	cout << "Training for network 2 finished succesfully!\n";

	cout << "\nTesting network 0 with learning factor 0.001...\n";
	cout << "Result: " << network0.test(testingInputList) << "/" << testingInputList.size() << endl;

	cout << "\nTesting network 1 with learning factor 0.01...\n";
	cout << "Result: " << network1.test(testingInputList) << "/" << testingInputList.size() << endl;

	cout << "\nTesting network 2 with learning factor 0.1...\n";
	cout << "Result: " << network2.test(testingInputList) << "/" << testingInputList.size() << endl;
}