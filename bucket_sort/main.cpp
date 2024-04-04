#include <iostream>

struct Meal{
    std:: string meal;
    int value{};
    int modulo{};
    int whole{};
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;

    std:: cin >> n;

    Meal meals[n];
    Meal result[n];

    int dResult[n + 1];

    for(int i = 0; i < n; i++){
        std:: cin >> meals[i].meal;
        std:: cin >> meals[i].value;
        meals[i].modulo = 0;
        meals[i].whole = 0;
        dResult[i] = 0;
    }

    dResult[n] = 0;

    for(int i = 0; i < n; i++){
        meals[i].modulo = meals[i].value % n;
    }

    for(int i = 0; i < n; i++){
        dResult[meals[i].modulo]++;
    }

    for(int i = 1; i <= n; i++){
        dResult[i] += dResult[i - 1];
    }

//    for(int i = 0; i < n; i++){
//        std:: cout << meals[i].meal << " " << meals[i].value << " " <<  meals[i].modulo << std:: endl;
//    }
//
//    for(int i = 0; i < n; i++){
//        std:: cout << dResult[i] << " ";
//    }

//    std:: cout << std:: endl;

    for(int i = n - 1; i >= 0; i--){
        int mod = meals[i].modulo;
        int index = --dResult[mod];
        result[index] = meals[i];
        //--dResult[mod];
    }

//    for(int i = 0; i < n; i++){
//        std:: cout << result[i].meal << " ";
//    }
//
//    std:: cout << std:: endl;

    for(int i = 0; i <= n; i++){
        dResult[i] = 0;
    }

    for(int i = 0; i < n; i++){
        result[i].whole = result[i].value / n;
    }

    for(int i = 0; i < n; i++){
        dResult[result[i].whole]++;
    }

    for(int i = 1; i <= n; i++){
        dResult[i] += dResult[i - 1];
    }

//    for(int i = 0; i < n; i++){
//        std:: cout << meals[i].meal << " " << meals[i].value << " " <<  meals[i].whole << std:: endl;
//    }
//
//    for(int i = 0; i < n; i++){
//        std:: cout << dResult[i] << " ";
//    }


//    std:: cout << std:: endl;

    for(int i = n - 1; i >= 0; i--){
        int wh = result[i].whole;
        int index = --dResult[wh];
        meals[index] = result[i];
        //--dResult[wh];
    }

    for(int i = 0; i < n; i++){
        std:: cout << meals[i].meal << " ";
    }

    std:: cout << std:: endl;

//    std:: string temp;
//    temp = result[n - 1].meal;
//    result[n - 1].meal = result[n - 2].meal;
//    result[n - 2].meal = temp;
//
//    for(int i = 0; i < n; i++){
//        std:: cout << result[i].meal << " ";
//    }

    return 0;
}