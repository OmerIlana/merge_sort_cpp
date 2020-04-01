#include <array>
#include <functional>
#include <iostream>
#include <algorithm> //std::copy
#include "merge_sort.h"
#include <windows.h>

template <typename T, size_t N> 
void print( std::array<T, N>& arr) { 
    std::copy(arr.begin(),
       arr.end(),
       std::ostream_iterator<T>(std::cout, ","));
       std::cout << std::endl;
}

int main()
{
    std::array<char,300> tooLongToBeSorted; 
    //sort(tooLongToBeSorted); // cause compile error "error: static assertion failed: Array length exceeded maximum allowed length."

    std::array<float,2> tooComplicatedTypeToBeSorted; 
    //sort(tooComplicatedTypeToBeSorted); // cause compile error "error: static assertion failed: Array can consist only of integral types."

    std::array<char,5> scores { 'A', 'B', 'C', 'A', 'A' }; 
    sort(scores);
    print(scores);

    std::array<unsigned, 5> arr {1, 4, 0, 3, 2};
    sort(arr, std::greater<unsigned>());
    print(arr);
    return 0;
}