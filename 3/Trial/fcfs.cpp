#include <bits/stdc++.h>
using namespace std;

float wt(int wait[], int n)
{
    float avg;
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + wait[i];
    }
    avg = sum / n;

    return avg;
}

//-------------------------

float tat(int turn[], int n)
{
    float avg;
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + turn[i];
    }
    avg = sum / n;

    return avg;
}

//--------------------------

void gchart(int burst[], int n)
{
    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << "x" << (i + 1) << endl;
        else
            cout << "x" << (i + 1) << setw(6);
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << current_time << setw(6);
        current_time += burst[i];
    }
    cout << current_time << setw(6);
    cout << endl;
}

//------------------------

void display_chart(int n, int wait[], int burst[], int tnt[])
{
    cout << setw(15) << "Process  ";
    cout << setw(15) << "Burst time  ";
    cout << setw(15) << "Waiting time  ";
    cout << setw(15) << "Turn around time  ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << "x" << (i + 1);
        cout << setw(15) << burst[i];
        cout << setw(15) << wait[i];
        cout << setw(15) << tnt[i];
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << endl;

    int burst_time[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter burst time for process " << i << ":" << endl;
        cin >> burst_time[i];
    }

    int wait_time[n];
    wait_time[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wait_time[i] = burst_time[i - 1] + wait_time[i - 1];
    }

    int turn_around_time[n];
    for (int i = 0; i < n; i++)
    {
        turn_around_time[i] = burst_time[i] + wait_time[i];
    }

    float avg_wait_time = wt(wait_time, n);
    float avg_turn_time = tat(turn_around_time, n);

    cout << endl;
    cout << endl;

    display_chart(n, wait_time, burst_time, turn_around_time);

    cout << endl;
    cout << endl;

    cout << "Avg WT = " << avg_wait_time << endl;
    cout << "Avg TAT = " << avg_turn_time << endl;

    cout << endl;
    cout << endl;

    gchart(burst_time, n);
}