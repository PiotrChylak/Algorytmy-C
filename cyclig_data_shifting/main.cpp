#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long m, n;
    long long a, b, c, d;

    std:: cin >> n >> m;

    char names[12][1500];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < 12; j++){
            std:: cin >> names[j][i];
        }
    }

    for(int i = 0; i < n; i ++){
        std:: cin >> a >> b >> c >> d;
        names[0][(i + m) % 1500] = names[0][a % 1500];
        names[1][(i + m) % 1500] = names[1][a % 1500];
        names[2][(i + m) % 1500] = names[2][a % 1500];

        names[3][(i + m) % 1500] = names[3][b % 1500];
        names[4][(i + m) % 1500] = names[4][b % 1500];
        names[5][(i + m) % 1500] = names[5][b % 1500];

        names[6][(i + m) % 1500] = names[6][c % 1500];
        names[7][(i + m) % 1500] = names[7][c % 1500];
        names[8][(i + m) % 1500] = names[8][c % 1500];

        names[9][(i + m) % 1500] = names[9][d % 1500];
        names[10][(i + m) % 1500] = names[10][d % 1500];
        names[11][(i + m) % 1500] = names[11][d % 1500];

    }

    for(int i = 0; i < 12; i++){
        std:: cout << names[i][(n - 1) % 1500];
    }
}