#include "stdio.h"
#include "stdlib.h"
#include "gaussSolver.c" 
#include "math.h"

int interpolation(int n , float  pontos[n][2],  float  X[n],  float Y[n], int m){
int i, j; 
float A[m][m]; 
int grupo = n/m;
for(i = 0; i<m; i++){
	float valorX = 0;
	float valorY = 0;
	for(j= 0; j < grupo; j++){
		valorX += pontos[(i*grupo)+j][0]; // x do ponto i
		valorY += pontos[(i*grupo)+j][1]; //y do ponto i
	}
	pontos[i][0] = valorX / grupo;
	pontos[i][1] = valorY / grupo;
}
n = m;

//Geração da matriz quadrada A. 
for (i = 0; i < n ; i++) {
	for (j = 0; j < n ; j ++) {
A[i][j] = pow(pontos[i][0], n- j - 1); 
printf("%.0f  ", A[i][j]);                                //= print da matriz quadrada
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
	printf("X%d = %Lf\n",i,X[i]);
	 //printf("x1 = %f\nx2 = %f\nx3 = %f \nX4 = %f\n", X[0], X[1], X[2], X[3]);//solução do sistema
	 
}
printf("\n");
for(i = 0; i<n;i++){
	
	 printf("%.4llfx^%d +",X[i],n-i);
//	printf("\n%.4fx^%d +  %.4fx^%d + %.4fx + %.4f \n", X[0],n-1,  X[1],n-2,  X[2], X[3]); //gera o polinômio interpolador
	
}
printf("\n");
 
	return 0; 	
}


//teste
int main( ){
int n = 1000;
float pontos[n][2]; 
int i= 0;
int j=0;
for (i= 0; i<n; i++){
	for(j=0; j<2; j++){
		pontos[i][j] = i;
	}
}

//float pontos[4][2] = {{0, 0}, {0.52359877559, 0.5}, { 0.78539816339, 0.70710678118}, {1.57079632679, 1} }; 

float X[n]; 
float Y[n]; 
interpolation(n, pontos,  X, Y, 8); 


	return 0; 
}
