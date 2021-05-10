#include <iostream>
#include <vector>

void print(const std::vector<int> &v) {
    for(auto i : v) {
        std::clog << i << ',';
    }
    std::clog << '\n';
}

[[nodiscard]]
std::vector<int>::iterator put_pivot_in_place(std::vector<int> &v, std::vector<int>::iterator low,
                                                    std::vector<int>::iterator high) {
    auto pivot = high;
    auto iter = low;
    auto lowest = low;
    while (iter <= high){
        const auto pred = [pivot](const auto v){ return v < *pivot; };
        iter = std::find_if(iter, pivot,  pred);
        if (iter == pivot) {
            break;
        }
        std::swap(*lowest, *iter);
        ++lowest; ++iter;
    }
    std::swap(*lowest, *pivot);
    return lowest;
}


[[nodiscard]]
std::size_t get_pivot_idx(const size_t low_idx, const size_t high_idx)
{
    return (high_idx + low_idx) / 2;
}

[[nodiscard]]
bool is_done(std::vector<int>& v, std::vector<int>::iterator low,
             std::vector<int>::iterator high) {
    return low >= high;
}

void quicksort(std::vector<int>& v, std::vector<int>::iterator low,
               std::vector<int>::iterator high) {
    if (is_done(v, low, high)) {
        return;
    }
    auto p = put_pivot_in_place(v, low, high);
    quicksort(v, low, std::prev(p));
    quicksort(v, std::next(p), high);
}

int main() {

    {
        auto v(std::vector<int>{2, 5, 9, 7, 4, 3, 6, 5, 1, 1, 10, 11});
        quicksort(v, std::begin(v), std::prev(std::end(v)));
        const auto s = std::is_sorted(std::begin(v), std::end(v));
        std::clog << std::boolalpha << s << '\n';
        if (!s) {
            print(v);
        }
    }


    {
        auto v(std::vector<int>{2, 5, 9, 7, 4, 3, 6, 5, 1, 1, 10, 11});
        quicksort(v, std::begin(v), std::prev(std::end(v)));
        std::clog << std::boolalpha << std::is_sorted(std::begin(v), std::end(v)) << '\n';
    }
    {
        auto v(std::vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0});
        quicksort(v, std::begin(v), std::prev(std::end(v)));
        const auto s = std::is_sorted(std::begin(v), std::end(v));
        std::clog << std::boolalpha << s << '\n';
        if(!s) {
            print(v);
        }
    }
    {
        auto v(std::vector<int>{10, 10, 10, 10, 10});
        quicksort(v, std::begin(v), std::prev(std::end(v)));
        std::clog << std::boolalpha << std::is_sorted(std::begin(v), std::end(v)) << '\n';
    }
    {
        auto v(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        quicksort(v, std::begin(v), std::prev(std::end(v)));
        std::clog << std::boolalpha << std::is_sorted(std::begin(v), std::end(v)) << '\n';
    }
    {
        auto v(std::vector<int>{10, 10, 10, 9, 9, 9, 8, 8, 7, 6});
        quicksort(v, std::begin(v), std::prev(std::end(v)));
        const auto s = std::is_sorted(std::begin(v), std::end(v));
        std::clog << std::boolalpha << s << '\n';
        if(!s) {
            print(v);
        }
    }
    {
        auto v(std::vector<int>{10, 10, 10, 9, 9, 9, 8, 8, 7, 6, 7, 8, 9, 10, 11});
        quicksort(v, std::begin(v), std::prev(std::end(v)));
        const auto s = std::is_sorted(std::begin(v), std::end(v));
        std::clog << std::boolalpha << s << '\n';
        if(!s) {
            print(v);
        }
    }
    return 0;
}
