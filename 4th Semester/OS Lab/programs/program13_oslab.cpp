#include <iostream>
using namespace std;
// n for number of pages in reference string, no for number of pages available in page slots (frames)
int n, no;
// hit_indices[100] to store the indices of the pages that are hit
int hit_indices[100];
// counter to maintain FIFO and circularity of page slots
int counter=0;
// page_faults to count the number of page faults
int page_faults=0;

// to find the index of the page hit
int findIndex (int ref_ele, int *page_slots) {
    for (int i=0; i<no; i++) {
        if (page_slots[i] == ref_ele)
            return i;
    }
    return -1;
}

void display (int ref_ele, int *page_slots, int hit_index) {
    cout<<"|\t      "<<ref_ele<<"\t          |\t"<<(hit_index != -1 ? "Hit  " : "Fault")<<"     |";
    for (int i=0; i<no; i++)
        cout<<" ";
    for (int i=0; i<no; i++) {
        if (page_slots[i] != -1) 
            cout<<page_slots[i]<<"  ";
        else    
            cout<<"-  ";
    }
    for (int i=2; i<no; i++)
        cout<<" ";
    cout<<"|\n";
}

void FIFO_replacement(int *ref_str, int *page_slots) {
    // looping through input string
    for (int i=0; i<n; i++) {
        // for each page in ref_str, loop through page slots 
        for (int j=0; j<no; j++) {
            // if page_slots are empty
            if (page_slots[j] == -1) {
                page_faults++;
                page_slots[j++] = ref_str[i];
                break;
            }
            // page hit condition
            else if (page_slots[j] != -1 && findIndex(ref_str[i], page_slots) != -1) {
                // storing the index of page in hit_indices
                hit_indices[i] = findIndex(ref_str[i], page_slots);
                break;
            }
            // FIFO replacement, circularity of page slots
            else {
                page_faults++;
                counter = (counter + 1) % no;
                page_slots[counter] = ref_str[i];
                break;
            }
        }
        display(ref_str[i], page_slots, hit_indices[i]);          
    }
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    cout<<"\nFirst In First Out (FIFO) Page Replacement\n";
    cout<<"\nEnter the number of elements in page reference string: ";
    cin>>n;
    int *ref_str = new int[n];    
    cout<<"\nEnter the reference string: ";
    for (int i=0; i<n; i++)
        cin>>ref_str[i];

    cout<<"\nEnter the number of page slots (pages that can be accomodated in memory): ";
    cin>>no;
    int *page_slots = new int[no];
    
    // assigning invalid indexing
    for (int i=0; i<no; i++) 
        page_slots[i] = -1;

    for (int i=0; i<n; i++) 
        hit_indices[i] = -1;

    // cout<<endl<<" -------------------------------------------------------- ";
    cout<<"\n|  Reference String Entry |   Hit/Fault   |";
    for (int i=1; i<no; i++)
        cout<<" ";
    if (no < 4)
        cout<<"Page Slots";
    else
        cout<<" Page Slots ";
    for (int i=1; i<no; i++)
        cout<<" ";
    cout<<"|\n\n";
    // cout<<" -------------------------------------------------------- \n";
    FIFO_replacement (ref_str, page_slots);
    // cout<<" -------------------------------------------------------- \n";

    double avg_page_fault = (double)page_faults/n;
    cout<<"\nNumber of page faults: "<<page_faults<<endl;
    cout<<"Number of page hits: "<<n-page_faults<<endl;
    cout<<"\nHit Ratio: "<<(1-avg_page_fault)<<endl;
    cout<<"Average number of page faults (Miss ratio): "<<avg_page_fault<<endl<<endl;

    return 0;
}