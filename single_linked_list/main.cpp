#include <iostream>
#include <string>

struct Actor{
    std::string name;
    int fans;
    Actor* next;
};

class List {
private:
    Actor *first;
public:
    List(){
        first = nullptr;
    }


    void add(const std::string name, int fans) {
        Actor* newActor = new Actor;
        newActor->name = name;
        newActor->fans = fans;
        newActor->next = nullptr;

        Actor* temp = first;

        if (first == nullptr) {
            first = newActor;
            std::cout << "TAK" << std::endl;
            return;
        } else {
            if (temp->name == name && temp->fans == fans) {
                std::cout << "NIE" << std::endl;
                delete newActor;
                return;
            }

            while (temp->next != nullptr) {
                if (temp->next->name == name && temp->next->fans == fans) {
                    std::cout << "NIE" << std::endl;
                    delete newActor;
                    return;
                }
                temp = temp->next;
            }
            temp->next = newActor;
            std::cout << "TAK" << std::endl;
        }
    }

    void find(int max) {
        if (first == nullptr) {
            std::cout << "NIE" << std::endl;
            return;
        }

        Actor* selectedActor = nullptr;
        Actor* prev = nullptr;
        Actor* temp = first;
        Actor* prevSelectedActor = nullptr;

        while(temp != nullptr){
            if(temp->fans <= max){
                selectedActor = temp;
                prevSelectedActor = prev;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        while(temp != nullptr){
            if(temp->fans <= max){
                if(temp->fans > selectedActor->fans){
                    selectedActor = temp;
                    prevSelectedActor = prev;
                } else if(temp->fans == selectedActor->fans && temp->name < selectedActor->name){
                    selectedActor = temp;
                    prevSelectedActor = prev;
                }
            }
            prev = temp;
            temp = temp->next;
        }

        if (selectedActor != nullptr) {

            std::cout << selectedActor->name << std::endl;

            if (prevSelectedActor == nullptr) {
                first = selectedActor->next;
            } else {
                prevSelectedActor->next = selectedActor->next;
            }
            delete selectedActor;
        } else {
            std::cout << "NIE" << std::endl;
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    List list;
    int n;
    std:: cin >> n;
    std:: string op;

    for(long long i = 0; i < n; i++) {
        std:: cin.ignore();
        std:: getline(std:: cin, op);
        if (std:: stoi(op) == 1) {
            std:: string name;
            int fans;
            getline(std:: cin, name);
            std:: cin >> fans;

            list.add(name, fans);
        }

        if (std:: stoi(op) == 2) {
            int max;

            std:: cin >> max;

            list.find(max);
        }
    }

    return 0;
}