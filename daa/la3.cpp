#include <iostream>
#include <algorithm> // Include this for 'sort'
#include <chrono>
#include <iomanip>
using namespace std;
struct Item {
    int value;
    int weight;
};

class Solution {
    public:
    static bool comp(Item a, Item b) {
        
    
    double r1 = static_cast<double>(a.value) / static_cast<double>(a.weight);
    double r2 = static_cast<double>(b.value) / static_cast<double>(b.weight);
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, comp);
int curWeight = 0;
double finalValue = 0.0;
for (int i = 0; i < n; i++) {
    if (curWeight + arr[i].weight <= W) {
curWeight += arr[i].weight;
finalValue += arr[i].value;
} else {
int remain = W - curWeight;
finalValue += (arr[i].value / static_cast<double>(arr[i].weight)) *
static_cast<double>(remain);
break;
}
}
return finalValue;
}
};

int main() {
    int n = 3, weight = 50;
    Item arr[n] = { {100,20},{60,10},{120,30} };
    Solution obj;
    auto start_time = chrono::high_resolution_clock::now();
    double ans = obj.fractionalKnapsack(weight, arr, n);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time -
    start_time);
    cout << "The maximum value is " << fixed << setprecision(2) << ans <<endl;
    cout << "Elapsed Time: " << duration.count() << " microseconds" << endl;
    return 0;
}