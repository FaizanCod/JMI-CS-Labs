#include <iostream>
#include <string.h>
using namespace std;

struct employee {
    int empid;
    char name[20];
    int salary;
}emp[10];

int count=-1;

void add();
int check_id(int id)
{
    for (int i=0; i<=count; i++)
    {
        if (id==emp[i].empid)
        {
            cout<<"\nID already in record! Enter again...\n";
            count--;
            return -1;
        } 
        return 0;
    }
}
void add ()
{
    int id;
    count++;
    cout<<"\nEnter the details of the employee:\n";
    cout<<"Enter the employee id: ";
    cin>>id;
    if (check_id(id)==-1)
     add();
    else
    {
        emp[count].empid=id;
        cout<<"Enter the employee name: ";
        char g=getchar();                       //or cin.ignore();
        cin.getline(emp[count].name, 20);
        cout<<"Enter salary: ";
        cin>>emp[count].salary;
    }
}

void display()
{
    cout<<"\nEMPLOYEE DETAILS:\n\n";
    cout<<"Employee ID\t\tEmployee name\t\tSalary\n";
    for (int i=0; i<=count; i++)
    {
        cout<<emp[i].empid;
        cout<<"\t\t\t"<<emp[i].name;
        cout<<"\t\t\t"<<emp[i].salary<<endl;
    } 
}

void search_empid(int key)
{
    int flag=0;
    for (int i=0; i<=count; i++)
    {
        if (emp[i].empid==key)
        {
            flag=1;
            cout<<"\nEmployee found in record!";
            cout<<"\nEMPLOYEE DETAILS:\n\n";
            cout<<"Employee ID\t\tEmployee name\t\tSalary\n";
            cout<<emp[i].empid;
            cout<<"\t\t\t"<<emp[i].name;
            cout<<"\t\t\t"<<emp[i].salary;
            if (flag==1)
             break;
            else if (flag==0)
             cout<<"\nEmployee not found in record!";
        }
    }
}

void search_name(char test[])
{
    int flag=0;
    for (int i=0; i<=count; i++)
    {
        if (strcmp(test, emp[i].name)==0)
        {
            flag=1;
            cout<<"\nEmployee found in record!";
            cout<<"\nEMPLOYEE DETAILS:\n\n";
            cout<<"Employee ID\t\tEmployee name\t\tSalary\n";
            cout<<emp[i].empid;
            cout<<"\t\t\t"<<emp[i].name;
            cout<<"\t"<<emp[i].salary;
            if (flag==1)
             break;
            else if (flag==0)
             cout<<"\nEmployee not found in record!";
        }
        // if (flag==1)
        //  return;
    }
    cout<<"\nEmployee not found in record!";
}

void highest_salary()
{
    int mx=0, index;
    for (int i=0; i<count; i++)
    {
        if (emp[i].salary>mx)
        {
            mx=emp[i].salary;
            index=i;
        } 
    }
    cout<<"Employee with the highest salary is:\n";
    cout<<"Employee ID\t\tEmployee name\t\tSalary\n";
    cout<<emp[index+1].empid;
    cout<<"\t\t\t"<<emp[index+1].name;
    cout<<"\t\t\t"<<emp[index+1].salary;
}

int main()
{
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021";
    
    int ch, key;
    char test[20], g1;
    while (1)
    {
        A:
        cout<<"\n\nMENU\n1. Add employee.\n2. Display all employees.\n3. Search employee by empid.\n4. Search employee by name.\n5. Employee having Highest Salary.\n6. Exit\n";
        cin>>ch;
        switch (ch)
        {
            case 1: if (count==10)
                    {
                        cout<<"\nMaximum employee limit (10) reached!\n";
                        goto A;
                    } 
                    else if (count<10)    
                     add();
                    break;
            case 2: if (count==-1)
                    {
                        cout<<"\nRecord is empty, add some employee details first!\n";
                        goto A;
                    }
                    else
                     display();
                    break;
            case 3: cout<<"\nEnter employee ID to be searched for: ";
                    cin>>key;
                    search_empid(key);
                    break;
            case 4: cout<<"\nEnter employee name to be searched for (case-sensitive): ";
                    g1=getchar();
                    cin.getline(test, 20);
                    search_name(test);
                    break;
            case 5: highest_salary();
                    break;
            case 6: exit(0);
            default: cout<<"\nWrong choice! Enter again...\n";
                     goto A;
        }
    }
    return 0;
}