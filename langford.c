
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


//calculate ceiling
int ceiling_div4(int n) {
    return (n + 3) / 4;  // Integer division automatically floors, so we add 3 to get the ceiling for positive n
}
//print
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
}

//print reverse
void printReverse(int arr[], int size) {
    for (int i = size - 1; i >= 0; --i) {
        printf("%d, ", arr[i]);
    }
}

//---------------------------------------------------------------------------------------//

//Helper 1
void print_sequence(int *arr, int size) {
    printf("Your sequence: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
//Helper2
bool is_langford_pairing(int a, const int array[]){
    if ((a / 2) % 4 != 0 && (a / 2) % 4 != 3) {
        return false;
    }
    int half = a/2;
    for (int i = 0;i< a; i++){
        if (array[i] == 0 || array <0){
            return false;
        }
        if (array[i] > half)
        {
           return false;
        }
        int curr = i;
        int front = curr - array[i] -1;
        int end = curr + array[i] +1 ;

        if (array[curr] != array[front] && array[curr] != array[end]){
            return false;
        }}
    return true;
}

//helper 3
void print_langford_paring(int n, int type){
    int x = ceiling_div4(n);
    int a = 2 * x - 1;
    int b = 4 * x - 2;
    int c = 4 * x - 1;
    int d = 4 * x;

    int p_size = (a - 1) / 2;
    int p[p_size];
    int q_size = (a - 1) / 2;
    int q[q_size];
    int r_size = (b - a - 1) / 2;
    int r[r_size];
    int s_size = (b - a) / 2;
    int s[s_size];

    //List p
    int idx = 0;
    for (int i = 1; i <= (a-1);i++){
        if (i%2 ==1){
            p[idx] = i;
            idx += 1;
        }
    }
    //List q
    idx = 0;
    for (int i=2; i<= (a-1);i++){
         if (i%2 ==0){
            q[idx] = i;
            idx += 1;
        }
    }
    //List r
    idx = 0;
    for (int i=(a+2); i<= (b-1);i++){
         if (i%2 ==1){
            r[idx] = i;
            idx += 1;
        }
    }
    //List s
    idx = 0;
    for (int i=(a+1); i<= (b-1);i++){
         if (i%2 ==0){
            s[idx] = i;
            idx += 1;
        }
    }
    if (type == 0){
        printf("[");
        printReverse(s,s_size);
        printReverse(p,p_size);
        printf("%d, ",b);
        printArray(p,p_size);
        printf("%d, ",c);
        printArray(s,s_size);
        printf("%d, ",d);
        printReverse(r,r_size);
        printReverse(q,q_size);
        printf("%d, ",b);
        printf("%d, ",a);
        printArray(q,q_size);
        printf("%d, ",c);
        printArray(r,r_size);
        printf("%d, ",a);
        printf("%d",d);
        printf("]\n");

    }else if (type == 3)
    {
        printf("[");
        printReverse(s,s_size);
        printReverse(p,p_size);
        printf("%d, ",b);
        printArray(p,p_size);
        printf("%d, ",c);
        printArray(s,s_size);
        printf("%d, ",a);
        printReverse(r,r_size);
        printReverse(q,q_size);
        printf("%d, ",b);
        printf("%d, ",a);
        printArray(q,q_size);
        printf("%d, ",c);
        printArray(r,r_size);
        printf("]\n");
    }




}
//-----------------------------------------------------------------------------------//
int main( int argc, char *argv[] ) {
    //No argument
    if ((argc == 1) || (strcmp(argv[1], "-h") == 0)){
        printf("usage: %s [-h] -c n | num...\n", argv[0]);
        return 0;
    }
    //First argument is -c
    else if (strcmp(argv[1], "-c") == 0){
        if(argc == 2){
             printf("%s: -c option requires an argument.\n",argv[0]);
            return 0;
        } else if (argc ==3){
            char *endptr;
            int value = strtol(argv[2], &endptr, 10);
            int mod = value % 4;

            if (endptr == argv[2] || *endptr != '\0') {
                printf("error: %s is not an integer.\n", argv[2]);
                return 1;
            } else {
                printf("Creating a langford pairing with n=%d\n", value);
                int n_1 = (3*value*value -value)%4;
                if ((n_1 == 1)|| n_1 == 2){
                    printf("No results found.\n");
                    return 0;
                } else{
                    print_langford_paring(value,mod);
                }
            }
        } else if (argc >3){
           printf("%s: -c option received too many arguments.\n", argv[0]);
            return 0;
        }
    }
//-----------------------------------------------------------------------------------------//
    //First argument is nither -c nor -h
    else if((strcmp(argv[1], "-h") != 0) && (strcmp(argv[1], "-c") != 0)){
        int values[argc - 1]; // Assuming argc > 1

        for (int i = 1; i < argc; i++) {
            char *endptr;
            values[i - 1] = strtol(argv[i], &endptr, 10);

            if (endptr == argv[i] || *endptr != '\0') {
                printf("error: %s is not an integer.\n", argv[i]);
                return 1;}
                }

        print_sequence(values, argc - 1);

        if (is_langford_pairing(argc-1,values) == 1){
            printf("It is a langford pairing!\n");
        }else{
            printf("It is NOT a langford pairing.\n");
        }
        return 0;
    }

}
