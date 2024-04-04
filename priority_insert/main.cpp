#include <iostream>

struct Student{
    std:: string code;
    float s;
    int d;
    short int m;
};

void insertionSort(Student students[], char first, char second, char third, long long n){
    if(first == 's' && second == 'd' && third == 'm'){
        Student temp;
        int j;

        for(int i = 1; i < n ; i++){
            if(students[i].s > students[i - 1].s
               || (students[i].s == students[i - 1].s && students[i].d > students[i - 1].d)
               || (students[i].s == students[i - 1].s && students[i].d == students[i - 1].d
                   && students[i].m > students[i - 1].m)){
                temp = students[i];
                for(j = i - 1; j >= 0 &&
                               (students[j].s < temp.s)
                               || ((students[j].s == temp.s) && (students[j].d < temp.d))
                               || ((students[j].s == temp.s) && (students[j].d == temp.d) && (students[j].m < temp.m));
                    j--){
                    students[j + 1] = students[j];
                }
                students[j + 1] = temp;
            }
        }
    } else if(first == 's' && second == 'm' && third == 'd'){
        Student temp;
        int j;

        for(int i = 1; i < n ; i++){
            if(students[i].s > students[i - 1].s
               || (students[i].s == students[i - 1].s && students[i].m > students[i - 1].m)
               || (students[i].s == students[i - 1].s && students[i].m == students[i - 1].m
                   && students[i].d > students[i - 1].d)){
                temp = students[i];
                for(j = i - 1; j >= 0 &&
                               (students[j].s < temp.s)
                               || ((students[j].s == temp.s) && (students[j].m < temp.m))
                               || ((students[j].s == temp.s) && (students[j].m == temp.m) && (students[j].d < temp.d));
                    j--){
                    students[j + 1] = students[j];
                }
                students[j + 1] = temp;
            }
        }
    } else if(first == 'd' && second == 's' && third == 'm'){
        Student temp;
        int j;

        for(int i = 1; i < n ; i++){
            if(students[i].d > students[i - 1].d
               || (students[i].d == students[i - 1].d && students[i].s > students[i - 1].s)
               || (students[i].d == students[i - 1].d && students[i].s == students[i - 1].s
                   && students[i].m > students[i - 1].m)){
                temp = students[i];
                for(j = i - 1; j >= 0 &&
                               (students[j].d < temp.d)
                               || ((students[j].d == temp.d) && (students[j].s < temp.s))
                               || ((students[j].d == temp.d) && (students[j].s == temp.s) && (students[j].m < temp.m));
                    j--){
                    students[j + 1] = students[j];
                }
                students[j + 1] = temp;
            }
        }
    } else if(first == 'd' && second == 'm' && third == 's'){
        Student temp;
        int j;

        for(int i = 1; i < n ; i++){
            if(students[i].d > students[i - 1].d
               || (students[i].d == students[i - 1].d && students[i].m > students[i - 1].m)
               || (students[i].d == students[i - 1].d && students[i].m == students[i - 1].m
                   && students[i].s > students[i - 1].s)){
                temp = students[i];
                for(j = i - 1; j >= 0 &&
                               (students[j].d < temp.d)
                               || ((students[j].d == temp.d) && (students[j].m < temp.m))
                               || ((students[j].d == temp.d) && (students[j].m == temp.m) && (students[j].s < temp.s));
                    j--){
                    students[j + 1] = students[j];
                }
                students[j + 1] = temp;
            }
        }
    } else if(first == 'm' && second == 's' && third == 'd'){
        Student temp;
        int j;

        for(int i = 1; i < n ; i++){
            if(students[i].m > students[i - 1].m
               || (students[i].m == students[i - 1].m && students[i].s > students[i - 1].s)
               || (students[i].m == students[i - 1].m && students[i].s == students[i - 1].s
                   && students[i].d > students[i - 1].d)){
                temp = students[i];
                for(j = i - 1; j >= 0 &&
                               (students[j].m < temp.m)
                               || ((students[j].m == temp.m) && (students[j].s < temp.s))
                               || ((students[j].m == temp.m) && (students[j].s == temp.s) && (students[j].d < temp.d));
                    j--){
                    students[j + 1] = students[j];
                }
                students[j + 1] = temp;
            }
        }
    } else if(first == 'm' && second == 'd' && third == 's'){
        Student temp;
        int j;

        for(int i = 1; i < n ; i++){
            if(students[i].m > students[i - 1].m
               || (students[i].m == students[i - 1].m && students[i].d > students[i - 1].d)
               || (students[i].m == students[i - 1].m && students[i].d == students[i - 1].d
                   && students[i].s > students[i - 1].s)){
                temp = students[i];
                for(j = i - 1; j >= 0 &&
                               (students[j].m < temp.m)
                               || ((students[j].m == temp.m) && (students[j].d < temp.d))
                               || ((students[j].m == temp.m) && (students[j].d == temp.d) && (students[j].s < temp.s));
                    j--){
                    students[j + 1] = students[j];
                }
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std:: cin >> n;
    char first, second, third;
    std:: string input;
    std:: cin.ignore();
    std:: getline(std:: cin, input);

    first = input[0];
    second = input[2];
    third = input[4];

    Student boys[n];
    Student girls[n];

    for(int i = 0; i < n; i++){

        std:: cin >> girls[i].code >> girls[i].s >> girls[i].d >> girls[i].m
                  >> boys[i].code >> boys[i].s >> boys[i].d >> boys[i].m;

    }

    insertionSort(girls, first, second, third, n);
    insertionSort(boys, first, second, third, n);

    for(int j = 0; j < n; j++){
        std:: cout << girls[j].code << " " << boys[j].code << " ";
    }

    return 0;
}
