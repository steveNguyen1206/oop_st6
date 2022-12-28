#ifndef _SMART_PTR_H
#define _SMART_PTR_H
#include <iostream>

template <class T>
class SmartPtr
{
    T* _ptr;
public:

    //constructor
    SmartPtr(T* p = NULL) {_ptr = p;};

    ~SmartPtr() {delete (_ptr);};

    T& operator *() {return *_ptr;};

    T& operator =(T* p) 
    {   _ptr = p;
        return *_ptr;
    };
    T* operator->() {return _ptr;}; 

    // template <class U>
    // bool operator == (U* p) {return _ptr == p};
    bool isNULL () {return _ptr == NULL;};

};

#endif
