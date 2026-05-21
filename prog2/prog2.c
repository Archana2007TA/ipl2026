#include<stdio.h>
#include<stdlib.h>
struct Student{
    int id;
    char name[50];
    float marks;
};

void  storeRecords(int n);
int createSeekPositions(long pos[]);
void displayRecord(long position);

int main(){
    int n,i,total;
    long pos[100];
    printf("Enter number of records:");
    scanf("%d",&n);
    storeRecords(n);
    total=createSeekPositions(pos);
    printf("\nSeek Positions of Records:\n");
    for(int i=0;i<total;i++){
        printf("Record %d starts at byte position %ld\n",i+1,pos[i]);
    }
    int rec;
    printf("Enter record number to display:");
    scanf("%d",&rec);
    if(rec>=1 && rec<=total){
        displayRecord(pos[rec-1]);
    }
    else{
        printf("Invalid record number!\n");
    }

    return 0;
}
void storeRecords(int n){
    FILE *fp;
    struct Student s;
    int i;
    fp=fopen("student.txt","w");
    if(fp==NULL){
        printf("File cannot be opened!\n");
        return;
    }
    for(int i=0;i<n;i++){
        printf("Enter details of Student %d\n",i+1);
        printf("ID:");
        scanf("%d",&s.id);
        printf("Name:");
        scanf("%s",s.name);
        printf("Marks:");
        scanf("%f",&s.marks);
        fprintf(fp,"%d %s %.2f\n",s.id,s.name,s.marks);
    }
    fclose(fp);
}
int createSeekPositions(long pos[]){
    FILE *fp;
    struct Student s;
    int count=0;
    fp=fopen("student.txt","r");
    if(fp==NULL){
        printf("File cannot be opened!\n");
        return 0;
    }
    while(1){
        pos[count]=ftell(fp);
        if(fscanf(fp,"%d %s %f",&s.id,s.name,&s.marks)!=3){
            break;
        }
        count++;
    }
    fclose(fp);
    return count;
}
void displayRecord(long position){
    FILE *fp;
    struct Student s;
    fp=fopen("student.txt","r");
    if(fp==NULL){
        printf("File cannot be opened!\n");
        return;
    }
    fseek(fp,position,SEEK_SET);
    fscanf(fp,"%d %s %f",&s.id,s.name,&s.marks);
    printf("Record Details:\n");
    printf("ID: %d\n",s.id);
    printf("Name: %s\n",s.name);
    printf("Marks: %.2f\n",s.marks);
    fclose(fp);
    
}