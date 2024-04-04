#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

struct Monkey {
    char letter;
    int value;
    std::vector<Monkey*> Kids;
};

void preorderTraversal(Monkey* root) {
    std::stack<Monkey*> Stack;
    std::vector<char> Preorder;

    Stack.push(root);

    while (!Stack.empty()) {
        Monkey* temp = Stack.top();
        Stack.pop();
        Preorder.push_back(temp->letter);

        for (int i = temp->Kids.size() - 1; i >= 0; i--) {
            Stack.push(temp->Kids[i]);
        }
    }

    for (char letter : Preorder) {
        std::cout << letter;
    }
}

int main() {
    int K;
    std::cin >> K;

    for (int k = 0; k < K; ++k) {
        int n;
        std::cin >> n;

        Monkey* first = new Monkey();
        std::queue<Monkey*> que;

        for (int i = 0; i < n; ++i) {
            char letter;
            int value;
            std::cin >> letter >> value;

            Monkey* new_ = new Monkey();
            new_->letter = letter;
            new_->value = value;

            if (i == 0) {
                *first = *new_;
                que.push(first);
            } else {
                if (new_->value != 0) {
                    que.push(new_);
                }

                if (que.front()->value != 0) {
                    que.front()->Kids.push_back(new_);
                    que.front()->value -= 1;
                }

                if (que.front()->value == 0) {
                    que.pop();
                }
            }
        }
        if(k == 0){
            std:: cout << std:: endl;
        }
        preorderTraversal(first);
        std:: cout << std:: endl;
    }

    return 0;
}