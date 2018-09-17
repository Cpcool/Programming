// Solution uses Recursive approach with bitmasking to track the path of the optimal solution

#include<iostream>
#include<stdio.h>
using namespace std;

double bestVal = 0;  
int bestStatus = 0;   
 
double max(double a, double b) { return (a > b)? a : b; } 
  
double Bitflyer(long int Max_size, long int size[], double fee[], int n,double totVal = 0, int status = 0) 
{ 
		  if (totVal > bestVal)
		  {
	         	bestStatus = status;
		        bestVal = totVal;
		  }
		
   if (n == 0 || Max_size <= 0) 
       return 0; 
   if (size[n-1] > Max_size) 
       return Bitflyer(Max_size, size, fee, n-1,totVal,status); 

   else return max((fee[n-1] + Bitflyer(Max_size-size[n-1], size, fee, n-1,totVal + fee[n-1], status |(1<<(n-1)))),
   	Bitflyer(Max_size, size, fee, n-1,totVal, status)); 	
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





