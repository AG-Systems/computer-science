// #include "orderedpair.h"
#include <iostream>
using namespace std;

namespace cs_pairs {
    template <class T>
    OrderedPair<T>::OrderedPair(T newFirst, T newSecond) {
        setFirst(newFirst);
        setSecond(newSecond);
    }

    template <class T>
    void OrderedPair<T>::setFirst(T newFirst) {
        // if statement to throw an exception if precondition not met goes here. 
        if(second == newFirst && (DEFAULT_VALUE != newFirst && DEFAULT_VALUE != second))
        {
            throw DuplicateMemberError(); 
        }
        first = newFirst;
    }

    template <class T>
    void OrderedPair<T>::setSecond(T newSecond) {
        // if statement to throw an exception if precondition not met goes here. 
        if(newSecond == first && (DEFAULT_VALUE != first && DEFAULT_VALUE != newSecond))
        {
            throw DuplicateMemberError(); 
        }
        second = newSecond;
    }

    template <class T>
    T OrderedPair<T>::getFirst() const {
        return first;
    }

    template <class T>
    T OrderedPair<T>::getSecond() const {
        return second;
    }

    template <class T>
    OrderedPair<T> OrderedPair<T>::operator+(const OrderedPair<T>& right) const {
        return OrderedPair(first + right.first, second + right.second);
    }

    template <class T>
    bool OrderedPair<T>::operator<(const OrderedPair<T>& right) const {
        return first + second < right.first + right.second;
    }


    template <class T>
    void OrderedPair<T>::print() const {
        cout << "(" << first << ", " << second << ")";
    }
}
