#include<stdio.h>
void printBitsInt(int n){
    int i;
    for(int i=31;i>=0;i--){
        printf("%d",(n>>i) & 1);

        if(i % 8 ==0){
            printf(" ");
        }
    }
    printf("\n");
}
int count1Bits(int n){
    int count=0;
    while(n!=0){
        count+=n&1;
        n=n>>1;
    }
    return count;
}
void checkEndian(){
    int x=1;
    char *p=(char *)&x;
    if(*p==1)
        printf("System is Little Endian\n");
    else
        printf("System is Big Endian\n");
}
void printBitsFloat(float f){
    int *p=(int *)&f;
    int i;
    for(i=31;i>=0;i--){
        printf("%d",(*p>>i)&1);
        if(i==31 || i==23){
            printf(" ");
        }
    }
    printf("\n");
}
int main(){

    int n;
    float f;
    printf("Enter an integer: ");
    scanf("%d",&n);
    printf("\nBits of integer:\n");
    printBitsInt(n);

    printf("\nNumber of 1 bits= %d\n",count1Bits(n));

    printf("\nEndian Check:\n");
    checkEndian();
    printf("\nBits of negative integer (%d):\n",-n);
    printBitsInt(-n);

    printf("\nEnter a floating point number: ");
    scanf("%f",&f);

    printf("\nBits of float:\n");
    printBitsFloat(f);

    printf("\nBits of negative float (%f):\n",-f);
    printBitsFloat(-f);

    return 0;
}