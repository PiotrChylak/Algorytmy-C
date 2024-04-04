#include <iostream>
#include <cmath>

double P(int i, int j){
    return 30 - sqrt(pow((i - 5), 2) + pow((j - 5), 2));
}

double daw(int x, int y, int x_max) {
    int temp = P(x, 0);
    int t = 0;

    for (int i = 0; i < y; i++) {
        int current = P(x, i);
        if (temp < current) {
            temp = current;
            t = i;
        }
    }

    int L = P(x - 1, t);
    int R = P(x + 1, t);

    if (x > 0 && x < x_max) {
        if (temp < L && L > R) {
            return daw((x / 2), y, x_max);
        } else if (temp < R && R > L) {
            if(x + x/2 > x_max) {
                return daw(x + 1, y, x_max);
            } return daw(x + x/2, y, x_max);
        } else if(L == R && R > temp){
            return daw(x + (x / 2), y, x_max);
        }
    } else {
        return temp;
    }
    return temp;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;

    std::cin >> m >> n;

    std::cout << int(floor(daw(n / 2, m, n)));

    return 0;
}
