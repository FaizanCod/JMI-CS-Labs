#include <iostream>
#include <limits.h>
using namespace std;
// n for number of pages in reference string, no for number of pages available in page slots (frames)
int n, no;
// hit_indices[100] to store the indices of the pages that are hit
int hit_indices[100];
// counter variable to keep track of number of page slots filled
int counter=0;
// page_faults to count the number of page faults
int page_faults=0;
// pointer for the dist array to store the distance of each page from the current page in the ref_str
int *dist;

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

void LRU_replacement(int *ref_str, int *page_slots) {
    for (int i=0; i<n; i++) {
        // condition for empty page slots (frames)
        if (counter < no) {
            page_faults++;
            page_slots[counter++] = ref_str[i];
        }
        // page hit condition
        else if (findIndex(ref_str[i], page_slots) != -1) {
            hit_indices[i] = findIndex(ref_str[i], page_slots);
        }
        // LRU replacement
        else {
            // mx variable to store max value of dist array, idx to store the index of this max value
            int mx = INT_MIN, idx;
            // looping through page slots to find the max value of dist array
            for (int j=0; j<no; j++) {
                // initializing dist array for each element in page_slots
                dist[j] = 0;
                // reverse looping through the ref_str (only for the elements in page_slots) to update the distance of each page from the current page
                // the greater the distance the least used the page will be
                for (int k=i-1; k>=0; k--) {
                    ++dist[j];
                    // if match found, stop increasing the distance
                    if (page_slots[j] == ref_str[k])
                        break;
                }
                // replacing mx with the max value of dist array and storing index in idx
                if (mx < dist[j]) {
                    mx = dist[j];
                    idx = j;
                }
            }
            page_faults++;
            // inserting at the max idx found
            page_slots[idx] = ref_str[i];
        }
        display(ref_str[i], page_slots, hit_indices[i]);          
    }
}

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";
    cout<<"\nLeast Recently Used (LRU) Page Replacement\n";
    cout<<"\nEnter the number of elements in page reference string: ";
    cin>>n;

    int *ref_str = new int[n];  
    dist = new int[n];

    cout<<"\nEnter the reference string: ";
    for (int i=0; i<n; i++)
        cin>>ref_str[i];

    cout<<"\nEnter the number of page slots (pages that can be accomodated in memory): ";
    cin>>no;
    int *page_slots = new int[no];
    for (int i=0; i<no; i++) 
        page_slots[i] = -1;

    for (int i=0; i<n; i++)
        hit_indices[i] = -1;

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
    LRU_replacement (ref_str, page_slots);

    double avg_page_fault = (double)page_faults/n;
    cout<<"\nNumber of page faults: "<<page_faults<<endl;
    cout<<"Number of page hits: "<<n-page_faults<<endl;
    cout<<"\nHit Ratio: "<<(1-avg_page_fault)<<endl;
    cout<<"Average number of page faults (Miss ratio): "<<avg_page_fault<<endl<<endl;

    return 0;
}