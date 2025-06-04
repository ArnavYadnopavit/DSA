#include<stdio.h>
double TaylorOn(double x,int n){
	static double s=1;
	if (n==0){
		return s;
	}
	s=1+x/n*s;
	return TaylorOn(x,n-1); //e^x=1+x(1+x/2(1+x/3(1+x/4(...))))

}
int main()
{
 printf("%lf \n",TaylorOn(1,50));
 return 0;
}
