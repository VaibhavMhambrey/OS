#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int scan(vector<int> &rq, int current_head, int limit) {
    int head = current_head, distance = 0;
    vector<int> seq;
    sort(rq.begin(), rq.end());
    auto it = lower_bound(rq.begin(), rq.end(), head);
    int midPos = it - rq.begin();

    for (int i = midPos; i < rq.size(); i++) {
        distance += abs(rq[i] - current_head);
        current_head = rq[i];
        seq.push_back(rq[i]);
    }

    if (midPos < rq.size()) {
        distance += abs(rq.back() - limit) + limit;
        current_head = 0;
        seq.push_back(limit);
        seq.push_back(0);
    }

    for (int i = 0; i < midPos; i++) {
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

    vector<int> requests;
    requests.resize(qsize);

    cout << "Enter the values of request queue" << endl;
    for (int i = 0; i < qsize; i++) {
        cin >> requests[i];
    }

    cout << "Enter the current pos of head: ";
    cin >> current_head;

    int limit;
    cout << "Enter the limit of the memory: ";
    cin >> limit;

    int seek_distance = scan(requests, current_head, limit);

    cout << "Total seek distance: " << seek_distance << endl;

    return 0;
}
