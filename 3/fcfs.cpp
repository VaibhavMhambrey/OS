#include<bits/stdc++.h>

using namespace std;

class sjf{
   
    public:
    int process;
    int burst_time;
    int waiting_time;
    int arrival_time;
    int turnaround_time;
        void getdata(int n);
       
        // void gantchart();
        void print_wait();
        void print_tat();
        sjf(){}
        
         
};

void sort(int n,sjf p[]){
     for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if((p[j].arrival_time)>=(p[j+1].arrival_time)){
                int temp;
                temp=p[j].burst_time;
                p[j].burst_time=p[j+1].burst_time;
                p[j+1].burst_time=temp;
                
                temp =  p[j].arrival_time ;
                p[j].arrival_time=p[j+1].arrival_time;
                p[j+1].arrival_time=temp;

                temp=p[j].process;
                p[j].process=p[j+1].process;
                p[j+1].process=temp;
            
            }
        }
     }
}
    
void sjf::print_wait(){
        cout<<"p"<<process<<" "<<waiting_time<<endl;
    
    
}

void sjf::getdata(int n){
    cout<<"enter burst time of"<<" "<<process<<" ";
    cin>>burst_time;
    cout<<"\n enter arrival time of"<<" "<<process<<" ";
    cin>>arrival_time;
}

void sjf::print_tat(){
    cout<<"p"<<process<<" "<<turnaround_time<<endl;
}

// void calculate(int n,sjf process[]){
//     process[0].waiting_time=0;
//     process[0].turnaround_time = process[0].waiting_time + process[0].burst_time;
//     for (int i = 1; i < n; i++)
//     {
//         process[i].waiting_time= process[i-1].waiting_time + process[i-1].burst_time;
//         process[i].turnaround_time = process[i].waiting_time + process[i].burst_time;
//     }
    
// }

void calculate_tat(int n,sjf p[]){
    int completion_time= p[0].arrival_time;
    for (int i = 0; i < n; i++)
    {
        completion_time+=p[i].burst_time;
        // c1.push_back(completion_time);
        p[i].turnaround_time = completion_time - p[i].arrival_time;
    }
    
}

void calculate_wt(int n,sjf p[]){
    for (int i = 0; i < n; i++)
    {
        p[i].waiting_time= p[i].turnaround_time - p[i].burst_time;
    }
    
}

void gchart(int n ,sjf process[]){
    cout<<"\nGantt Chart:"<<endl;
    int current_time = process[0].arrival_time;
    int size=5;
    for (int i = 0; i < n; i++)
    {
        cout<<'p'<<process[i].process<<setw(size);
    }
    cout<<"\n";

     for (int i = 0; i < n; i++)
    {
        cout<<current_time<<setw(size);
        current_time+= process[i].burst_time;

        if(i == n-1){
            cout<<current_time;
        }
    }
    
    cout<<"\n";
}

void calculate_avg(int n, sjf process[],float &avg1,float &avg2){
	//calulate the average
	avg1=0;
	avg2=0;
	for(int i=0;i<n;i++){
		avg1+= process[i].waiting_time;
		avg2+=process[i].turnaround_time;
	}
	
	cout<<"Average waiting time is: "<<(avg1)/n<<"\n \n";
	cout<<"Average turnaround time is: "<<(avg2)/n<<"\n \n";
}

int main(){
    int n;
	float avg_wt,avg_tat;
    cout<<"enter no of processes"<<endl;
    cin>>n;
    sjf process[n];
    for (int i = 0; i < n; i++)
    {
        process[i].process = i+1;
        process[i].getdata(n);
    }

    //sort the array based on the burst_time

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<process[i].process<<" "<<process[i].burst_time<<endl;
    // }
    
    sort(n,process);

    calculate_tat(n,process);
    calculate_wt(n,process);
    
    cout<<"waiting time of porcesses are: "<<endl;
    for (int i = 0; i < n; i++)
    {
        process[i].print_wait();
    }
    cout<<"\n";

    cout<<"Turn around times: "<<endl;

    for (int i = 0; i < n; i++)
    {
        process[i].print_tat();
    }
	cout<<"\n\n";
	
	calculate_avg(n,process,avg_wt,avg_tat);
    //dispaly gannt chart 
    gchart(n,process);



   
    


}
