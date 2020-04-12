#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <cmath>
#include <ctime>
#define SIZE sizeof (int)*8

using namespace std;

double **FillMatrica (int n)//������ ��������� ������� �
{
	double **mA;
	mA= new double *[n];
	new int [n];
		for (int i=0; i<n; i++)
			mA[i]=new double[n];
	for (int i=0; i<n; i++)
    	{
		for (int j=0; j<n; j++)
    		{
				mA[i][j]= rand()%20;
        	}
        }
	return mA;
}
double **FillMatricaB (int n)//�� ����� �������� ������ ������� �
	{
	double **mA;
	mA = new double *[n];
		for (int i=0; i<n; i++)
			mA[i]=new double[n];
	for (int i=0; i<n; i++)
    	{
		for (int j=0; j<n; j++)
    		{
        		mA[i][j] = 1.0/(i+j+1.0);
        	}
        }
	return mA;
}

double **MultiplyMatrica (int n, double**c, double **z)//������ ������� �������
	{
	double **mA;
	mA = new double *[n];
		for (int i=0; i<n; i++)
			mA[i]=new double[n];
	for(int i = 0; i < n; i++)
    		for(int j = 0; j < n; j++){
      			mA[i][j] = 0;
      			for(int k = 0; k < n; k++)
       			 mA[i][j] += z[i][k]*c[k][j];}
	return mA;
}



int main()
{	
	
	int number=500;
	double **z =FillMatrica(number);


	double **c=FillMatricaB(number);


	double **q = MultiplyMatrica(number,c,z);


}
