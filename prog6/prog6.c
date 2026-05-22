#include<stdio.h>
#define ROWS 25
#define COLS 50
typedef struct{
    int centerX;
    int centerY;
    int radius;
}Circle;
void initializeBuffer(char buffer[ROWS][COLS]);
void setPixel(char buffer[ROWS][COLS],int x,int y);
void drawCircle(char buffer[ROWS][COLS],Circle c);
void displayBuffer(char buffer[ROWS][COLS]);
int main(){
    char buffer[ROWS][COLS];
    Circle c;

    printf("Enter center X(0-%d): ",COLS-1);
    scanf("%d",&c.centerX);

    printf("Enter centerY(0-%d): ",ROWS-1);
    scanf("%d",&c.centerY);

    printf("Enter radius: ");
    scanf("%d",&c.radius);

    initializeBuffer(buffer);
    drawCircle(buffer,c);
    displayBuffer(buffer);

    return 0;
}
void initializeBuffer(char buffer[ROWS][COLS]){
    int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            buffer[i][j]=' ';
        }
        buffer[i][COLS]='\0';
    }
}
void setPixel(char buffer[ROWS][COLS],int x,int y){
    if(x>=0 && x<COLS && y>=0 && y<ROWS){
        buffer[y][x]='*';
    }
}
void drawCircle(char buffer[ROWS][COLS],Circle c){
    int x,y;
    int r2=c.radius*c.radius;
    for(y=0;y<ROWS;y++){
        for(x=0;x<COLS;x++){
            int dx=x-c.centerX;
            int dy=y-c.centerY;

            int dist = dx*dx + dy*dy;

            if (dist>=r2-c.radius && dist<=r2+c.radius)
            {
                setPixel(buffer,x,y);
            }
            
        }
    }
}
void displayBuffer(char buffer[ROWS][COLS]){
    int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            printf("%c",buffer[i][j]);
        }
        printf("\n");
    }
}