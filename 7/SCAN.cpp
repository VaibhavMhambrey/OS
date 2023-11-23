#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int scan(vector<int> &rq, int current_head) {
    int head = current_head, distance = 0;
    vector<int> seq;
    sort(rq.begin(), rq.end());
    auto it = lower_bound(rq.begin(), rq.end(), head);
    int midPos;

    if (head > *it) {
        midPos = it - rq.begin();
    } else {
        midPos = it - rq.begin() - 1;
    }

    for (int i = midPos; i >= 0; i--) {
        distance += abs(rq[i] - current_head);
        if (i == 0) {
            distance += rq[0];
            current_head = 0;
            seq.push_back(rq[i]);
            seq.push_back(0);
        } else {
            current_head = rq[i];
            seq.push_back(rq[i]);
        }
    }

    for (int i = midPos + 1; i < rq.size(); i++) {
        distance += abs(rq[i] - current_head);
        current_head = rq[i];
        seq.push_back(rq[i]);
    }

    cout << "Seek sequence is: " << head << "-->";
    for (int i = 0; i < seq.size(); i++) {
        if (i == seq.size() - 1) {
            cout << seq[i];
        } else {
            cout << seq[i] << "-->";
        }
    }

    cout << endl;

    return distance;  // Return the total seek distance
}

int main() {
    int qsize, current_head;
    cout << "Enter the queue size: ";
    cin >> qsize;

    vector<int> requests(qsize);

    cout << "Enter the values of request queue" << endl;
    for (int i = 0; i < qsize; i++) {
        cin >> requests[i];
    }

    cout << "Enter the current pos of head: ";
    cin >> current_head;

    int seek_distance = scan(requests, current_head);

    cout << "Total seek distance: " << seek_distance << endl;

    return 0;
}
