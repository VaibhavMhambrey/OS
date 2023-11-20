#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;
int m, n, flag;

int allocation[10][10], maximum[10][10], need[10][10];
int available[10];

void safety()
{
	int safe[n], work[m];
	bool finish[n];
    for(int i=0;i<n;i++)
    {
    	safe[i]=-1;
    	finish[i]=false;
	}
	for(int i=0; i<m; i++)
		work[i] = available[i];

	int k=0, loop_flag;
	do
	{
		loop_flag=0;
		for(int i=0; i<n; i++)
		{
	   		flag=0;
	   		for(int j=0; j<m; j++)
	   		{
	   			if(finish[i]==false && need[i][j]<=work[j])
	   				continue;
	   			else
	   				flag=1;
			}

			if(flag==0)
			{
				finish[i] = true;
				for(int j=0; j<m; j++)
					work[j] = work[j] + allocation[i][j];

	    		safe[k]=i;
		   		k++;
		   		loop_flag=1;
			}
		}
		flag=0;
		for(int i=0; i<n; i++)
		{
			if(finish[i]==false)
				flag=1;
		}
		if(flag==0)
			break;
		if(loop_flag==0)
			break;
	}while(true);

	if(flag==0)
	{
		cout<<endl<<"Safe Sequence:  ";
		for(int j=0; j<n; j++){
			if(j==n-1){
				cout<<safe[j];
			}
			else{
				cout<<safe[j]<<" ..... ";
			}
		}
		    
	}
	else
		cout<<endl<< "Safe sequence doesnt exists";
	cout<<endl;
}

void display()
{
    cout<<endl<<"Allocation \t Maximum \t Need \t Available"<<endl;
    for(int i=0;i<n;i++)
    {
    	cout<<setiosflags(ios::right)<<" ";
		for(int j=0;j<m;j++)
			cout<<allocation[i][j]<<" ";

		cout<<setw(11);
		for(int j=0;j<m;j++)
			cout<<maximum[i][j]<<" ";

		cout<<setw(8);
		for(int j=0;j<m;j++)
			cout<<need[i][j]<<" ";
			
		if(i==0)
		{
			cout<<setw(6);
			for(int j=0;j<m;j++)
			{
				cout<<available[j]<<" ";
			}
		}
		
		cout<<endl;
    }
}

int main()
{
	//-----------------------Input----------------------------------------
    cout<<"Enter the number of Processes: ";
    cin>>n;

    cout<<"Enter the number of Resource types: ";
    cin>>m;

    cout<<"Enter Allocated Resources for each process:"<<endl;
    for(int i=0;i<n;i++)
    {
    	cout<<"P"<<i<<": ";
		for(int j=0;j<m;j++)
    		cin>>allocation[i][j];
    }

    cout<<endl<<"Enter maximum Resources for each process:"<<endl;
    for(int i=0;i<n;i++)
    {
    	cout<<"P"<<i<<": ";
		for(int j=0;j<m;j++)
	        cin>>maximum[i][j];
    }

    cout<<endl<<"Enter Available Resources:"<<endl;
    for(int i=0;i<m;i++)
    	cin>>available[i];
	//------------------------------------------------------

    for(int i=0;i<n;i++)
    {
		for(int j=0;j<m;j++)
    		need[i][j] = maximum[i][j] - allocation[i][j];
    }

	display();
	
	safety();

	char ans='y';

	do{	
		int request[m], p;
		cout<<endl<<"Enter Process Number: ";
		cin>>p;
	
		cout<<"Enter Request: ";
		for(int i=0; i<m; i++)
			cin>>request[i];
			
		for(int i=0; i<m; i++)
		{
			if(need[p][i]<request[i])
			{
				cout<<endl<<"Process exceeded maximum claim for resorces.\nRequest Cannot be granted."<<endl;
				goto end;
			}
			if(available[i]<request[i])
			{
				cout<<endl<<"Process must wait.Resorces not available."<<endl;
				goto end;
			}
		}
	
	    for(int i=0; i<m; i++)
	    {
	    	available[i] -= request[i];
	    	allocation[p][i] += request[i];
	    	need[p][i] -= request[i];
		}
	
		cout<<endl<<endl;
		display();

		safety();
	
		if(flag==1)
		{
			cout<<"Request cannot be granted."<<endl;
			for(int i=0; i<m; i++)
			{
				available[i] += request[i];
		    	allocation[p][i] -= request[i];
		    	need[p][i] += request[i];
			}
			cout<<endl<<"States Reverted:"<<endl;
			display();
		}
		else
		{
			cout<<endl<<"Safe Sequence Exists and request can be granted immediately to process.\nSnapshot after request:"<<endl;
			display();
		}
		end:
		cout<<endl<<"Try another Process?(Y/N)  ";
		cin>>ans;
	}while(ans=='y' || ans=='Y');
}