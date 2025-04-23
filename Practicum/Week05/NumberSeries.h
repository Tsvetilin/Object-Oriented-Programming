#pragma once

class NumberSeries
{
public:
	void copyFrom(const NumberSeries& other);
	void free();
	NumberSeries();
	NumberSeries(int a_0, int(*func)(int a));
	NumberSeries(const NumberSeries& other);
	NumberSeries& operator=(const NumberSeries& series);
	~NumberSeries();

	int getA_i(size_t index);
	bool isPartOfSeries(int a);
	void setA_0(int a_0);
	void setFunc(int(*func)(int a));

private:
	int a_0;
	int* nums;
	size_t numsSize;
	int(*func)(int a);
};