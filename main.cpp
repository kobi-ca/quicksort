#include <iostream>
#include <vector>
#include <span>

void print(const std::vector<int> &v) {
    for(auto i : v) {
        std::clog << i << ',';
    }
    std::clog << '\n';
}

[[nodiscard]]
auto put_pivot_in_place(const std::span<int>& v) {
    auto& pivot = v.back();
    int lowest = 0;
    const std::span<int> without_pivot(v.first(v.size() - 1));
    for(auto& elem : without_pivot) {
        if (elem < pivot) {
            std::swap(elem, v[lowest]);
            ++lowest;
        }
    }
    std::swap(pivot, v[lowest]);
    return lowest;
}

void quicksort_impl(const std::span<int>& v) {
    if (v.size() <= 1) {
        return;
    }
    auto p = put_pivot_in_place(v);
    quicksort_impl(v.first(p));
    quicksort_impl(v.last(v.size() - p - 1));
}

void quicksort(std::vector<int>& v) {
    std::span sv(v);
    quicksort_impl(sv);
}

int main() {

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
        auto v(std::vector<int>{2, 5, 9, 7, 4, 3, 6, 5, 1, 1, 10, 11});
        quicksort(v);
        std::clog << std::boolalpha << std::is_sorted(std::begin(v), std::end(v)) << '\n';
    }
    {
        auto v(std::vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0});
        quicksort(v);
        const auto s = std::is_sorted(std::begin(v), std::end(v));
        std::clog << std::boolalpha << s << '\n';
        if(!s) {
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
        if(!s) {
            print(v);
        }
    }
    {
        auto v(std::vector<int>{10, 10, 10, 9, 9, 9, 8, 8, 7, 6, 7, 8, 9, 10, 11});
        quicksort(v);
        const auto s = std::is_sorted(std::begin(v), std::end(v));
        std::clog << std::boolalpha << s << '\n';
        if(!s) {
            print(v);
        }
    }
    return 0;
}
