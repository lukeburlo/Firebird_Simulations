/*********************************************************************************************************************/
//
//  DynamicStateArray.h
//  Class Description: The DynamicStateArray class is simple array that can be dynamically size. i.e. The array is
//                     created on the heap. The class is designed for fast intialisation and access.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#include <stdexcept>
#include <string>
#include <sstream>

#ifndef _DynamicStateArray_h_  
#define _DynamicStateArray_h_    

namespace Simulation
{
	template <class T>
	class DynamicStateArray
	{
		private:
			T* _array;
			int _arrayCount;
			void Init();

		public:
			DynamicStateArray();
			DynamicStateArray(int stateCount);
			DynamicStateArray(DynamicStateArray& other);
			~DynamicStateArray();
			T& operator[]( int index);
			int GetCount();

	};

	template <class T>
	void DynamicStateArray<T>::Init()
	{
		if(_arrayCount > 0)
		{
			_array = new T[_arrayCount];
		}
		else
		{
			_array = 0;	
		}

		return;
	}

	template <class T>
	DynamicStateArray<T>::DynamicStateArray()
	{
		_arrayCount=0;
		_array = 0;
	}

	template <class T>
	DynamicStateArray<T>::DynamicStateArray(int stateCount)
	{
		_arrayCount=stateCount;
		Init();
	}

	//needs to be private and =operator
	template <class T>
	DynamicStateArray<T>::DynamicStateArray(DynamicStateArray& other)
	{
		_arrayCount = other._arrayCount;
		_array = other._array;
	}

	template <class T>
	DynamicStateArray<T>::~DynamicStateArray()
	{
		if(_array!=0)
		{
			delete [] _array;
		}
	}

	template <class T>
	T& DynamicStateArray<T>::operator[]( int index)
	{	
		if(index < 0 || index >= _arrayCount)
		{
			std::stringstream exceptionStream;
			exceptionStream << "Trying to access array with index: " <<  
				index << " where array size is: " << _arrayCount;
			
			throw std::out_of_range (exceptionStream.str());
		}

		T& result = _array[index];
		return result;
	}
	template <class T>
	int DynamicStateArray<T>::GetCount()
	{
		return _arrayCount;
	}
}

#endif