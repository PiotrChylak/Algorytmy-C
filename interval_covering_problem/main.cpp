#include <iostream>
#include <algorithm>

struct interval{
    int first;
    int last;
};

bool compare(const interval &a, const interval &b) {
    return a.last < b.last;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    int n;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n;
        interval cagesAv[n];
        bool camsPlaced[n];
        bool answer = true;
        bool allTaken = false;
        int a, b;
        int counter = 0;

        for (int j = 0; j < n; j++) {
            std::cin >> a >> b;
            cagesAv[j].first = a;
            cagesAv[j].last = b;
            camsPlaced[j] = false;
        }

//        for (int j = 0; j < n - 1; ++j) {
//            for (int k = 0; k < n - j - 1; ++k) {
//                if (cagesAv[k].last > cagesAv[k + 1].last) {
//                    interval temp = cagesAv[k];
//                    cagesAv[k] = cagesAv[k + 1];
//                    cagesAv[k + 1] = temp;
//                }
//            }
//        }

        std::sort(cagesAv, cagesAv + n, compare);

        for (int j = 0; j < n; j++) {
            for (int k = cagesAv[j].first; k <= cagesAv[j].last; k++) {
                if (!camsPlaced[k]) {
                    camsPlaced[k] = true;
                    counter = 0;
                    break;
                } else {
                    counter++;
                }
            }
//            if (counter > cagesAv[j].last - cagesAv[j].first) {
//                allTaken = true;
//                counter = 0;
//                break;
//            }
        }


        for (int j = 0; j < n; j++) {
            if (!camsPlaced[j]) {
                std::cout << "NIE" << std::endl;
                answer = false;
                break;
            }
        }

        if (answer) {
            std::cout << "TAK" << std::endl;
        }
    }
}