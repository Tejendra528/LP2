#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    Job jobs[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(jobs)/sizeof(jobs[0]);
    sort(jobs, jobs + n, compare);

    int result[3] = {-1, -1, -1};
    bool slot[3] = {false, false, false};

    for (int i = 0; i < n; i++) {
        for (int j = min(2, jobs[i].deadline - 1); j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for (int i = 0; i < 3; i++)
        if (result[i] != -1)
            cout << jobs[result[i]].id << " ";
    return 0;
}
