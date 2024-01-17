#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

class Process
{
public:
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turn_around_time;
    int visited = 0;
    int queue = 0;

    bool operator<(const Process &other) const
    {
        // Higher priority processes go first
        return priority > other.priority;
    }
};

bool compare(Process p1, Process p2)
{
    return p1.arrival_time < p2.arrival_time;
}

void take_input(vector<Process> &processes)
{

    for (int i = 0; i < processes.size(); i++)
    {
        cout << "Enter the arrival time, burst time and priority of process " << i + 1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time >> processes[i].priority;
        processes[i].pid = i + 1;
    }
    sort(processes.begin(), processes.end(), compare);
}

void schedule(vector<Process> &p)
{
    int current_time = p[0].arrival_time;
    vector<Process> np;
    priority_queue<Process> ready_queue;

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].arrival_time <= current_time && p[i].queue == 0)
        {
            ready_queue.push(p[i]);
            p[i].queue = 1;
        }
        while (!ready_queue.empty())
        {
            Process current_process = ready_queue.top();
            ready_queue.pop();
            current_process.waiting_time = current_time - current_process.arrival_time;
            current_process.turn_around_time = current_process.waiting_time + current_process.burst_time;
            current_time += current_process.burst_time;
            cout << current_time << endl;
            np.push_back(current_process);
        }
        // move this out of the while loop
        for (int j = 0; j < p.size(); j++)
        {
            if (p[j].arrival_time <= current_time && p[j].queue == 0)
            {
                ready_queue.push(p[j]);
                p[j].queue = 1;
            }
            else
            {
                continue;
            }
        }
    }
    // print
    cout << np.size() << endl;
    for (int i = 0; i < np.size(); i++)
    {
        cout << "Process " << np[i].pid << ":\n";
        cout << "Waiting time: " << np[i].waiting_time << endl;
        cout << "Turn around time: " << np[i].turn_around_time << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> processes(n);
    take_input(processes);
    schedule(processes);
    return 0;
}