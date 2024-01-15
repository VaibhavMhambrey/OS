#include <bits/stdc++.h>
using namespace std;

int var=0;
void accessPages(vector<int> &page, int page_number, int max_size, int &faults ,vector<int> &order) {
    auto it = find(page.begin(), page.end(), page_number);

    if (it != page.end()) {
        page.erase(it); // This removes the page if it is already present in the memory and is not a page fault
    } else {
        faults++; // If the page is not present in the page vector, then there is a fault, so increment it
    }
    page.push_back(page_number);
    if(page.size()<=max_size){
        order.push_back(page_number);
    }else{
       auto it = find(order.begin(),order.end(),page[0]);
       *it=page_number;
    }
    if (page.size() > max_size) {
        page.erase(page.begin());
    }
    var++;
	cout<<"iteration"<<var<<": ";	
	 for (int i = 0; i < max_size; i++) {
        if (i < order.size()) {
            cout<<order[i]<<" ";
        }
    }
	cout<<endl;    
}


int main() {
//    vector<int> pages;
//    vector<int> order;
//    vector<int> page_sequence = {1, 2, 3, 4 , 2 , 1 , 5 , 6, 2 , 1};
   vector<int> pages;
    vector<int> order;
    int frames;
    int faults = 0;

    cout << "Enter the number of frames in the memory: ";
    cin >> frames;
    cout << endl;

    int page_sequence_size;
    cout << "Enter the size of the page sequence: ";
    cin >> page_sequence_size;
    cout << "Enter the page sequence: ";
    vector<int> page_sequence(page_sequence_size);
    for (int i = 0; i < page_sequence_size; i++) {
        cin >> page_sequence[i];
    }

    for (int page : page_sequence) {
        accessPages(pages, page, frames, faults, order);
    }

    // Print the current memory

    // Number of page faults
    cout << endl;
    cout << "Number of page faults: " << faults << endl;

    return 0;
}