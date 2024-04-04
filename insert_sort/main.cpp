#include <iostream>
#include <valarray>

struct Person{
    std:: string name;
    long long min = 0;
};

void insertSort(Person people[], long long n){
    Person temp;
    int j;

    for(int i = 1; i < n; i++){
        if(people[i].min > people[i - 1].min || people[i].min == people[i - 1].min) {
            temp = people[i];
            for (j = i - 1; j >= 0 &&
            ((people[j].min < temp.min) || (people[j].min == temp.min && people[j].name > temp.name)); j--) {
                people[j + 1] = people[j];
            }
            people[j + 1] = temp;
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    short int t;
    std::cin >> t;
    std:: cin.ignore();

    long long n;
    long long p;

    for(int i = 0; i < t; i++){
        std:: cin >> n >> p;
        Person people[n];

        for(int j = 0; j < n; j++){
//          getline(std::cin, people[j].name, ' ');
            std:: cin.ignore();
            std:: cin >> people[j].name;
            std::cin.ignore();
            std:: cin >> people[j].min;
        }

        insertSort(people, n);

        long long minutes = 1;

        for(int k = 1; k < n; k++){
            minutes += 1 + (people[k].min * k);
        }

        minutes = minutes % (long int)(std:: pow(10, 6) + 3);

        for(int l = 0; l < p; l++){
            std:: cout << people[l].name << " ";
        }
        std:: cout << "\n" << minutes << "\n";
    }

    return 0;
}
