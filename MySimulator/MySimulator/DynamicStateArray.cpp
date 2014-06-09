
#include "DynamicStateArray.h"


//namespace Simulation
//{
//
//	DynamicStateArray::DynamicStateArray(int stateCount)
//	{
//		_arraryCount=stateCount;
//		Init();
//	}
//
//	DynamicStateArray::~DynamicStateArray()
//	{
//		if(_array != 0 )
//		{
//			delete[] _array;
//		}
//	}
//
//
//	void DynamicStateArray::Init()
//	{
//		if(_arraryCount > 0)
//		{
//			_array = new double[_arraryCount];
//		}
//		else
//		{
//			_array = 0;	
//		}
//
//		return;
//	}
//
//
//	double DynamicStateArray::operator[](int index)
//	{
//		double result = _array[index];
//		return result;
//	}
//}

namespace Simulation
{
	/*template <class T>
	DynamicStateArray<T>::DynamicStateArray(int stateCount)
	{
		_arraryCount=stateCount;
		init();
	}
	template <class T>
	DynamicStateArray<T>::DynamicStateArray()
	{
		_arraryCount=0;
		
	}

	template <class T>
	DynamicStateArray<T>::~DynamicStateArray<T>()
	{
		if(_array != 0 )
		{
			delete[] _array;
		}
	}

	template <class T>
	void DynamicStateArray<T>::Init()
	{
		if(_arraryCount > 0)
		{
			_array = = new T[_arraryCount];
		}
		else
		{
			_array = 0;	
		}

		return;
	}

	template <class T>
	T DynamicStateArray<T>::operator[](int index)
	{
		T result = _array[index];

		return result;
	}*/
}