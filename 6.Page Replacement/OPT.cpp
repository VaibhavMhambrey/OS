
#include <bits/stdc++.h>
using namespace std;

int var = 0;
// Function to check whether a page exists
// in a frame or not
bool search(int key, vector<int>& fr)
{
	for (int i = 0; i < fr.size(); i++)
		if (fr[i] == key)
			return true;
	return false;
}


int predict(int pg[], vector<int>& fr, int pn, int index)
{
	// Store the index of pages which are going
	// to be used recently in future
	int res = -1, farthest = index;
	for (int i = 0; i < fr.size(); i++) {
		int j;
		for (j = index; j < pn; j++) {
			if (fr[i] == pg[j]) {
				if (j > farthest) {
					farthest = j;
					res = i;
				}
				break;
			}
		}

		// If a page is never referenced in future,
		// return it.
		if (j == pn)
			return i;
	}

	// If all of the frames were not in future,
	// return any of them, we return 0. Otherwise
	// we return res.
	return (res == -1) ? 0 : res;
}

void optimalPage(int pg[], int pn, int fn)
{
	// Create an array for given number of
	// frames and initialize it as empty.
	vector<int> fr;

	// Traverse through page reference array
	// and check for miss and hit.
	int hit = 0;
	for (int i = 0; i < pn; i++) {

		// Page found in a frame : HIT
		if (search(pg[i], fr)) {
			hit++;
			continue;
		}

		// Page not found in a frame : MISS

		// If there is space available in frames.
		if (fr.size() < fn)
			fr.push_back(pg[i]);

		// Find the page to be replaced.
		else {
			int j = predict(pg, fr, pn, i + 1);
			fr[j] = pg[i];
		}
		
		//print 
		var++;
		cout<<"Iteration"<<var<<":";
		for(int i = 0; i<fr.size();i++){
			cout<<fr[i]<<" ";
		}
		cout<<endl;
	}

	cout << "Page faults = " << pn - hit << endl;
}

// Driver Function
int main()
{
	int pages;
	int fn;
	cout<<"enter the number of frames in the memory"<<" : ";
	cin>>fn;
	cout<<endl;
	cout<<"enter the number of pages"<<": ";
	cin>>pages;
	cout<<endl;
//	int pg[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
	int pg[pages];
	cout<<"enter the refrence string of page accesses"<<endl;
	for(int i =0;i<pages;i++)
		cin>>pg[i];
	cout<<endl;
	
	
	
	optimalPage(pg, pages, fn);
	return 0;
}

// This code is contributed by Karandeep Singh

