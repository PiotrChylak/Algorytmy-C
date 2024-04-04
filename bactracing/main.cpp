#include <iostream>
#include <vector>
#include <algorithm>

bool comp(int a, int b) {
    return a > b;
}

int combinations(std::vector<int>& calories, int& counter, int target, int current, int index) {
    if (target == current) {
        counter++;
        return counter;
    }

    for (int i = index; i < calories.size(); i++) {
        if (target >= current + calories[i]) combinations(calories, counter, target, current + calories[i], i + 1);
    }

    return counter;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    int result;
    int counter = 0;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> calories(n);

        for (int i = 0; i < n; ++i) std::cin >> calories[i];

        int target_calories;

        std::cin >> target_calories;

        std::sort(calories.begin(), calories.end(), comp);

        counter = 0;

        result = combinations(calories, counter, target_calories, 0, 0);
        std::cout << result << std::endl;
    }
    return 0;
}