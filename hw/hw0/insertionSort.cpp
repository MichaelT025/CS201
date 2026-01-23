/*
Name: Michael Tesfaye
Email:mktesfaye@crimson.ua.edu
Course Section: Spring 2026 CS 201 – 002    
Homework #:0
To Compile: g++ insertionSort.cpp -o insertionSort
To Run: ./insertionSort
*/

#include <vector>
#include <algorithm>
#include <iostream>

template <class RandomIt>
constexpr void insertionsort(RandomIt first, RandomIt last) {
    //If range is empty or has only one element, it's already sorted.
    if(first==last || first+1==last) return;
    
    for(RandomIt i=first+1;i!=last;i++){
        auto key=*i;
        RandomIt j=i-1;
        while(j>=first && *j>key){
            *(j+1)=*j;
            j=j-1;
        }
        *(j+1)=key;
    }
    
}

