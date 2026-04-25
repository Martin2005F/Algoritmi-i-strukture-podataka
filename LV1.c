1. zad Slozenost je O(n)


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void gen_arr(float V[], int n, float dg, float gg){
    
    for(int i=0; i<n; i++){
       V[i] = ((float)rand() / RAND_MAX) * (gg - dg) + dg;
    }
}

int sekv_pret( float V[], int n, float x ){
    


    for(int i=0; i<n; i++){
        if(V[i] == x){
            return i;
        }
    }
    
    return -1;
}

int main()
{
    float x;
    int dg, gg, n;

    printf("Velicina polja: ");
    scanf("%d", &n);
    printf("Donja granica: ");
    scanf("%d", &dg);
    printf("Gornja granica: ");
    scanf("%d", &gg);
    printf("Broj koji se trazi: ");
    scanf("%f", &x);

    float p[n];
    srand(time(NULL));

    gen_arr(p, n, dg, gg);

    printf("Generirai niz:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", p[i]);
    }
    printf("\n");

    int rezultat = sekv_pret(p, n, x);
    printf("Rezultat: %d\n", rezultat);
    
    return 0;
}


2. zad (JA SAM KORISTIO BUBBLE SORT) slozenost je O(n^2) 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void gen_arr(float V[], int n, float dg, float gg){
    
    for(int i=0; i<n; i++){
       V[i] = ((float)rand() / RAND_MAX) * (gg - dg) + dg;
    }
}


void sort(float V[], int n){
    for(int i=0; i<n-1; i++){
        float t;
        for(int j=0; j<n-i-1; j++){
            if(V[j] > V[j+1]){
                t= V[j];
                V[j] = V[j+1];
                V[j+1] = t;
            }
        }
    }
}

int main()
{
    int dg, gg, n;

    printf("Velicina polja: ");
    scanf("%d", &n);
    printf("Donja granica: ");
    scanf("%d", &dg);
    printf("Gornja granica: ");
    scanf("%d", &gg);

    float p[n];
    srand(time(NULL));

    gen_arr(p, n, dg, gg);

    printf("Generirai niz:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", p[i]);
    }
    printf("\n");

    sort(p, n);
    
    for(int i=0; i<n; i++){
        printf("%.2f ", p[i]);
    }
    
    return 0;
}


3. ZAD BIRNARNO PRETRAZIVANJE slozenost je O(log n)


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void gen_arr(float V[], int n, float dg, float gg){
    
    for(int i=0; i<n; i++){
       V[i] = ((float)rand() / RAND_MAX) * (gg - dg) + dg;
    }
}


void sort(float V[], int n){
    float t;
    for(int i=0; i<n-1; i++){
        for(int j=1; j<n; j++){
            if(V[j] > V[j+1]){
                t= V[j];
                V[j] = V[j+1];
                V[j+1] = t;
            }
        }
    }
}

int bin_pret( float V[], int n, float x ){
    int dg= 0;
    int gg = n-1;
    int s;
    while (dg<=gg){
        s = (dg +gg) / 2;
        if(V[s] == x){
            return s;
        }else if(x > V[s]){
            dg = s +1;
        }else if(x < V[s]){
            gg = s -1;
        }
    }
    return -1;
}

int main()
{
    int dg, gg, n;
    float x;
    
    printf("Velicina polja: ");
    scanf("%d", &n);
    printf("Donja granica: ");
    scanf("%d", &dg);
    printf("Gornja granica: ");
    scanf("%d", &gg);
    printf("Broj koji se trazi: ");
    scanf("%f", &x);
    
    float p[n];
    srand(time(NULL));

    gen_arr(p, n, dg, gg);

    printf("Generirai niz:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", p[i]);
    }
    printf("\n");

    sort(p, n);
    
    printf("Generirani niz:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", p[i]);
    }
    printf("\n");
    
    
    int rezultat = bin_pret(p, n, x);
    
    printf("%d", rezultat);
    printf("vrijeme mjerenja je %.6fms", (double)(t2-t1) / CLOCKS_PER_SEC);
    return 0;

}

