#ifndef _DYNAMIC_ARRAY_H
#define _DYNAMIC_ARRAY_H
#define MAX_SIZE   100
#include <iostream>


template <class T>
class DynamicArray
{
private:
    T* _data;
    int _maxSize;
    int _currentSize;  
public:
    DynamicArray(){
        _data = NULL;
        _maxSize = MAX_SIZE;
        _currentSize = 0;
    };

    int Size(){return _currentSize;}
    void push_back(T value){
        if(_currentSize < _maxSize)
        {

            T* tmp = _data;
            _data = new T [_currentSize+1];
            if(_data == NULL)
            {
                exit(1);
            }
            else
            {
                if(tmp != NULL)
                {
                    for(int i = 0; i < _currentSize; i++)
                        _data[i] = tmp[i];
                    
                    delete [] tmp;
                }

                _data[_currentSize] = value;
                _currentSize++;
            }
        }
    }

    T operator[](int i)
    {
        if(i < 0 || i >= _currentSize)
        {
            if(_data != NULL)
                return _data[0];
            exit(2);
        }
        return _data[i];
    }

    ~DynamicArray(){
        if(_data != NULL)
            delete [] _data;
    };
};




#endif