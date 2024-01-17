#include<bits/stdc++.h>

using namespace std;

void FCFS(int n, int arr[], int head) {
    int distance = 0;
    vector<int> seekSequence; // To store the seek sequence

    // Traverse the array and keep adding the absolute difference to the distance to get the head movements
    for (int i = 0; i < n - 1; i++) {
        distance += abs(arr[i] - arr[i + 1]);
        seekSequence.push_back(arr[i]);
    }
    // Add the initial head movement to the first request
    distance += abs(head - arr[0]);
    seekSequence.push_back(arr[0]);

    // Display the seek sequence
    cout << "Seek sequence: " << head << " --> ";
    for (int i = 0; i < seekSequence.size(); i++) {
        cout << seekSequence[i];
        if (i != seekSequence.size() - 1) {
            cout << " --> ";
        }
    }

    cout << "\nThe head movements are: " << distance;
}

int main() {
    // Take the seek sequence
    int size, head;
    cout << "Enter the size of the request array: ";
    cin >> size;
    int seek[size];
    cout << "Enter the values in the request queue: ";
    for (int i = 0; i < size; i++) {
        cin >> seek[i];
    }
    cout << "Enter the address of the head: ";
    cin >> head;
    FCFS(size, seek, head);

    return 0;
}
