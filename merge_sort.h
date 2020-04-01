#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include <array>
#include <functional>

/**
 * In-place merge sort.
 *
 * @param[in,out] Array Container whose values are sorted.
 * @param[in] (optional) Function object for performing comparisons
 */
template <typename T, size_t N, typename Comparator = std::less<T>>
void sort(std::array<T, N>& arr, Comparator cmp =  Comparator()); 

 #include "merge_sort.cpp"

#endif  // __MERGE_SORT_H__