#include <iostream>
#include <vector>

void print(const std::vector<int> &v) {
    for(auto i : v) {
        std::clog << i << ',';
    }
    std::clog << '\n';
}

void put_pivot_in_place(std::vector<int> &v, const size_t low_idx, const size_t high_idx, std::size_t pivot_idx){
    for(auto idx = low_idx; idx <= high_idx; ++idx) {
        auto& pivot = v[pivot_idx];
        if (v[idx] > pivot && pivot_idx > idx) {
                std::swap(v[idx], pivot);
                pivot_idx = idx;
        } else if (v[idx] < pivot && pivot_idx < idx) {
                std::swap(v[pivot_idx + 1], v[idx]);
                std::swap(v[pivot_idx + 1], v[pivot_idx]);
                ++pivot_idx;
        }
    }
}

[[nodiscard]]
std::size_t get_pivot_idx(const size_t low_idx, const size_t high_idx)
{
    return (high_idx + low_idx) / 2;
}

[[nodiscard]]
bool is_done(std::vector<int>& v, const std::size_t low_idx, const std::size_t high_idx) {
    const bool equal_or_reversed = low_idx >= high_idx;
    const bool two_left_ordered = (high_idx - low_idx == 1) && v[low_idx] <= v[high_idx];
    return  equal_or_reversed || two_left_ordered;
}

void partition(std::vector<int>& v, const std::size_t low_idx, const std::size_t high_idx) {
    const auto pivot_idx = get_pivot_idx(low_idx, high_idx);
    put_pivot_in_place(v, low_idx, high_idx, pivot_idx);
}

void quicksort(std::vector<int>& v, const std::size_t low_idx, const std::size_t high_idx) {
    if (is_done(v, low_idx, high_idx)) {
        return;
    }
    partition(v, low_idx, high_idx);
    const auto mid = (high_idx + low_idx) / 2;
    quicksort(v, low_idx, mid);
    quicksort(v, mid, high_idx);
}

int main() {
    {
        auto v(std::vector<int>{2, 5, 9, 7, 4, 3, 6, 5, 1, 1, 10, 11});
        quicksort(v, 0, std::size(v) - 1);
        std::clog << std::boolalpha << std::is_sorted(std::begin(v), std::end(v)) << '\n';
    }
    {
        auto v(std::vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0});
        quicksort(v, 0, std::size(v) - 1);
        const auto s = std::is_sorted(std::begin(v), std::end(v));
        std::clog << std::boolalpha << s << '\n';
        if(!s) {
            print(v);
        }
    }
    {
        auto v(std::vector<int>{10, 10, 10, 10, 10});
        quicksort(v, 0, std::size(v) - 1);
        std::clog << std::boolalpha << std::is_sorted(std::begin(v), std::end(v)) << '\n';
    }
    {
        auto v(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        quicksort(v, 0, std::size(v) - 1);
        std::clog << std::boolalpha << std::is_sorted(std::begin(v), std::end(v)) << '\n';
    }
    {
        auto v(std::vector<int>{10, 10, 10, 9, 9, 9, 8, 8, 7, 6});
        quicksort(v, 0, std::size(v) - 1);
        std::clog << std::boolalpha << std::is_sorted(std::begin(v), std::end(v)) << '\n';
    }
    {
        auto v(std::vector<int>{10, 10, 10, 9, 9, 9, 8, 8, 7, 6, 7, 8, 9, 10, 11});
        quicksort(v, 0, std::size(v) - 1);
        const auto s = std::is_sorted(std::begin(v), std::end(v));
        std::clog << std::boolalpha << s << '\n';
        if(!s) {
            print(v);
        }
    }
    return 0;
}
