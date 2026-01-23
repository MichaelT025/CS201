/*
Name: Michael Tesfaye
Email:mktesfaye@crimson.ua.edu
Course Section: Spring 2026 CS 201 – 002    
Homework #:0
To Compile: g++ mergeSort.cpp -o mergeSort
To Run: ./mergeSort
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

template<class RandomIt>
constexpr void merge(RandomIt first, RandomIt mid, RandomIt last, RandomIt tempstart) {
    RandomIt left = first;
    RandomIt right = mid;
    RandomIt curr = tempstart;

    while (left != mid && right != last) {
        if (*left <= *right) {
            *curr = *left;
            ++left;
        } else {
            *curr = *right;
            ++right;
        }
        ++curr;
    }

    while (left != mid) {
        *curr = *left;
        ++left;
        ++curr;
    }

    while (right != last) {
        *curr = *right;
        ++right;
        ++curr;
    }

    // Copy back to original range
    for (RandomIt i = first, j = tempstart; i != last; ++i, ++j) {
        *i = *j;
    }
}

template<class RandomIt>
constexpr void mergesort(RandomIt first, RandomIt last, RandomIt tempstart) {
    if (last - first <= 1) return;

    RandomIt mid = first + (last - first) / 2;
    mergesort(first, mid, tempstart);
    mergesort(mid, last, tempstart);
    merge(first, mid, last, tempstart);
}
