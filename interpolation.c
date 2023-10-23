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
printf("%.0f  ", A[i][j]); 
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
  printf("x1 = %f\nx2 = %f\nx3 = %f \nX4 = %f\n", X[0], X[1], X[2], X[3]);//solução do sistema
printf("\n%.4fx^%d +  %.4fx^%d + %.4fx + %.4f \n", X[0],n-1,  X[1],n-2,  X[2], X[3]); //gera o polinômio interpolador
	return 0; 	
}


//teste
int main( ){

double pontos[4][2] = {{-1, 0}, {0, 1}, { 3, -1}, {4, 0} }; 
double X[4]; 
double Y[4]; 
interpolation(4, pontos,  X, Y); 


	return 0; 
}
