#include<stdio.h>
#include<string.h>
int naiveSearch(char text[],char pat[]);
void computeLPS(char pat[],int lps[]);
int KMPSearch(char text[],char pat[]);
int naiveSearch(char text[],char pat[]){
    int n=strlen(text);
    int m=strlen(pat);
    int i,j;
    for(i=0;i<=n-m;i++){
        for(j=0;j<m;j++){
            if(text[i+j]!=pat[j])
                break;
        }
        if(j==m)
            return i;
    }
    return -1;
}
void computeLPS(char pat[],int lps[]){
    int len=0;
    int i=1;
    int m=strlen(pat);
    lps[0]=0;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
int KMPSearch(char text[],char pat[]){
    int n=strlen(text);
    int m=strlen(pat);
    int lps[m];
    computeLPS(pat,lps);
    int i=0;
    int j=0;
    while(i<n){
        if(text[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            return i-j;
        }
        else if(i<n && text[i]!=pat[j]){
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
    return -1;
}
int main(){

    char text[100];
    char pattern[100];

    printf("Enter Text: ");
    fgets(text,sizeof(text),stdin);
    text[strcspn(text,"\n")]='\0';

    printf("Enter pattern: ");
    fgets(pattern,sizeof(pattern),stdin);
    pattern[strcspn(pattern,"\n")]='\0';
    
    int naiveIndex=naiveSearch(text,pattern);
    int kmpIndex=KMPSearch(text,pattern);
    printf("\n---Results---\n");
    if(naiveIndex==-1)
        printf("Naive Search : Pattern Not Found\n");
    else
        printf("Naive Search : Pattern Found at Index %d\n",naiveIndex);
    if(kmpIndex==-1)
        printf("KMP Search : Pattern Not Found\n");
    else
        printf("KMP Search : Pattern Found at Index %d\n",kmpIndex);
    printf("\n---Comparison---\n");
    printf("Naive Search Worst Case Time Complexity : O(n*m)\n");
    printf("KMP Search Worst Case Time Complexity : O(n+m)\n");
    printf("KMP avoids unnecessary comparsions using the LPS array,\n");
    return 0;
}