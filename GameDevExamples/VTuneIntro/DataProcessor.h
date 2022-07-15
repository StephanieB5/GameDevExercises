#pragma once
#include <vector>

class Data
{
public:
	Data();
	~Data();

	// What do the trivial getters and virtual keyword add?
	virtual int GetNumRows() const { return mNumRows; }
	virtual int GetImportantValue() const { return mImportantValue; }
	virtual int GetNumColumns() const { return mNumColums; }
	virtual const int* GetValuesPtr() const { return mValues; }

	virtual bool CheckCondition(int const intParam) const;

private:
	int mNumRows;
	int mImportantValue;
	int mNumColums;
	int* mValues;
};


class DataProcessor
{
public:
	DataProcessor(Data const& data);
	~DataProcessor();

	void Process(Data const& data);

private:
	int mCount;
	int mImportantCost;
	int* mProcessedValues;
};

