#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Location {
    string name;
    int num_of_steps;
};

bool comp(const Location& x, const Location& y) {
    if (x.num_of_steps == y.num_of_steps)
        return x.name > y.name;
    return x.num_of_steps > y.num_of_steps;
}

int medians(vector<Location>& array, int smaller, int bigger) {
    if (bigger - smaller < 5) {
        sort(array.begin() + smaller, array.begin() + bigger + 1, comp);
        return (smaller + bigger) / 2;
    }

    for (int i = smaller; i <= bigger; i += 5) {
        int end = min(i + 4, bigger);
        sort(array.begin() + i, array.begin() + end + 1, comp);
        int median = (i + end) / 2;
        swap(array[smaller + (i - smaller) / 5], array[median]);
    }

    return medians(array, smaller, smaller + ceil((bigger - smaller) / 5.0) - 1);
}

int partition(vector<Location>& array, int smaller, int bigger, int pivotIndex, int& k) {
    Location pivotValue = array[pivotIndex];
    swap(array[pivotIndex], array[bigger]);

    int i = smaller;
    int j = bigger - 1;

    while (true) {
        while (i <= j && comp(array[i], pivotValue)) {
            i++;
        }
        while (i <= j && !comp(array[j], pivotValue)) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(array[i], array[j]);
    }

    swap(array[i], array[bigger]);

    if (k < i) {
        return i;
    }
    if (k <= i) {
        return k;
    }
    return i;
}

Location select_element(vector<Location>& array, int smaller, int bigger, int k) {
    while (true) {
        if (smaller == bigger) {
            return array[smaller];
        }
        int a = medians(array, smaller, bigger);
        a = partition(array, smaller, bigger, a, k);

        if (k == a) {
            return array[k];
        } else if (k < a) {
            bigger = a - 1;
        } else {
            smaller = a + 1;
        }
    }
}

Location hoare_algorithm(vector<Location>& array, int k) {
    int n = array.size();
    int smaller = 0;
    int bigger = n - 1;
    if (n <= 10) {
        sort(array.begin(), array.end(), comp);
        return array[k];
    }

    return select_element(array, smaller, bigger, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, d, a;
    cin >> n;

    vector<Location> locations(n);
    for (int i = 0; i < n; i++) {
        cin >> locations[i].name >> locations[i].num_of_steps;
    }

    cin >> d >> a;

    vector<int> numbers(a);

    for (int i = 0; i < a; i++) {
        cin >> numbers[i];
        Location tmp = hoare_algorithm(locations, numbers[i]);
        if (d - tmp.num_of_steps * 2 >= 0) {
            cout << tmp.name << " ";
            d = d - tmp.num_of_steps * 2;
        }
        else cout << "NIE" << " ";
    }

    return 0;
}
