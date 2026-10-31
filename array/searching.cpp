#include <iostream>
using namespace std;

int main() {
    int a[100], n, x, temp;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nEnter element to search: ";
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            cout << "Found at position " << i + 1;
            return 0;
        }
    }

    cout << "Not Found";

    return 0;
}
