 #include <stdio.h>
 #include <math.h>
 #define EPS 1.0e-6 
 
 double f(double x){
 	return (x*x*x-x-1); 
 } 
 
 double bisolver(double a,double b){
 	double m;
 	while(1){
 		m=(a+b)/2;
 		if(fabs(f(m))<EPS) break;
 		 if(f(m)*f(a)<0) b=m;
		 	else if (f(m)*f(a)>0) a=m; 		
	 }
 	return (a+b)/2;
 }
 
 int main(){
 	double a,b;
	printf("Please input the segment which contains a root of the equation:\n");
	
	while(1){
		scanf("%lf",&a);
	    scanf("%lf",&b);	
	    if(f(a)*f(b)>0) printf("This segment doesn't contain a root.\n");
	    else break;
		
		
		
	}

	 

 	
 	printf ("The root found within this segment is %f.",bisolver(a,b));
 	
 	
 	
 	
 	
 	
 	
 	
 	return 0; 
 }
