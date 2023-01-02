#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char n[10];
    int burst;
    int arrival;
    int completion;
    int waiting;
    int turnaround;
    int response;
    struct node *next;
};
struct node *front=NULL, *p, *ptr, *temp, *sjf=NULL;

// on the basis of arrival time
void insertProcess (char *pr, int bt, int at) {
    ptr = (struct node *) malloc (sizeof(struct node));
    if (ptr == NULL) {
        cout<<"\nMemory could not be allocated!\n";
        return;
    } 
    
    strcpy(ptr->n, pr);
    ptr->burst = bt;
    ptr->arrival = at;
    ptr->next=NULL;

    if (front == NULL || at < (front->arrival)) {
        ptr->next = front;
        front=ptr;
    }          
    else {
        p=front;
        while (p->next != NULL && p->next->arrival <= at)
            p=p->next;
        ptr->next = p->next;
        p->next = ptr;
    }
}

// on the basis of burst time
void SJFQueue (struct node **start, struct node **newp) {
    if ((*start) == NULL || (*newp)->burst < (*start)->burst) {
        (*newp)->next = *start;
        *start=*newp;
    }          
    else {
        struct node *x = *start;
        while (x->next != NULL && x->next->burst <= (*newp)->burst)
            x=x->next;
        (*newp)->next = x->next;
        x->next = (*newp);
    }
}

void SJF () {
    p = front;  
    struct node *r = sjf; 
    int current = p->arrival;       // time which begins from the process that arrived earliest
    struct node *q = NULL;                       // sjf/burst time queue pointer

    while (p != NULL) { 
        int t = 0;                  // time for executing all process in queue
        while (p != NULL && p->arrival <= current) {
            temp = p;          // dequeueing from ready queue
            p = p->next;
            temp->next = NULL;
            t += temp->burst;
            SJFQueue (&q, &temp);
        }

        int exTime = q->arrival;        // execution time of sjf queue
        while (q != NULL && q->arrival >= exTime) {
            if (p == NULL) {            // when ready queue is empty.
                if (sjf == NULL)
                    sjf = q;
                else
                    while (r->next != NULL)
                        r = r->next;
                    r->next = q;
                    break;
            }

            struct node *n = q;         // dequeueing from burst time queue
            q = q->next;
            n->next = NULL;
            if (sjf == NULL) {
                sjf = n;
                r = sjf;
            }
            else {
                while (r->next != NULL)
                    r = r->next;
                r->next = n;
            }
            exTime += n->burst;
        }
        if (p != NULL)
            if (current + t < p->arrival)
                current = p->arrival;       // updating current process' arrival time
            else
                current += t;
    }
}

void display () {
    double tot_ct = 0, tot_wt =0, tot_tat = 0, tot_rt =0;
    int count = 0, time = 0;
    p = front;
    cout<<"\n\nProcess | Burst Time | Arrival Time | Completion Time | Waiting Time | Turnaround Time | Response Time\n";
    cout<<"_______________________________________________________________________________________________________\n\n";
    while (p != NULL) {
        if (time < p->arrival) {
            while (time != p->arrival)
                time++;
        }
        p->response = time - p->arrival;
        time += p->burst;
        p->completion = time;   // completion occurs after burst time ends
        p->turnaround = p->completion - p->arrival;     // tat = ct - at = wt + bt
        p->waiting = p->turnaround - p->burst;          // wt = tat - bt

        printf("   %s        %2d            %2d                %2d               %2d             %2d              %2d\n", p->n, p->burst, p->arrival, p->completion, p->waiting, p->turnaround, p->response);

        tot_ct += p->completion;
        tot_wt += p->waiting;
        tot_tat += p->turnaround;
        tot_rt += p->response;

        count++;
        p = p->next;
    }
    cout<<"_______________________________________________________________________________________________________\n\n";

    printf("\nAverage Completion time: %.2f",tot_ct / (float) count);
    printf("\nAverage Waiting time: %.2f", tot_wt / (float) count);
    printf("\nAverage Turnaround time: %.2f",tot_tat / (float) count);
    printf("\nAverage Response time: %.2f\n",tot_rt / (float) count);
}

void displayGantt () {
    int time = 0;
    p = front;
    cout<<"\nGantt chart: \n";
    // for printing structure
    while (p != NULL) {
        cout<<"|";
        if (time < p->arrival) {
            while (time != p->arrival) {
                time++;
            }
            time += p->burst;
            cout<<"  |";
        }
        else {
            time += p->arrival;
            if (front->arrival == 0)
                time += p->burst;
        }
        for (int i=0; i<(p->burst-1); i++)
            cout<<" ";
        cout<<p->n;
        for (int i=0; i<(p->burst-1); i++)
            cout<<" ";
        p = p->next;
    }
    cout<<"|"<<endl;
    p = front;
    time = 0;
    // for printing time below each process
    if (time < p->arrival && p->arrival != 0) {
        cout<<time;
        while (time != p->arrival) {
            time++;
        }
        time += p->burst;
        cout<<"  ";
    }
    cout<<p->arrival;
    while (p != NULL) {
        if (time < p->arrival) {
            while (time != p->arrival) {
                time++;
            }
            if (time < 9)
                cout<<" "<<time;
            else
                cout<<time;
            time += p->burst;
        }
        else {
            time += p->arrival;
            if (front->arrival == 0)
                time += p->burst;
        }
        for (int i=0; i< 2*(p->burst)-1; i++)
            cout<<" ";
        if (p->completion < 9)
            cout<<"  "<<p->completion;
        else
            cout<<p->completion;
        p = p->next;
    }
    cout<<endl<<endl;
}

void del () {
    p = front;
    front=front->next;
    delete p;
}

int main () {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    cout<<"\nShortest Job First (Non-Preemptive) Scheduling Algorithm\n";
    int n;

    cout<<"\nEnter the number of processes: ";
    cin>>n;
    char k[n][10];
    int bt[n], at[n];                   // burst time and arrival time

    cout<<"\nEnter process names: ";
    for (int i=0; i<n; i++)
        cin>>k[i];
    cout<<"\nEnter burst time for each process: ";
    for (int i=0; i<n; i++)
        cin>>bt[i];
    cout<<"\nEnter arrival time for each process: ";
    for (int i=0; i<n; i++)
        cin>>at[i];

    for (int i=0; i<n; i++)
        insertProcess(k[i],bt[i],at[i]);

    SJF ();            // logic for calculating various times
    display ();         // displaying calculated values of time
    displayGantt ();    // to display Gantt chart
    del ();             // releasing memory

    return 0;
}