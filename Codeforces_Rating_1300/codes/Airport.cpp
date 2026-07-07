#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Priority queues (max-heap for maximum revenue, min-heap for minimum revenue)
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // Input the planes' seat counts into both heaps
    for (int i = 0; i < m; i++) {
        int seats;
        cin >> seats;
        max_heap.push(seats);
        min_heap.push(seats);
    }

    int max_revenue = 0, min_revenue = 0;

    // Calculate maximum revenue
    for (int i = 0; i < n; i++) {
        int top_seats = max_heap.top();
        max_heap.pop();
        max_revenue += top_seats;
        if (top_seats > 1) max_heap.push(top_seats - 1);
    }

    // Calculate minimum revenue
    for (int i = 0; i < n; i++) {
        int top_seats = min_heap.top();
        min_heap.pop();
        min_revenue += top_seats;
        if (top_seats > 1) min_heap.push(top_seats - 1);
    }

    cout << max_revenue << " " << min_revenue << endl;

    return 0;
}

