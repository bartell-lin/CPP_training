#include <iostream>
#include <memory>
#include <stdexcept>
#include <iterator>
#include <cstddef>
using namespace std;

template<typename T>
class myvector {
private:
	T* mData; // this is the actual data (or array)
 	int mSize; // Size is how much data.  Capacity is how much memory.
  	int mCapacity; // not always same as mSize, usually much larger than mSize.
	T mUndefined;// Lots of STL functions say that doing something naughty gets "undefined behavior".
public:
    myvector() {
    	mData = new T[1];
    	mSize = 0;
    	mCapacity = 1;
    }
    myvector(T*, int sz) {
    	mData = new T[sz];
    	mSize = 0;
    	mCapacity = sz;
    }
	virtual ~myvector() {
		delete [] mData;
	}
	myvector(const myvector<T>& other) {
		mSize = other.mSize;
		mCapacity = other.mCapacity;
		mData = new T[mCapacity];
		copy(other.mData, other.mData + mSize, mData);
	}
	myvector(myvector<T>&& other) {
		swap(mSize, other.mSize);
		swap(mCapacity, other.mCapacity);
		swap(mData, other.mData);

	}
	myvector& operator=(const myvector<T>& other) {
		if (this != &other) {
			mSize = other.mSize;
			mCapacity = other.mCapacity;
			mData = new T[mCapacity];
			copy(other.mData, other.mData + mSize, mData);
		}
		return *this;
	}
	myvector& operator=(myvector<T>&& other) {
		if (this != &other) {
			swap(mSize, other.mSize);
			swap(mCapacity, other.mCapacity);
			swap(mData, other.mData);
		}
		return *this;
	}

	bool operator==(const myvector<T>& other) {
		for (int i = 0; i < mSize; i++) {
			if (mData[i] != other.mData[i]) {
				return false;
			}
		}
		return true;
	}
	bool operator!=(const myvector<T>& other) {
		for (int i = 0; i < mSize; i++) {
			if (mData[i] != other.mData[i]) {
				return true;
			}
		}
		return false;
	}
	T& operator[](int offset) {
		if (offset >= mSize) {
			throw invalid_argument("Array index out of bound");
		}
		return mData[offset];
	}
	void push_back(const T& t) {
		if (mSize == mCapacity) {
			reserve(mCapacity);
		}
		mData[mSize++] = t;
	}
	void pop_back() {
		mSize--;
		mData[mSize] = 0;
	}
	T& at(int offset) {
		if (offset >= mSize) {
			throw invalid_argument("Array index out of bound");
		}
		return mData[offset];
	}
	void clear() {
		delete [] mData;
		mSize = 0;
		mCapacity = 1;
		mData = new T[mCapacity];
	}
	int size() const {return mSize;}
	void reserve(int tCount) {  
		int newSize = mCapacity + tCount;
		T* newArr = new T[newSize];
		memcpy(newArr, mData, mCapacity * sizeof(T));
		mCapacity = newSize;
		delete [] mData;
		mData = newArr;
	} 
	int capacity() const {return mCapacity;}
	T* data() {return mData;}
	void insert(int pos, const T& t) {
		if (mSize == mCapacity) {
			reserve(mCapacity);
		}
		for (int i = mSize; i > pos; i--) {
			mData[i] = mData[i - 1];
		}
		mData[pos] = t;
		mSize++;
	}
    
    // iterator
    class Iterator {
    	using iterator_category = forward_iterator_tag;
    	using difference_type = ptrdiff_t;
    	using value_type = T;
    	using pointer = T*;
    	using reference = T&;

	private:
        pointer myvec;
    public:
        Iterator(pointer myvec): myvec(myvec) {}
        Iterator& operator++() {
        	++myvec;
        	return *this;
        }
        Iterator operator++(int) {
        	Iterator tmp = *this;
        	++(*this);
        	return tmp;
        }
        Iterator& operator--() {
        	--myvec;
        	return *this;
        }
        Iterator operator--(int) {
        	Iterator tmp = *this;
        	--(*this);
        	return tmp;
        }
        friend bool operator==(const Iterator& a, const Iterator& other) {return a.myvec == other.myvec;}
        friend bool operator!=(const Iterator& a, const Iterator& other) {return a.myvec != other.myvec;}
        reference operator*() {return *myvec;}
        pointer operator->() {return myvec;} 
    };

    Iterator begin() {return Iterator(&mData[0]);}
    Iterator end() {return Iterator(&mData[mSize]);}
};