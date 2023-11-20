#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*Shortest Job First Scheduling C++ */

    int p, i, j, min, index;
    int sum = 0;
    float awt = 0, atat = 0;

    cout << "Enter The Total Number of Process:\n ";
    cin >> p;

    int proc[p];

    int *cbt = new int[p];
    int *wt = new int[p];
    int *gc = new int[p];
    int *tat = new int[p];
    int *tmp = new int[p];

    cout << "Enter BT of Process:\n";

    for (i = 0; i < p; i++)
    {
        cin >> cbt[i];
        tmp[i] = cbt[i];
    }

    sort(cbt, cbt + p);

    cout << "\nSJF gantt chart\n";

    for (j = 0; j <= p; j++)
    {
        min = 100;
        for (i = 0; i < p; i++)
        {
            if (min > tmp[i] && tmp[i] != -1)
            {
                min = tmp[i];
                index = i;
            }
        }

        gc[j] = sum;
        wt[j] = sum;
        sum += tmp[index];
        tat[j] = sum;
        tmp[index] = -1;

        if (j == p)
            break;
        cout << 'P' << index + 1 << "  |  ";
        proc[j] = index + 1;
    }
    cout << "\n";
    /*sum = 0;

    for (j = 0; j <= p; j++)
    {
        if (gc[j] < 10)
            cout << 0;
        cout << gc[j] << "    ";
        sum = sum + gc[j];
    }

    cout << endl;

    atat = (sum * 1.0) / p;
*/
    cout << "\nProcess\t\tBT\tWT\tTAT\n";

    for (i = 0; i < p; i++)
    {
        cout << "P[" << proc[i] << "]\t\t" << cbt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
        awt = awt + wt[i];
    }

    awt = (awt * 1.0) / p;

    cout << "\n\nTotal Waiting Time: " << awt;
    cout << "\n\nTotal Turn Around Time: " << atat << endl;

    return 0;
}