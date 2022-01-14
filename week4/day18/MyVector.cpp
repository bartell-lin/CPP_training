#include "MyVector.h"

template<typename T>
myvector<T>::myvector(T*, int sz) {
	mCapacity = sz;
	mSize = 0;
}