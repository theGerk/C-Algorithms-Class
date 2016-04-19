#include <algorithm>
#include <iostream>
#include "Sorts.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

#define EXTENSION ".doNotCopy"
#define OUTPUT_FILE "Output.doNotCopy"
#define INPUT_FILE "Input.doNotCopy"

typedef int*& (*sortFunction)(int*&, size_t);


static inline bool prompt()
{
	std::cout << "(Y/N):\t";
	char input;
	while (true) {
		std::cin >> input;
		switch (input) {
		case '1':
		case 'T':
		case 't':
		case 'Y':
		case 'y':
			return true;
		case '0':
		case 'F':
		case 'f':
		case 'N':
		case 'n':
			return false;
		default:
			std::cout << "Invalid input.\n(Y/N):\t";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			break;
		}
	}
}

void runTest(const int* arrayIn, const size_t arrayInLength, std::ostream& out, sortFunction sort, const std::string& functionName)
{
	int* arrayToSort = new int[arrayInLength];
	memcpy(arrayToSort, arrayIn, sizeof(*arrayIn) * arrayInLength);

	std::cout << "Start " << functionName << std::endl;
	clock_t timer = clock();
	sort(arrayToSort, arrayInLength);
	timer = clock() - timer;
	std::cout << functionName << ":\t" << timer << std::endl;
	out << functionName << ":\t" << timer << std::endl;

	std::ofstream tmp(functionName + std::to_string(arrayInLength) + EXTENSION);
	for (size_t i = 0; i < arrayInLength; i++)
		tmp << arrayToSort[i] << std::endl;

	delete[] arrayToSort;
}

void runAllSorts(const std::string& inputLine, std::ostream& outputStream)
{
	std::ifstream inputFile(inputLine);
	std::string discriptor;
	std::cout << "Start reading file \"";
	std::getline(inputFile, discriptor);
	std::cout << discriptor << "\'" << std::endl;
	size_t length;
	inputFile >> length;
	int* myArray = new int[length];

	for (size_t i = 0; i < length; i++)
		inputFile >> myArray[i];

	std::cout << "Finish reading file\n";

	inputFile.close();

	auto callTest = [&myArray, &length, &outputStream](sortFunction sort, const std::string str) {	
		runTest(myArray, length, outputStream, sort, str);	
	
	};

	outputStream << discriptor << ":\n";
//	callTest(Sort::BubbleSort<int*>, "Bubble Sort");
	callTest(Sort::HeapSort<int*>, "Heap Sort");
//	callTest(Sort::InsertionSort<int*>, "Insertion Sort");
//	callTest(Sort::MergeSort<int*>, "Merge Sort");
//	callTest(Sort::QuickSort<int*>, "Quick Sort");
//	callTest(Sort::SelectionSort<int*>, "Selection Sort");
	outputStream << '\n';

	delete[] myArray;
}

void makeRandFile(const std::string& description, size_t length, const std::string& filename, std::ostream& mainFile)
{
	std::ofstream out(filename);
	out << description << '\n' << length << '\n';
	for (size_t i = 0; i < length; i++)
		out << rand() << '\n';
	out.close();
	mainFile << filename << '\n';
}

void generate()
{
#define SMALLEST 100
#define BIGGEST	1000000
#define GROWTH 10
	std::ofstream outFile(INPUT_FILE);
	srand(time(NULL));
	for (size_t i = SMALLEST; i <= BIGGEST; i *= GROWTH)
	{
		std::cout << "STARTING: " << i << std::endl;
		makeRandFile("Random array of size " + std::to_string(i), i, "rand" + std::to_string(i) + EXTENSION, outFile);
		std::cout << "ENDING: " << i << std::endl;
	}
	outFile.close();
	std::cout << "FILE GENERATION COMPLETE" << std::endl << std::endl;
#undef SMALLEST
#undef BIGGEST
#undef GROWTH
}

int main(int argc, char** argv)
{
	std::cout << "Will we be generating the files this evening?\n";
	if (prompt())
		generate();


	std::ifstream inputFileStream(INPUT_FILE);
	std::ofstream outputFileStream(OUTPUT_FILE);

	for (std::string currentLine; !inputFileStream.eof(); )
	{
		std::getline(inputFileStream, currentLine);
		if (currentLine == "")
			continue;

		runAllSorts(currentLine, outputFileStream);
	}

	inputFileStream.close();
	outputFileStream.close();

	return 0;
}