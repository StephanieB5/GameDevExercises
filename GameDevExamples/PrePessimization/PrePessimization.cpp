// PrePessimization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "DataProcessor.h"

int main()
{
	using namespace std::chrono;

	time_point<high_resolution_clock> start;
	time_point<high_resolution_clock> end;

	Data* dataSlow = new Data();
	DataProcessor* dataProcessorSlow = new DataProcessor(*dataSlow);

	start = high_resolution_clock::now();
	dataProcessorSlow->SlowProcessing(*dataSlow);
	end = high_resolution_clock::now();

	auto startMs = time_point_cast<milliseconds>(start).time_since_epoch().count();
	auto endMs = time_point_cast<milliseconds>(end).time_since_epoch().count();
	std::cout << "SlowProcessing Time taken = " << (endMs - startMs) << " milliseconds" << std::endl;

	delete dataProcessorSlow;
	delete dataSlow;
	Data* dataOpt = new Data();
	DataProcessor* dataProcessorOpt = new DataProcessor(*dataOpt);

	start = high_resolution_clock::now();
	dataProcessorOpt->OptimizedProcessing(*dataOpt);
	end = high_resolution_clock::now();

	startMs = time_point_cast<milliseconds>(start).time_since_epoch().count();
	endMs = time_point_cast<milliseconds>(end).time_since_epoch().count();
	std::cout << "OptimizedProcessing Time taken = " << (endMs - startMs) << " milliseconds" << std::endl;

	delete dataProcessorOpt;
	delete dataOpt;

	std::cout << "Press Enter to continue" << std::endl;
	std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
