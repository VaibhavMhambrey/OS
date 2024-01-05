#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int clook(vector<int> &rq, int current_head, int limit)
{
    int head = current_head, distance = 0;
    vector<int> seq;
    sort(rq.begin(), rq.end());

    auto it = upper_bound(rq.begin(), rq.end(), head);
    int midPos = (it - rq.begin()) % rq.size(); // Calculate the starting position in the sorted array

    for (int i = midPos; i < rq.size(); i++)
    {
        distance += abs(rq[i] - current_head);
        current_head = rq[i];
        seq.push_back(rq[i]);
    }

    for (int i = 0; i < midPos; i++)
    {
        distance += abs(rq[i] - current_head);
        current_head = rq[i];
        seq.push_back(rq[i]);
    }

    cout << "Seek sequence is: " << head << "-->";
    for (int i = 0; i < seq.size(); i++)
    {
        if (i == seq.size() - 1)
        {
            cout << seq[i];
        }
        else
        {
            cout << seq[i] << "-->";
        }
    }
    cout << endl;

    return distance;
}

int main()
{
    int qsize, current_head, limit;
    cout << "Enter the queue size: ";
    cin >> qsize;

    vector<int> requests(qsize);
    cout << "Enter the values of request queue" << endl;
    for (int i = 0; i < qsize; i++)
    {
        cin >> requests[i];
    }

    cout << "Enter the current pos of head" << endl;
    cin >> current_head;

    cout << "Enter the limit of the memory" << endl;
    cin >> limit;

    int seek_distance = clook(requests, current_head, limit);
    cout << "Total seek distance: " << seek_distance << endl;

    return 0;
}
