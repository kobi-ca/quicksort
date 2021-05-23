#include <iostream>
#include <vector>
#include <span>
#include <chrono>

void print(const std::vector<int> &v) {
    for(auto i : v) {
        std::clog << i << ',';
    }
    std::clog << '\n';
}

[[nodiscard]]
auto put_pivot_in_place(std::span<int> v) {
    auto& pivot = v.back();
    auto lowest = v.begin(); // this makes a huge diff. (Jason Turner found it)
                             // int vs iterator. iterator is faster
    // for GCC have this
    // for clang, just iterate over entire v even if looking
    //   at the last one (pivot) is redundant
    const std::span<int> without_pivot(v.first(v.size() - 1));
    for(auto& elem : without_pivot) {
    //for(auto& elem : v) { // enable this for clang
        if (elem < pivot) {
            std::swap(elem, *lowest);
            ++lowest;
        }
    }
    std::swap(pivot, *lowest);
    return lowest;
}

void quicksort_impl(std::span<int> v) {
    if (v.size() <= 1) {
        return;
    }
    const auto p = put_pivot_in_place(v);
    const auto place = std::distance(v.begin(), p);
    quicksort_impl(v.first(place));
    quicksort_impl(v.last(v.size() - place - 1));
}

void quicksort(std::vector<int>& v) {
    std::span sv(v);
    quicksort_impl(sv);
}

int main() {
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < 1000; ++i) {
        {
            auto v(std::vector<int>{2, 5, 9, 7, 4, 3, 6, 5, 1, 1, 10, 11});
            quicksort(v);
            const auto s = std::is_sorted(std::begin(v), std::end(v));
            std::clog << std::boolalpha << s << '\n';
            if (!s) {
                print(v);
            }
        }

        {
            auto v(std::vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0});
            quicksort(v);
            const auto s = std::is_sorted(std::begin(v), std::end(v));
            std::clog << std::boolalpha << s << '\n';
            if (!s) {
                print(v);
            }
        }
        {
            auto v(std::vector<int>{10, 10, 10, 10, 10});
            quicksort(v);
            std::clog << std::boolalpha << std::is_sorted(std::begin(v), std::end(v)) << '\n';
        }
        {
            auto v(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
            quicksort(v);
            std::clog << std::boolalpha << std::is_sorted(std::begin(v), std::end(v)) << '\n';
        }
        {
            auto v(std::vector<int>{10, 10, 10, 9, 9, 9, 8, 8, 7, 6});
            quicksort(v);
            const auto s = std::is_sorted(std::begin(v), std::end(v));
            std::clog << std::boolalpha << s << '\n';
            if (!s) {
                print(v);
            }
        }
        {
            auto v(std::vector<int>{10, 10, 10, 9, 9, 9, 8, 8, 7, 6, 7, 8, 9, 10, 11});
            quicksort(v);
            const auto s = std::is_sorted(std::begin(v), std::end(v));
            std::clog << std::boolalpha << s << '\n';
            if (!s) {
                print(v);
            }
        }
    }
    auto end = std::chrono::steady_clock::now();
    std::clog << "diff " << (end - start).count() << '\n';
    return 0;
}
