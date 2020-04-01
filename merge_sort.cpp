
#ifdef __MERGE_SORT_H__

#include <iterator>
#include <algorithm>
#include <type_traits>

const size_t MAX_ALLOWED_LENGTH = 256;

template <class Iter, typename Comparator>
void mergeSort(Iter begin, Iter end, Comparator cmp)
{
    auto const arrLen = std::distance(begin, end);
    if (arrLen > 1) {
        auto mid = std::next(begin, arrLen / 2);
        mergeSort(begin,mid, cmp);
        mergeSort(mid,  end, cmp);
        std::inplace_merge(begin, mid, end, cmp);
    }
}

template <typename T, size_t N, typename Comparator>
void sort(std::array<T, N>& arr, Comparator cmp) {
    static_assert(N <= MAX_ALLOWED_LENGTH,      "Array length exceeded maximum allowed length.");  
    static_assert(std::is_integral<T>::value,   "Array can consist only of integral types.");  
    mergeSort(arr.begin(), arr.end(), cmp);
}
#endif  // __MERGE_SORT_H__