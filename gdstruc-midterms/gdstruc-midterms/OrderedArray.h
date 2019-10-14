#pragma once
#include <assert.h>

template<class T>
class OrderedArray
{
public:
	OrderedArray(int size, int growBy = 1) : mArray(NULL), mMaxSize(0), mGrowSize(0), mNumElements(0)
	{
		if (size)
		{
			mMaxSize = size;
			mArray = new T[mMaxSize];
			memset(mArray, 0, sizeof(T) * mMaxSize);
			mGrowSize = ((growBy > 0) ? growBy : 0);
		}
	}

	virtual ~OrderedArray()
	{
		if (mArray != NULL)
		{
			delete[] mArray;
			mArray = NULL;
		}
	}

	virtual void push(T value)
	{
		assert(mArray != NULL);

		if (mNumElements >= mMaxSize)
			expand();

		//your code goes after this line
	}

	virtual void pop()
	{
		if (mNumElements > 0)
			mNumElements--;
	}

	virtual void remove(int index)
	{
		assert(mArray != NULL && index <= mMaxSize);

		for (int i = index; i < mMaxSize - 1; i++)
			mArray[i] = mArray[i + 1];

		mMaxSize--;

		if (mNumElements >= mMaxSize)
			mNumElements = mMaxSize;
	}

	virtual T & operator[](int index)
	{
		assert(mArray != NULL && index <= mNumElements);
		return mArray[index];
	}

	virtual int getSize()
	{
		return mNumElements;
	}


	virtual int binarySearch(T val)
	{
		//your code goes after this line

		return -1;
	}

private:
	T * mArray;
	int mGrowSize;
	int mMaxSize;
	int mNumElements;

	bool expand()
	{
		if (mGrowSize <= 0)
			return false;

		T * temp = new T[mMaxSize + mGrowSize];
		assert(temp != NULL);

		memcpy(temp, mArray, sizeof(T) * mMaxSize);

		delete[] mArray;
		mArray = temp;

		mMaxSize += mGrowSize;
		return true;
	}

};