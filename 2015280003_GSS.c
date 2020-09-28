#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#define N 100
#define r 0.618

int polinomDerece;
double epsilon;
double degiskenKatsayilari[N];
double aralik1,aralik2;


double f(double x)
{
	double sum=0;
	int i;
		for(i=0;i<polinomDerece;i++)
		{
			//double temp=degiskenKatsayilari[i]*(x);  
			//sum+=pow(temp,(polinomDerece-i));
			
			double temp=pow(x,(polinomDerece-i));
			sum+=degiskenKatsayilari[i]*temp;		   
		}
		
	return sum;
}

void goldenSectionSearch(double aralik1,double aralik2,double epsilon)
{
	FILE *fpp;
	fpp=fopen("output.txt","w");
	double c=0;
	double d;
	int i;
	int k=0;
	fprintf(fpp,"%.3f %.3f\n",aralik1,aralik2);
	do{
		c=aralik2-r*(aralik2-aralik1);
		d=aralik1+r*(aralik2-aralik1);
		printf("d = %lf \n ",d);
		printf("c = %lf \n",c);
		if(f(c)>f(d)) aralik1=c;
		else aralik2=d;
		k++;
		printf("aralik1= %.3f  aralik2=%.3f\n",aralik1,aralik2);
		fprintf(fpp,"%.3f %.3f \n",aralik1,aralik2);
	}while(aralik2-aralik1>epsilon);
}

void dosyaOku()
{
	FILE *fp;
	fp= fopen("input.txt","r");
	fscanf(fp,"%d",&polinomDerece);
	int i;
	for(i=0;i<polinomDerece;i++)
	{
		fscanf(fp,"%lf",&degiskenKatsayilari[i]);
	}
	fscanf(fp,"%lf%lf%lf",&epsilon,&aralik1,&aralik2);
	fclose(fp);
}

main()
{
	dosyaOku();
	goldenSectionSearch(aralik1,aralik2,epsilon);
}
