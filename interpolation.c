#include "stdio.h"
#include "stdlib.h"
#include "gaussSolver.c" 
#include "math.h"

int interpolation(int n , double  pontos[n][2], double  X[n], double Y[n]){
int i, j; 
double A[n][n]; 

//Geração da matriz quadrada A. 
for (i = 0; i < n ; i++) {
	for (j = 0; j < n ; j ++) {
A[i][j] = pow(pontos[i][0], n- j - 1); 
//printf("%.0f  ", A[i][j]);                                = print da matriz quadrada
		}
		printf("\n"); 
	}
printf("\n Y = {"); 
for (i = 0; i < n ; i++){
Y[i] = pontos[i][1]; 

printf(" %.0f  ", Y[i]);
}
printf("}\n"); 

gaussSolver( n, A, Y, X); 

for(i = 0; i<n;i++){
	printf("X%d = %f\n",i,X[i]);
	 //printf("x1 = %f\nx2 = %f\nx3 = %f \nX4 = %f\n", X[0], X[1], X[2], X[3]);//solução do sistema
	 
}
printf("\n");
for(i = 0; i<n;i++){
	
	 printf("%.4fx^%d +",X[i],n-i);
//	printf("\n%.4fx^%d +  %.4fx^%d + %.4fx + %.4f \n", X[0],n-1,  X[1],n-2,  X[2], X[3]); //gera o polinômio interpolador
	
}
printf("\n");
 
	return 0; 	
}


//teste
int main( ){
int n = 20;
double pontos[n][2]; 
int i= 0;
int j=0;
for (i= 0; i<n; i++){
	for(j=0; j<2; j++){
		pontos[i][j] = i;
	}
}

//double pontos[4][2] = {{0, 0}, {0.52359877559, 0.5}, { 0.78539816339, 0.70710678118}, {1.57079632679, 1} }; 

double X[n]; 
double Y[n]; 
interpolation(n, pontos,  X, Y); 


	return 0; 
}
