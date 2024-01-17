#include <bits/stdc++.h>
using namespace std;

int sstf(vector<int> &requests, int current_head)
{
    int total_seek_time = 0;
    vector<int> seekSequence;

    while (!requests.empty())
    {
        auto min_it = min_element(requests.begin(), requests.end(), [current_head](int a, int b) {
            return abs(current_head - a) < abs(current_head - b);
        });

        seekSequence.push_back(*min_it);
        total_seek_time += abs(current_head - *min_it);
        current_head = *min_it;
        requests.erase(min_it);
    }

    // Print the seek sequence
    cout << "Seek sequence: " << seekSequence[0];
    for (int i = 1; i < seekSequence.size(); i++)
    {
        cout << " --> " << seekSequence[i];
    }
    cout << endl;

    return total_seek_time;
}

int main()
{
    int qsize, current_head;

    cout << "Enter the queue size: ";
    cin >> qsize;

    if (qsize < 1)
    {
        cout << "Invalid queue size. Exiting.\n";
        return 1;
    }

    vector<int> requests(qsize);

    cout << "Enter the values of the request queue:\n";
    for (int i = 0; i < qsize; i++)
    {
        cin >> requests[i];
    }

    cout << "Enter the current position of the head: ";
    cin >> current_head;

    int seek_time = sstf(requests, current_head);

    cout << "Total seek time: " << seek_time << endl;

    return 0;
}
