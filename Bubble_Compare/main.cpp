#include <iostream>
#include <cmath>
#include <string>

void asc(long long rotations[], std::string models[]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (rotations[j] > rotations[j + 1]) {
                long long temp = rotations[j];
                rotations[j] = rotations[j + 1];
                rotations[j + 1] = temp;

                std::string temp1 = models[j];
                models[j] = models[j + 1];
                models[j + 1] = temp1;
            } else if((rotations[j] == rotations[j + 1] && models[j] > models[j + 1])){
                std::string temp = models[j];
                models[j] = models[j + 1];
                models[j + 1] = temp;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n;
    std::string model;
    long double p;
    long long d;
    std::cin >> n;
    std::string models[3];
    long long rotations[3] = {0, 0, 0}; //= {12531883901, 12531883901, 12531883901};

    for (int i = 0; i < n; i++) {
        std::cin.ignore();
        getline(std::cin, model);
        std::cin >> p >> d;



        long long rotation = floor(p * 100000 / (d * 2.54 * 3.141593));


        if (i < 3) {
            rotations[i] = rotation;
            models[i] = model;
        }

        if(i == 2)
        {
            asc(rotations, models);
        }

        if (i >= 3) {
                    if (rotation == rotations[0] && model <= models[0]) {
                        rotations[2] = rotations[1];
                        rotations[1] = rotations[0];
                        rotations[0] = rotation;
                        models[2] = models[1];
                        models[1] = models[0];
                        models[0] = model;
                    } else if (rotation < rotations[0]) {
                        rotations[2] = rotations[1];
                        rotations[1] = rotations[0];
                        rotations[0] = rotation;
                        models[2] = models[1];
                        models[1] = models[0];
                        models[0] = model;
                    } else if (rotation == rotations[1] && model <= models[1]) {
                        rotations[2] = rotations[1];
                        rotations[1] = rotation;
                        models[2] = models[1];
                        models[1] = model;
                    } else if (rotation < rotations[1]) {
                        rotations[2] = rotations[1];
                        rotations[1] = rotation;
                        models[2] = models[1];
                        models[1] = model;
                    } else if (rotation == rotations[2] && model <= models[2]) {
                        rotations[2] = rotation;
                        models[2] = model;
                    } else if (rotation < rotations[2]) {
                        rotations[2] = rotation;
                        models[2] = model;
                    }
                }
        }


    for (int i = 0; i < 3; i++) {
        std::cout<<models[i]<<'\n'<<rotations[i]<<'\n';
    }

    return 0;
}