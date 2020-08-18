/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<math.h>

int main()
{
    int n=0;
    double x=1, y=1, sum=0, tot_x=0,tot_y=0,sum_xi=0, sum_yi=0, mean_x=0, mean_y=0, result=0;
    double a=0, b=0; ///for regression analysis
    scanf("%lf%lf", &x, &y);
    while(x!=0) /// here 0,0 is the stop code. to terminate input loop input 0 0 
    {
        n++;
        sum+= (x*y);
        sum_xi+= (x*x);
        sum_yi+= (y*y);
        tot_x+= x;
        tot_y+= y;
        
        scanf("%lf%lf", &x, &y);
    }
    
    mean_x = tot_x/n;
    mean_y = tot_y/n;
    
    printf("sum : %lf\n", sum);
    printf("sum_ xi: %lf\n", sum_xi);
    printf("sum_yi: %lf\n", sum_yi);
    printf("mean x=%lf     y=%lf\n", mean_x, mean_y);
    result = (sum - n*mean_x*mean_y) / (sqrt(sum_xi-n*pow(mean_x,2))*sqrt(sum_yi-n*pow(mean_y,2)));
    
    a = (tot_y*sum_xi - tot_x*sum) / (n*sum_xi - pow(tot_x,2));
    b = (n*sum - tot_x*tot_y) / (n*sum_xi - pow(tot_x,2));
    
    printf("\ncorrelation coefficient is %lf\n", result);
    printf("regression equation: %lf + %lfx\n", a,b);

    return 0;
}

