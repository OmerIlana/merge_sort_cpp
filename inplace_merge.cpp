#include <utility>
#include <array>

template <typename  T, size_t N> 
void inplace_merge( std::array<T, N>& arr, size_t begin, size_t mid, size_t end) { 
    size_t index1 = begin;
    size_t index2 = mid;
    while (index1 < index2 && index2 <= end) {
        if (arr[index1] <= arr[index2]) {
            index1++;
        } else {
             if (index2 !=end && arr[index1] > arr[index2+1]){
                T nextValue = arr[index1];
                while ( index2 <= end && nextValue > arr[ index2]) {
                    std::swap(arr[index1], arr[index2]);
                    index2++;
                    index1++;
                }
                if (index2 > end) index2=end;
            } else {
                std::swap(arr[index1], arr[index2]);
                index1++;
            }
        }
    }
}
