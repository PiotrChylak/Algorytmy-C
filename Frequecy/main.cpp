#include <iostream>
#include <string>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std:: string text;

    while(true){
        char letter;
        std:: cin.get(letter);

        if(letter == '^')
            break;
        else
            text += letter;
    }

    int counter[26] = {0};

    for(char letter : text){
        if(letter < 91){
            letter = letter + 32;
        }
        counter[letter - 'a']++;
    }

    int max = 0;
    int min = text.size() + 1;
    char mostFrequent, leastFrequent;

    for (int i = 0; i < 26; i++) {
        if (counter[i] > max) {
            max = counter[i];
            mostFrequent = (char)('a' + i);
        }
        if (counter[i] < min && counter[i] > 0) {
            min = counter[i];
            leastFrequent = (char)('a' + i);
        }
    }

    std::cout << mostFrequent << " ";
    std::cout << leastFrequent;

    return 0;
}