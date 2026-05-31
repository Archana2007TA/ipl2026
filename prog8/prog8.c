#include <stdio.h>
#include <math.h>
#define MAX 20

typedef struct{
    int disk[MAX];
    int top;
    char name;
}Peg;

void push(Peg *p,int x){
    p->disk[++p->top]=x;
}
int pop(Peg *p){
    return p->disk[p->top--];
}
int topDisk(Peg *p){
    if(p->top==-1)
        return  999999;
    return p->disk[p->top];
}
void moveDisk(Peg *from,Peg *to){
    int d=pop(from);
    push(to,d);
    printf("Move disk %d from %c to %c\n",d,from->name,to->name);
}
void legalMove(Peg *p1,Peg *p2){
    if(topDisk(p1)<topDisk(p2))
        moveDisk(p1,p2);
    else
        moveDisk(p2,p1);
}
int main(){
    int n;
    printf("Enter number of disks: ");
    scanf("%d",&n);
    Peg A={.top=-1,.name='A'};
    Peg B={.top=-1,.name='B'};
    Peg C={.top=-1,.name='C'};
    for(int i=n;i>=1;i--){
        push(&A,i);
    }
    long long totalMoves=(1LL<<n)-1;
    for(long long move=1;move<=totalMoves;move++){
        if(n%2==1){
            if(move%3==1){
                legalMove(&A,&C);
            }
            else if(move%3==2){
                legalMove(&A,&B);
            }
            else{
                legalMove(&B,&C);
            }
        }
        else{
            if(move %3==1){
                legalMove(&A,&B);
            }
            else if(move %3==2){
                legalMove(&A,&C);
            }
            else{
                legalMove(&B,&C);
            }
        }
    }
    return 0;
}