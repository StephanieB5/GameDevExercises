#include "DataProcessor.h"
#include <math.h>
#include <ittnotify.h>

__itt_domain* domain = __itt_domain_create(L"GameDevExample.Global");
__itt_string_handle* handleInitialIteration = __itt_string_handle_create(L"Initial Iteration");
__itt_string_handle* handleMainLoop = __itt_string_handle_create(L"Main Loop");

namespace
{
	int constexpr TaxOnImportance = 5; 
	int constexpr defaultValue = 0;
    int constexpr numTestsForCondition = 1000000;
	float constexpr randomNumber = 143089.f;

	int constexpr ImportantValue = 3; 
	int constexpr NumRows = 500;
	int constexpr NumColumns = 3000;

	int constexpr NumIterations = 200;  
}

// EXCERCISE: Profile both the optimized and the non-optimized version of the DataProcessor::Process method
// You can switch between the two by uncommenting line 26
//
// #define UseOptimizedVersion

#ifdef UseOptimizedVersion
void DataProcessor::Process(Data const& data)
{
    for (int k = 0; k < mCount; ++k)
    {
        if (data.CheckCondition(mCount) && k == 0)
        {
            __itt_task_begin(domain, __itt_null, __itt_null, handleInitialIteration);
            for (int i = 0; i < data.GetNumRows() * data.GetNumColumns(); ++i)
            {
                mImportantCost += data.GetImportantValue() + TaxOnImportance;
                mProcessedValues[i] = defaultValue;
            }
            __itt_task_end(domain);
        }
        else
        {
            __itt_task_begin(domain, __itt_null, __itt_null, handleMainLoop);
            for (int i = 0; i < data.GetNumRows() * data.GetNumColumns(); ++i)
            {
                mProcessedValues[i] += (mCount * data.GetValuesPtr()[i]) / k;
            }
            __itt_task_end(domain);
        }
    }
}
#else
//
//-----------------------------------------------DON'T CHANGE CODE IN THIS #else/#endif -----------------------------------------//
//

void DataProcessor::Process(Data const& data)
{
	for (int k = 0; k < mCount; ++k)
	{
		if (data.CheckCondition(mCount) && k == 0)
		{
			__itt_task_begin(domain, __itt_null, __itt_null, handleInitialIteration);
			for (int i = 0; i < data.GetNumRows() * data.GetNumColumns(); ++i)
			{
				mImportantCost += data.GetImportantValue() + TaxOnImportance;
				mProcessedValues[i] = defaultValue;
			}
			__itt_task_end(domain);
		}
		else
		{
			__itt_task_begin(domain, __itt_null, __itt_null, handleMainLoop);
			for (int i = 0; i < data.GetNumRows() * data.GetNumColumns(); ++i)
			{
				mProcessedValues[i] += (mCount * data.GetValuesPtr()[i]) / k;
			}
			__itt_task_end(domain);
		}
	}
}
#endif

Data::Data()
	: mNumRows(NumRows)
	, mImportantValue(ImportantValue)
	, mNumColums(NumColumns)
{
	int const size = mNumRows * mNumColums;
	mValues = new int[size];
	int* p = mValues;
	for (int i = 0; i < size; ++i, ++p)
	{
		*p = i;
	}
}

Data::~Data()
{
	delete[] mValues;
}

// Pretend you don't know if this will return true or false or not :)
bool Data::CheckCondition(int const intParam) const
{
	float myFloat = static_cast<float>(intParam);

	for (int i = 0; i < numTestsForCondition; ++i)
	{
		float myNum = sqrtf(randomNumber+i);
		if (myNum == myFloat)
			return false;
	}
	return true;
}

DataProcessor::DataProcessor(Data const& data)
	: mCount(NumIterations)
	, mImportantCost(defaultValue)
{
	mProcessedValues = new int[data.GetNumRows() * data.GetNumColumns()];
}

DataProcessor::~DataProcessor()
{
	delete[] mProcessedValues;
}
