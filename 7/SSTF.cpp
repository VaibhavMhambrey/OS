#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int sstf(vector<int> &requests, int current_head) {
    int total_seek_time = 0;
    int head=current_head;
    vector<int> seekSequence;
    while (!requests.empty()) {
        int min_seek = INT_MAX;
        int min_index = -1;

        for (int i = 0; i < requests.size(); i++) {
            int seek = abs(current_head - requests[i]);
            if (seek < min_seek) {
                min_seek = seek;
                min_index = i;
                
            }
        }
        seekSequence.push_back(requests[min_index]);
        total_seek_time += min_seek;
        current_head = requests[min_index];
        requests.erase(requests.begin() + min_index);
    }
    //prints the seek sequence
    cout<<"seek sequenece is: "<<head<<"-->";
    for(int i=0;i<seekSequence.size();i++){
    	cout<<seekSequence[i]<<"-->";
    	if(i==seekSequence.size()-1){
    		cout<<seekSequence[i];
		}
	}
	cout<<endl;

    return total_seek_time;
}

int main() {
//    vector <int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
//    int current_head = 53;
int qsize,current_head;
		cout <<"enter the queue size:";
		cin>>qsize;
		vector<int> requests;
		requests.resize(qsize);
		cout<<"enter the values of request queue"<<endl;
		for(int i =0;i<qsize;i++){
			cin>>requests[i];
		}
		cout<<"enter the current pos of head"<<endl;
		cin>>current_head;
    int seek_time = sstf(requests, current_head);

    cout << "Total seek time: " << seek_time << endl;

    return 0;
}

