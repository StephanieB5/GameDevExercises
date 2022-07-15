#include "DataProcessor.h"
#include <math.h>

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

// EXCERCISE: Optimize this function.  
// As you optimize run this function frequently to see the impact your changes have.
// Focus first on caching values to the stack. 
// You may continue to other optimizations if time permits.
//
void DataProcessor::OptimizedProcessing(Data const& data)
{
    for (int k = 0; k < mCount; ++k)
    {
        if (data.CheckCondition(mCount) && k == 0)
        {
            for (int i = 0; i < data.GetNumRows() * data.GetNumColumns(); ++i)
            {
                mImportantCost += data.GetImportantValue() + TaxOnImportance;
                mProcessedValues[i] = defaultValue;
            }
        }
        else
        {
            for (int i = 0; i < data.GetNumRows() * data.GetNumColumns(); ++i)
            {
                mProcessedValues[i] += (mCount * data.GetValuesPtr()[i]) / k;
            }
        }
    }
}

//
//-----------------------------------------------DON'T CHANGE CODE AFTER THIS POINT-----------------------------------------//
//


// This function is a reference and shows the timing for before your optimizations.  
// It will be used to create comparison timings. 
void DataProcessor::SlowProcessing(Data const& data)
{
	for (int k = 0; k < mCount; ++k)
	{
		if (data.CheckCondition(mCount) && k == 0)
		{
			for (int i = 0; i < data.GetNumRows() * data.GetNumColumns(); ++i)
			{
				mImportantCost += data.GetImportantValue() + TaxOnImportance;
				mProcessedValues[i] = defaultValue;
			}
		}
		else
		{
			for (int i = 0; i < data.GetNumRows() * data.GetNumColumns(); ++i)
			{
				mProcessedValues[i] += (mCount * data.GetValuesPtr()[i]) / k;
			}
		}
	}
}

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
