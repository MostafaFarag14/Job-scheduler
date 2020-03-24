#include<iostream>
using namespace std;

class process
{
	public :
		int order ;
		int arr_time ;
		int burst_time ;
		int b ;
		int priority ;
		int finish_time ;
		bool status ;
};

process P[10]; 
int type ;
int type2 ;



void swap(process &a , process &b)
{
	process temp ;
	temp=a ;
	a=b;
	b=temp;
}

void sort_arrival (int &n)
{
	for(int i=0;i<n-1;i++)
		{
			int min=P[i].arr_time;
			for(int j=i+1;j<n;j++)
			{
				if(P[j].arr_time<min)
				{
					min=P[j].arr_time ;
					swap(P[i],P[j]) ;
				}
			}
		}
}

void sort_burst(int &n)
{
	for(int i=0;i<n-1;i++)
		{
			int min=P[i].burst_time;
			for(int j=i+1;j<n;j++)
			{
				if(P[j].burst_time<min)
				{
					min=P[j].burst_time;
					swap(P[i],P[j]) ;
				}
			}
		}
}

void sort_priority(int &n)
{
	for(int i=0;i<n-1;i++)
		{
			int min=P[i].priority;
			for(int j=i+1;j<n;j++)
			{
				if(P[j].priority<min)
				{
					min=P[j].priority;
					swap(P[i],P[j]) ;
				}
			}
		}
}

void Non_preemptive(int &n)
{
	int t=0 ; int m=0 ; int k=0;
			while(m!=n)
			{
				for(int i=0;i<n;i++)
				{
				
					k=m;
					if(P[i].arr_time<=t && P[i].status==0)
					{
						cout<<"|"<<t<<"|" ;
						for(int j=0;j<P[i].burst_time-1;j++) cout<<"-" ;

									cout<<"P"<<P[i].order ;
							for(int j=0;j<P[i].burst_time-1;j++) cout<<"-" ;
					
					P[i].status=1 ;
						m++ ;
						t=t+P[i].burst_time ;
						P[i].finish_time=t;
						i=-1;
					}

					if(k==m&&i==n-1)
						{
							t++;
						}
				}

			}
			cout<<"|"<<t-1<<"|"<<"\n" ;
}

void Preemptive(int &n)
{
	{
						int t=0 ; int m=0 ;int k=0;
			while(m!=n)
			{
				escape :
				for(int i=0;i<n;i++)
				{
					k=m;
					if(P[i].arr_time<=t && P[i].status==0)
					{
						cout<<"|"<<t<<"|"<<"P"<<P[i].order ;
					
					for(int j=0;j<P[i].burst_time;)
					{
						cout<<"--" ;	t++ ;	P[i].burst_time-- ;
							if(P[i].burst_time==0)
							{	
								P[i].status=1 ; m++ ;
								P[i].finish_time=t;
								goto escape ;
							}
							for(int k=0;k<n;k++)
							{
								if(type==1)
								{
									if(P[k].arr_time==t && P[k].burst_time<P[i].burst_time)
									{
										sort_burst(n);
										goto escape ;
									}
								}
								else if (type==2)
								{
									if(P[k].arr_time==t && P[k].priority<P[i].priority)
									goto escape ;
								}
							}
					}
					}
					if(k==m&&i==n-1)
						{
							t++;
						}
				}
			}
			cout<<"|"<<t-1<<"|"<<"\n" ;
				}
}

void Avg_W_T(int &n)
{
    float avg_w_t=0 ;
            for(int i=0;i<n;i++)
            {
                avg_w_t=avg_w_t+(P[i].finish_time - P[i].arr_time -	P[i].b ) ;
            }
            cout<<"Average Waiting Time ="<<avg_w_t/n<<"\n" ; 
}

int main()
{
	bool reset=1 ;
	while(reset)
	{
	int n ;
	int Q;
	cout<<"Enter type of schedular :\n\n0 for FCFS\n1 for SJF\n2 for Priroity\n3 for RoundRobin\n\n" ;
	cin>>type ;
	cout<<"\n" ;
	cout<<"Enter number of processes :\n\n" ;
		cin>>n ;
		cout<<"\n" ;
		cout<<"Enter arrive time of each process respectively : \n\n" ;
		for(int i=0;i<n;i++)
		{
			cin>>P[i].arr_time ;
			P[i].order=i ;
			P[i].status=0;
		}
		cout<<"\n" ;
		cout<<"Enter burst time of each process respectively : \n\n" ;
		for(int i=0;i<n;i++)
		{
			cin>>P[i].burst_time ;
			P[i].b=P[i].burst_time ;
		}
		cout<<"\n" ;
		if(type==2 | type==1)
		{	
			if(type==2)
			{
			cout<<"Enter priority of each process respectively :\n\n" ;
				for(int i=0;i<n;i++)
				{
					cin>>P[i].priority ;
				}
			}
			cout<<"press 0 for Non preemptive or 1 for Preemptive :\n\n" ;
			cin>>type2 ;
			
		}
		cout<<"\n" ;
		if(type==3)
			{
				cout<<"Enter Quantam\n\n";
				cin>>Q;
			}

		// FCFS
		if(type==0)
			{
		sort_arrival(n) ;
		
		//execute
			int t=0 ,i ,j ;
			cout<<" " ;

			for( i=0;i<n;i++)
			{
				for( j=0;j<P[i].burst_time;j++) cout<<"--" ;
				cout<<" ";
			}

			cout<<"\n|" ;

			for(i=0; i<n; i++) 
			{
				for(j=0; j<P[i].burst_time - 1; j++) printf(" ");
				cout<<"P"<<P[i].order ;
				 for(j=0; j<P[i].burst_time - 1; j++) printf(" ");
				cout<<"|";
			 }

			cout<<"\n " ;
			for(i=0; i<n; i++) 
			{
				for(j=0; j<P[i].burst_time; j++) printf("--");
				cout<<" ";
			 }

			cout<<"\n" ;
			cout<<t ;

			for(i=0; i<n; i++) 
			{
			for(j=0; j<P[i].burst_time; j++) printf("  ");
			
					t=t+P[i].burst_time ;
					P[i].finish_time = t ;
					if(t>9) cout<<"\b" ;
					cout<<t ;
			}
			cout<<"\n\n" ;
           Avg_W_T (n);            //average waiting time
		}

		// sjf
		if(type==1)
			{
				
		sort_burst(n);

		//execute
		if(type2==0)
				{
					Non_preemptive(n) ;
					cout<<"\n" ;
					 Avg_W_T (n);            //average waiting time
				}
				else if (type2==1)
				{
					Preemptive(n) ;
					cout<<"\n" ;
					Avg_W_T (n);            //average waiting time
				}
		}

		//RR

		if(type==3)
		{
				sort_arrival(n) ;
				//execute
				int i , j ; int t=P[0].arr_time ; ; int m=0 ;  int q=Q ;

				while(m!=n)
			{
				for(int i=0;i<n;i++)
				{
					if(P[i].status==0 && P[i].burst_time==0)
					{
						P[i].status=1 ; m++ ;
					}

					if(P[i].status==0)
					{
						
					cout<<"|"<<t<<"|" ; 
					if(P[i].burst_time<Q)
						{
							 q=Q ;
							Q=P[i].burst_time ;
						}
					for(j=0; j<Q - 1; j++) printf("-");
					cout<<"P"<<P[i].order ;
					for(j=0; j<Q - 1; j++) printf("-");
					
			
					t=t+Q ;
					P[i].burst_time = P[i].burst_time-Q;
					if(P[i].burst_time<0) P[i].burst_time=0 ;
					
					if(P[i].burst_time==0)
					{
						P[i].finish_time=t;
						P[i].status=1 ;
						m++;
					}
					}
					Q=q ;
				}
			}
			cout<<"|"<<t<<"|"<<"\n" ;

			
			cout<<"\n\n" ;

			 Avg_W_T (n);            //average waiting time
		}

		// priority

		if(type==2)
			{
		
			sort_priority(n);
		//execute
		if(type2==0)	
			{
			Non_preemptive(n) ;
			cout<<"\n" ;
			Avg_W_T (n);            //average waiting time
			}
		else if(type2==1)
			{
			Preemptive(n) ;
			cout<<"\n" ;
			Avg_W_T (n);            //average waiting time
			}
		}
		//exit
		//for (int i=0;i<n;i++) cout<<P[i].finish_time<<"\t"<<P[i].arr_time<<"\t"<<P[i].b<<"\n" ;
		reset=0;
		cout<<"\nto restart press 1 or 0 to terminate\n\n";
			cin>>reset ;
		}
    return 0 ;
}
