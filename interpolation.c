#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int gaussSolver(int n, float A[n][n], float b[n], float X[n]) {
    int i, j, k, l, m;
    
    
    
    
    
    //ETAPA DE ESCALONAMENTO
    
    for (k = 0; k < n - 1; k++) {
        float max = fabs(A[k][k]);
        int maxIndex = k;
        //procura o maior k-esimo coeficiente em modulo
        for (i = k + 1; i < n; i++) {
            if (max < fabs(A[i][k])) {
                max = fabs(A[i][k]);
                maxIndex = i;
            }
        }
        if (maxIndex != k) {
            /*
             troca a equacao k pela equacao com o
             maior k-esimo coeficiente em modulo
             */
            for (j = 0; j < n; j++) {
                float temp = A[k][j];
                A[k][j] = A[maxIndex][j];
                A[maxIndex][j] = temp;
            }
            float temp = b[k];
            b[k] = b[maxIndex];
            b[maxIndex] = temp;
        }
        //Se A[k][k] for zero, entao a matriz dos coeficiente nao tem resolucao
        //det A = 0
        if (A[k][k] == 0) {
            //A matriz dos coeficientes nao tem resolucao
            return 0 ;
        } else {
            //realiza o escalonamento
            	
            for (m = k + 1; m < n; m++) { 
                float F = -A[m][k] / A[k][k];
                A[m][k] = 0; //evita uma iteracao
                b[m] = b[m] + F * b[k];
                for (l = k + 1; l < n; l++) {
                    A[m][l] = A[m][l] + F * A[k][l];
                }
                
                
	
                
            }
        }
    }
    
 	


    //ETAPA DE RESOLUCAO DO SISTEMA   
   
    for (i = n - 1; i >= 0; i--) {
    	X[i] = b[i]; // salvando valores de Y (b[i]) em X[i]    	
        //substituicoes retroativas à partir da segunda equacao
        for (j = i + 1; j < n; j++) {
            X[i] = X[i] - X[j] * A[i][j];            
        }
        X[i] = X[i] / A[i][i];
       
    }
     
    
    
   }
   
int interpolation(int n , float  pontos[n][2],  float  X[n],  float Y[n], int m){
int i, j; 
float A[m][m]; 
int grupo = n/m; // grupo é a quantidade de pontos que vai ser agrupada para gerar o polinomio interpolador 


// for para definir os novos valores dos "m" pontos
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

//Geracao da matriz quadrada A. 
for (i = 0; i < n ; i++) {
	for (j = 0; j < n ; j ++) {
A[i][j] = pow(pontos[i][0], n- j - 1);                                
		}
	 
	}
 
for (i = 0; i < n ; i++){
Y[i] = pontos[i][1]; 
X[i] = pontos[i][0];
}





gaussSolver( n, A, Y, X); 
 
	return 0; 	
}



int main( ){
int n,m,i,j;


FILE *file;
file = fopen("entrada.txt", "r");


if(file == NULL){
	return 0;
}

fscanf(file, "%d %d", &n, &m); // n- quantidade total de pontos / m - grau + 1 do polinomio interpolador (grau 3 => m = 4)
float pontos[n][2]; // matriz dos pontos [x][y]





for(i = 0; i<n; i++){	
	fscanf(file,"%f",&pontos[i][0]); // salva os x	
}
for(i = 0; i<n; i++){
	fscanf(file,"%f",&pontos[i][1]); // salva os y
}





float X[n]; // vetores de X e Ys 
float Y[n]; 



interpolation(n, pontos,  X, Y, m);  // funcao de interpolacao
FILE *file1; // arquivo de saida
file1 = fopen("saida.txt", "w");

fprintf(file1,"Polinomio interpolador:\n");
for(i = 0; i<m;i++){
	 if(i == m-1){
	 	fprintf(file1,"%.4f ",X[i]);
	 }else{
	 fprintf(file1,"%.4fx^%d + ",X[i],m-i-1);
	 }
	
}


	return 0; 
}
