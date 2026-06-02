#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE 200

typedef struct Node
{
    char line[MAX_LINE];
    struct Node *next;
}Node;
Node* createNode(char text[]);
void insertEnd(Node **head, char text[]);
void readFileToList(char filename[], Node **head);
void writeListToFile(char filename[], Node *head);
void freeList(Node *head);
Node* createNode(char text[]){
    Node *newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->line,text);
    newNode->next=NULL;

    return newNode;
}
void insertEnd(Node **head,char text[]){
    Node *newNode=createNode(text);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
void readFileToList(char sourceFile[],Node **head){
    FILE *fp=fopen(sourceFile,"r");
    if(fp==NULL){
        printf("Cannot open source file!\n");
        return;
    }
    char buffer[MAX_LINE];
    while(fgets(buffer,sizeof(buffer),fp)!=NULL){
        insertEnd(head,buffer);
    }
    fclose(fp);
}
void writeListToFile(char destFile[],Node *head){
    FILE *fp=fopen(destFile,"w");
    if(fp==NULL){
        printf("Cannot open destination file!\n");
        return;
    }
    Node *temp=head;
    while(temp!=NULL){
        fputs(temp->line,fp);
        temp=temp->next;
    }
    fclose(fp);
}
void freeList(Node *head){
    Node *temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}
int main(){
    Node *head=NULL;
    char sourceFile[100];
    char destFile[100];
    printf("Enter source file name: ");
    scanf("%s",sourceFile);
    printf("Enter destination file name: ");
    scanf("%s",destFile);
    readFileToList(sourceFile,&head);
    writeListToFile(destFile,head);
    printf("File copied successfully using linked list.\n");
    freeList(head);
    return 0;
}