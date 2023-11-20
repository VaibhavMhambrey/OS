#include <stdio.h>
struct task
{
    int taskID;
    int bur;
    int arr;
    int wait;
    int turn;
    int prio;
    int ps;
    int pe;
};
int main()
{
    int n, i, b, a, c, j, min, k;
    float awt, att;
    printf("\nEnter number of processes:");
    scanf("%d", &n);
    struct task processes[n];
    struct task temp1, temp2;
    for (i = 0; i < n; i++)
    {
        processes[i].taskID = i;
        printf("\nEnter burst time:");
        scanf("%d", &b);
        processes[i].bur = b;
        printf("\nEnter arrival time:");
        scanf("%d", &a);
        processes[i].arr = a;
        printf("\nEnter priority:");
        scanf("%d", &c);
        processes[i].prio = c;
    }
    // sorting
    for (i = 0; i < n; i++)
    {
        temp1 = processes[i];
        temp2 = temp1;
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (processes[j].arr < temp1.arr)
            {
                temp1 = processes[j];
                min = j;
            }
            else if (processes[j].arr == temp1.arr)
            {
                if (processes[j].prio < temp1.prio)
                {
                    temp1 = processes[j];
                    min = j;
                }
            }
        }
        processes[i] = temp1;
        processes[min] = temp2;
    }
    // sort 2
    int curt = processes[0].arr;
    for (i = 0; i < n; i++)
    {
        processes[i].pe = curt + processes[i].bur;
        for (j = i + 1; j < n; j++)
        {
            temp1 = processes[j];
            temp2 = temp1;
            min = j;
            for (k = j + 1; k < n; k++)
            {
                if ((processes[k].arr) <= (processes[i].pe))
                {
                    if ((processes[k].prio) < (temp1.prio))
                    {
                        temp1 = processes[k];
                        min = k;
                    }
                }
            }
            processes[j] = temp1;
            processes[min] = temp2;
        }
        curt = processes[i].pe;
    }
    int tt = processes[0].arr;
    for (i = 0; i < n; i++)
    {
        processes[i].wait = tt - processes[i].arr;
        tt += processes[i].bur;
        processes[i].turn = processes[i].bur + processes[i].wait;
    }
    // display
    printf("\nPID\tPrio\tBT\tAT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {

        printf("\n%d\t%d\t%d\t%d\t%d\t%d", processes[i].taskID, processes[i].prio, processes[i].bur, processes[i].arr, processes[i].wait, processes[i].turn);
    }
    for (i = 0; i < n; i++)
    {
        processes[i].ps = processes[i].arr + processes[i].wait;
    }
    // calculating averages
    awt = att = 0;
    for (i = 0; i < n; i++)
    {
        awt += processes[i].wait;
        att += processes[i].turn;
    }
    awt /= n;
    att /= n;
    printf("\nAverage waiting time:%f\nAverage turnaround time:%f", awt, att);
    // gant chart
    i = 0;
    printf("\nGannt Chart:\n");
    for (j = 0; j < processes[n - 1].ps + processes[n - 1].bur; j++)
    {
        if (j == processes[i].ps)
        {
            printf("P%d(%d)", processes[i].taskID, processes[i].ps);
            i += 1;
        }
        printf("--");
        if (j == processes[n - 1].ps + processes[n - 1].bur - 1)
        {
            printf("(%d)", j + 1);
        }
    }
}
