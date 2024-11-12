#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int step_count = 0; // Global step counter

void printFibonacci(int n) {
    step_count++; // Counting the check for n > 0
    static int n1 = 0, n2 = 1, n3;
    if (n > 0) {
        n3 = n1 + n2;
        step_count++; // Counting the addition n3 = n1 + n2
        n1 = n2;
        n2 = n3;
        step_count += 2; // Counting the updates n1 = n2 and n2 = n3
        cout << n3 << " "; // Print Fibonacci number (not counted as a step)
        printFibonacci(n - 1); // Recursive call
        step_count++; // Counting the recursive call itself
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    cout << "0 " << "1 "; // First two numbers of the series (not counted as a step)

    auto start_time = high_resolution_clock::now();

    printFibonacci(n - 2); // Calculate and print the Fibonacci sequence (excluding first two terms)

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "\nElapsed Time: " << duration.count() << " microseconds" << endl;
    cout << "Total Steps for Calculation: " << step_count << endl; // Display calculation-related steps only

    return 0;
}