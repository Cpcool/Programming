// Solution uses bitmasking 
#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

long bestStatus=0;
  
double Bitflyer(long int Max_size, long int size[], double fee[], int n) 
{
		double Max_fee=0,sum;
		long int size_limit=0;
 
		 for(long int i=1;i<=pow(2,n);i++)
		 {
			long int temp=i;
			sum=0,size_limit=0;

			for(int j=0;j<n;j++)
			{
				if(temp&1)
				{
					sum+=fee[j];
					size_limit+=size[j];				
				}
				temp>>=1;
			}
			
			if(sum>Max_fee && size_limit<=Max_size)
			{
				Max_fee=sum;	
				bestStatus=i;					
			}
		 } 	

		 return Max_fee;
} 

int main() 
{ 
    int n = 12;
    long int  Max_size = 1000000;
    long int total_size=0;

    double fee[] = {0.0887,0.1856,0.2307,0.1522,0.0532,0.0250,0.1409,0.2541,0.1147,0.2660,0.2933,0.0686}; 
    long int size[] ={57247, 98732,134928,77275,29240,15440,70820,139603,63718,143807,190457,40572}; 
     
    double price = 12.50 + Bitflyer(Max_size, size, fee, n); 
    
    cout<<"*******************************"<<endl;
    cout<<"Block size         "<<" BTC    "<<endl;
    cout<<"*******************************"<<endl;    

    int count=0;
   
    while (bestStatus){
    	if(bestStatus&1){
	printf("%5ld",size[count]);
	cout<<"          ";
	printf("%5lf\n",fee[count]);
	total_size+=size[count];
	}
    	count++;
    	bestStatus>>=1;
	}
    
        cout<<"*******************************"<<endl;	
	cout<<"Maximum price is "<<price<<endl;
        cout<<"Total  Size   is "<<total_size<<endl;
        cout<<"*******************************"<<endl;
	return 0;
} 
