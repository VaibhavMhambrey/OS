#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For formatting output

using namespace std;

void accessPages(vector<int> &page, int page_number, int max_size, int &faults,vector<int> &order) {
    auto it = find(page.begin(), page.end(), page_number);

    if (it == page.end()) {
        faults++; // If the page is not present in the page vector, then there is a fault, so increment it

        if (page.size() >= max_size) {
            auto it = find(order.begin(),order.end(),page[0]);
            *it = page_number;
            page.erase(page.begin());
        }
        if(page.size()<max_size){
            order.push_back(page_number);
        }
        page.push_back(page_number);
        
    }

    cout << "Current Memory: ";
    for (int i = 0; i < max_size; i++) {
        if (i < order.size()) {
            cout << setw(2) << order[i] << " "; // Format the output
        } else {
            cout << "   "; // Empty space to maintain the same width
        }
    }
    cout << endl;
}

int main() {
//    vector<int> pages;
//    vector<int> page_sequence = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
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

    // Number of page faults
    cout << endl;
    cout << "Number of page faults: " << faults << endl;

    return 0;
}

