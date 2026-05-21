#include<stdio.h>
#include<stdlib.h>
struct Student{
    int id;
    char name[30];
    float marks;
};

void storeRecords(){
    FILE *fp;
    int n,i;
    fp=fopen("student.dat","wb");
    if(fp==NULL){
        printf("File cannot be opened!\n");
        return;
    }
    printf("Enter number of records: ");
    scanf("%d",&n);
    
    struct Student s;

    for(i=0;i<n;i++){
    printf("\n Enter details of student %d\n",i+1);
    printf("ID: ");
    scanf("%d",&s.id);
    printf("Name: ");
    scanf("%s",s.name);
    printf("Marks: ");
    scanf("%f",&s.marks);
    fwrite(&s,sizeof(struct Student),1,fp);
    }
    fclose(fp);
}
void displayMthRecord(int m){
    FILE *fp;
    struct Student s;
    fp=fopen("student.dat","rb");
    if(fp==NULL){
        printf("File cannot be opened!\n");
        return;
    }
    fseek(fp,(m-1)*sizeof(struct Student),SEEK_SET);
    fread(&s,sizeof(struct Student),1,fp);
    printf("\nMth Record Details:\n");
    printf("ID: %d\n",s.id);
    printf("Name: %s\n",s.name);
    printf("Marks: %.2f\n",s.marks);

    fclose(fp);
}
void deleteRecord(int delId){
    FILE *fp,*temp;
    struct Student s;
    fp=fopen("student.dat","rb");
    temp=fopen("temp.dat","wb");
    if(fp==NULL || temp==NULL){
        printf("File error!\n");
        return;
    }
    while(fread(&s,sizeof(struct Student),1,fp)){
        if(s.id!=delId){
            fwrite(&s,sizeof(struct Student),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("student.dat");
    rename("temp.dat","student.dat");

    printf("Record deleted successfully.\n");
}
int main(){
    int m,delId;
    storeRecords();
    printf("\nEnter record number to display: ");
    scanf("%d",&m);
    displayMthRecord(m);
    printf("\nEnter ID to delete: ");
    scanf("%d",&delId);
    deleteRecord(delId);
    return 0;
}