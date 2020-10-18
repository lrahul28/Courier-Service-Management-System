#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define V 9
#define INFINITY 9999
#define MAX 10
struct data{
    char name[25];
    int src;
    int dest;
    int pr;
}d,temp[100];
void dijkstra(int **G,int n,int startnode,int dest)
{
        int cost[MAX][MAX],distance[MAX],pred[MAX];
        int visited[MAX],count,mindistance,nextnode,i,j;
           for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            if(G[i][j]==0)
            cost[i][j]=INFINITY;
            else
            cost[i][j]=G[i][j];
           for(i=0;i<n;i++)
           {
                      distance[i]=cost[startnode][i];
                      pred[i]=startnode;
                      visited[i]=0;
           }
           distance[startnode]=0;
           visited[startnode]=1;
           count=1;
           while(count<n-1)
           {
    mindistance=INFINITY;
    for(i=0;i<n;i++)
    if(distance[i]<mindistance&&!visited[i])
       {
        mindistance=distance[i];
        nextnode=i;
        }
   visited[nextnode]=1;
        for(i=0;i<n;i++)
        if(!visited[i])
        if(mindistance+cost[nextnode][i]<distance[i])
        {
        distance[i]=mindistance+cost[nextnode][i];
        pred[i]=nextnode;
        }
                      count++;
           }
        if(dest!=startnode)
            {
        printf("\nDistance To Be Travelled=%d",distance[dest]);
                printf("\nPath=");
                if(dest==0){
                printf("Hyderabad");
                }
                else if(dest==1)
                {
                    printf("Vizag");
                }
                else if(dest==2)
                {
                    printf("Chennai");
                }
                else if(dest==3)
                {
                    printf("Banglore");
                }
                else if(dest==4)
                {
                    printf("Delhi");
                }
                else if(dest==5)
                {
                    printf("Pune");
                }
                else if(dest==6)
                {
                    printf("Amritsar");
                }
                else if(dest==7)
                {
                    printf("Nagpur");
                }
                else if(dest==8)
                {
                    printf("Kolkata");
                }
        j=dest;
        do{
                j=pred[j];
                if(j==0){
                printf("<-Hyderabad");
                }
                else if(j==1)
                {
                    printf("<-Vizag");
                }
                else if(j==2)
                {
                    printf("<-Chennai");
                }
                else if(j==3)
                {
                    printf("<-Banglore");
                }
                else if(j==4)
                {
                    printf("<-Delhi");
                }
                else if(j==5)
                {
                    printf("<-Pune");
                }
                else if(j==6)
               {
                    printf("<-Amritsar");
                }
                else if(j==7)
                {
                    printf("<-Nagpur");
                }
                else if(j==8)
                {
                    printf("<-Kolkata");
                }
            }while(j!=startnode);
           }
}
int mycomp(const void* a,const void* b)
{
    return (*(struct data*)a).pr-(*(struct data*)b).pr;
}
void newreq(){
    int p;
    FILE *data;
    printf("\nEnter the type of post\n1.General\n2.Speed post\n3.Express\n-->");
    scanf("%d",&p);
    printf("\nEnter Name:-");
    scanf("%s",&d.name);
    printf("\nEnter Source:-");
    scanf("%d",&d.src);
    printf("\nEnter destination:-");
    scanf("%d",&d.dest);
    data=fopen("data.txt","a");
    if(p==1){
            d.pr=1;
    }
    else if(p==2){
            d.pr=2;
    }
    else if(p==3){
            d.pr=3;
    }
    fwrite(&d,sizeof(struct data),1,data);
    printf("\nData Submitted\n");
    fclose(data);
    data=fopen("data.txt","r+");
    int i=0,j=0;
    while(!feof(data))
    {
        fread(&temp[i],sizeof(struct data),1,data);
        i++;
    }
    qsort((void *)temp,i,sizeof(struct data),mycomp);
    fclose(data);
    data=fopen("data.txt","w+");
    while(--i)
    {
        fwrite(&temp[i],sizeof(struct data),1,data);
    }
    fclose(data);
    printf("enter any key to continue:\n");
    getch();
    system("cls");
}
void print(){
    FILE *data;
    data=fopen("data.txt","r");
    while(fread(&d,sizeof(struct data),1,data)){
    printf("\nName:-       %s",d.name);
    printf("\nSource:-     %d",d.src);
    printf("\nDestination:-%d",d.dest);
    printf("\npriority:-   %d\n",d.pr);
    }
    printf("\nEnter any key to continue\n");
    getch();
}
void track(){
    char name[100];
    printf("Enter the name of package:\n");
    scanf("%s",&name);
    FILE* data=fopen("data.txt","r+");
    int i=0,j=0;
    while(!feof(data))
    {
        fread(&temp[i],sizeof(struct data),1,data);
        i++;
    }
    i--;
    fclose(data);
    for(j=0;j<i;j++)
    {
        if(strcmp(temp[j].name,name)==0)
        {
            printf("FOUND\n");
            break;
        }
    }
    if(j==0)
    {
        printf("STATUS(:->)OUT FOR DELIVERY\n");
    }
    else if(j==i)
    {
        printf("STATUS(:->)PACKAGE DELIVERED\n");
    }
    else
    {
        printf("STATUS(:->)AT DISPACH CENTER\n");
    }
    printf("Enter something to continue....\n");
    getch();
    system("cls");
}
int main()
{
    int o,y,src,dest;
    int** array;
           int n=9;
           array = malloc(n*sizeof(*array));
           int count = 1;
           for(int i = 0; i < n; i++)
           {
               array[i] =(int *) malloc(n* sizeof(int));
               count++;
           }
           FILE* fp = fopen("file.txt", "r");
           for(int i = 0; i < 9; i++)
           {
               for(int j = 0; j < 9; j++)
               {
                   fscanf(fp, "%d", &array[i][j]);
               }
           }
        printf("\t\t\t WELCOME TO COURIER SERVICE SYSTEM\n");
    printf("Select the Interface\n1.User\n2.Administrator\n->");
    scanf("%d",&y);
    system("cls");
    char user[25],pass[25];
    if(y==1){
    while(o!=4){
        printf("\t\t\t WELCOME TO COURIER SERVICE SYSTEM\n");
        printf("\n-->Select your Request");
        printf("\n1)Book a new Order\n2)Track your order\n3)Exit\n-->");
        scanf("%d",&o);
        system("cls");
        switch(o){
            case 1:
                printf("Cities:- \n0.Hyderabad\n1.Vizag\n2.Chennai\n3.Banglore\n4.Delhi\n5.Pune\n6.Amritsar\n7.Nagpur\n8.Kolkata\n");
                newreq();break;
            case 2:track();break;
            case 3:printf("\t\t\tThank you\n");exit(0);break;
            }
        }
    }
    else if(y==2)
    {   printf("\nUser Name:");
        scanf("%s",user);
        printf("\nPassword:");
        int p=0;
        do{
        pass[p]=getch();
        if(pass[p]!='\n'){
            printf("*");
        }
        p++;
    }while(pass[p-1]!='\r');
        if((strcmp(user,"admin")!=0)&&(strcmp(pass,"admin")!=0)){
            printf("Incorrect");
            exit(0);
        }
      else{
            system("cls");
        int yy=0;
        while(1)
        {printf("Enter \n1. Get Path for Deliveries\n2. Deliver the order\n3.Show Remaining Deliveries\n4.Exit:\n");
        scanf("%d",&yy);
        system("cls");
        if(yy==4) break;
        if(yy==1)
        {
        FILE* data=fopen("data.txt","r");
        do{
            d.name[0]='\0';d.src=-1;d.dest=-1;d.pr=-1;
            fread(&d,sizeof(struct data),1,data);
            if(d.name[0]!='\0')
        {   printf("details of %s:",d.name);
            dijkstra(array,V,d.src,d.dest);
            printf("\n");
            printf("\n");
            }
            if(feof(data)) break;
        }while(1);
    fclose(data);
        printf("enter any key to continue:\n");
        getch();
        system("cls");
        }
        else if(yy==2)
        {
            FILE* data=fopen("data.txt","r+");
            int i=0,j=0;
            while(!feof(data))
            {
                fread(&temp[i],sizeof(struct data),1,data);
                i++;
            }
            i--;
            printf("%d\n",i);
            fclose(data);
            data=fopen("data.txt","w+");
           for(j=1;j<i;j++)
            {
            fwrite(&temp[j],sizeof(struct data),1,data);
            }
            fclose(data);
            printf("Delivered successful\n");
            printf("Enter any key to continue:\n");
            getch();
            system("cls");
        }
        else if(yy==3)
        {
            print();
        }
    }
    }
    }
    }
