#include <stdlib.h>
#include <stdio.h>

#define MAX_R 50

int rand_equa(int diff,int *x,int *y,char *symb);
int check_results(int R_MAT[][3],int NMBR_R,int NMBR_T);

int main(){

    int result, rand_result, diff, nmb_rech,results_mat[MAX_R][3],i = 0;
    int x = 0,y = 0;
    long nmb_equa = 0;
    char symb;

    printf("Entrer a result to find : ");
    scanf("%d",&result);

    do{
    printf("Enter the number of equations to show (<50): ");
    scanf("%d",&nmb_rech);
    }while(nmb_rech > 50);

    printf("Enter the difficulty of search from 1 to 10*");
    scanf("%d",&diff);

    do{
        rand_result = rand_equa(diff,&x,&y,&symb);
        results_mat[i][0] = x;
        results_mat[i][1] = symb;
        results_mat[i][2] = y;
        if(result == rand_result && check_results(results_mat,i,nmb_rech)){
            printf("%d %c %d = %d\n",x,symb,y,result);
            i++;
        }
        nmb_equa++;
    }while(i != nmb_rech);

    printf("\n\t%ld results found !\n",nmb_equa);

return 0;
}

int rand_equa(int diff,int *x,int *y,char *symb){
    //srand(time(NULL));
    int result = 0;
    int rand_symb = rand() % 4; // 0 = +; 1 = -; 2 = *; 3 = /;
    *x = (rand() % (10*diff)) + 1;
    *y = (rand() % (10*diff)) + 1;
    switch(rand_symb){
        case 0 :
            *symb = '+';
            result = *x + *y;
            break;
        case 1 :
            *symb = '-';
            result = *x - *y;
            break;
        case 2 :
            *symb = '*';
            result = *x * *y;
            break;
        case 3 :
            *symb = '/';
            while(*x % *y != 0){
                *x = (rand() % (10*diff)) + 1;
            }
            result = *x / *y;
            break;
    }

    return result;
}

int check_results(int R_MAT[][3],int NMBR_R,int NMBR_T){
    int t,i;
    if(NMBR_R == 1)
        return 1;

    for(i = 0; i < NMBR_R; i++)
        for(t = NMBR_R; t < NMBR_T;t++)
            if((R_MAT[i][0] == R_MAT[t][0]) && (R_MAT[i][1] == R_MAT[t][1]) && (R_MAT[i][2] == R_MAT[t][2]))
                return 0;

    return 1;
}

