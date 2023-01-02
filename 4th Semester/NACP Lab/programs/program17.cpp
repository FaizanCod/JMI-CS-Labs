#include <iostream>
#include <limits.h>
using namespace std;

// reduced number of variables for easier input
const int MAX = 3, NUM = 3;

struct student {
    int id;
    char name[20];
    float marks[NUM];
    float total;
    float avg;
} st[MAX];

void input () {
    for (int i=0; i<MAX; i++) {
        st[i].id = i+1;
        st[i].total = 0;
        st[i].avg = 0;
        cout<<"\nEnter the details of student "<<i+1<<": ";
        // cout<<"\nEnter the ID: ";
        // cin>>st[i].id;
        cout<<"\nEnter the name: ";
        fflush(stdin);
        cin.getline(st[i].name, 20);
        cout<<"\nEnter the marks in three subjects: ";
        for (int j=0; j<NUM; j++) {
            cin>>st[i].marks[j];
            st[i].total += st[i].marks[j];
        }
        st[i].avg = st[i].total / NUM;
    }
}

void display () {
    cout<<"\nID\tName\t\t\tMarks\t\tTotal\tAverage\n";
    for (int i=0; i<MAX; i++) {
        cout<<st[i].id<<"\t"<<st[i].name<<"\t";
        for (int j=0; j<NUM; j++) {
            cout<<st[i].marks[j]<<"\t";
        }
        cout<<st[i].total<<"\t"<<st[i].avg<<endl;
    }
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    int i, idx;
    float sum = 0, max = INT_MIN;

    input();
    display();
    for (i=0; i<MAX; i++) {
        if (st[i].total > max) {
            max = st[i].total;
            idx = i;
        }
    }

    cout<<"\nThe student with the highest total is: "<<endl;
    cout<<st[idx].id<<"\t"<<st[idx].name<<"\t";
    for (int j=0; j<NUM; j++) {
        cout<<st[idx].marks[j]<<"\t";
    }
    cout<<st[idx].total<<"\t"<<st[idx].avg<<endl;

    return 0;
}