/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 09:27:33 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define max 10000
#define output "%10s%4d%4d%7.2lf"


typedef struct student{
    long offset;
    char name[20];
    int age;
    int class;
    double height;

}student;

student sarr[max + 5];
int sc;

int rfile(student *arr){
    int i = 0;
    //FILE*fp = fopen("data.txt","r");
    FILE*fp = fopen("data.txt","rb");
    if (fp == NULL)return 0;
    while (1){
        long offset = ftell(fp);
        //if (fscanf(fp,"%s",sarr[i].name) == EOF) break;
        if (fread(arr+i,sizeof(int),1,fp) == 0) break;
        //fscanf(fp,"%d%d%lf",&sarr[i].age,&sarr[i].class,&sarr[i].height);
        arr[i].offset = offset;
        //fgetc(fp);
        i++;
    }
    fclose(fp);
    return i;
}

long pfile(student*arr,int n){
    //FILE *fp = fopen("data.txt","a");
    FILE *fp = fopen("data.txt","ab");
    fseek(fp,0,SEEK_END);
    long offset = ftell(fp);
    fwrite(arr, sizeof(student),n,fp);
    //for (int i = 0; i < n; i++){
        //fprintf(fp, output "\n",arr[i].name,
              //arr[i].age,
              //arr[i].class,
              //arr[i].height);
   //}
    fclose(fp);
    return offset;
}

void clear(){
    FILE *fp = fopen("data.txt","w");
    fclose(fp);
    return;
}

void mod2(student*stu){
    //FILE *fp = fopen("data.txt","r+");
    FILE *fp = fopen("data.txt","rb+");
    fseek(fp,stu->offset,SEEK_SET);
    fwrite(stu,sizeof(student),1,fp);
    //fprintf(fp,output,stu->name,stu->age,
           //stu->class,
           //stu->height);
    fclose(fp);
    return;
}

void ls(){
    int len = printf("%4s|%10s|%4s|%6s|%7s","id","name","age","class","height");
    printf("\n");
    for (int i = 0; i < len; i++)printf("=");
    printf("\n");
    for (int i = 0; i < sc; i++){
        printf("%4d|%10s|%4d|%6d|%7.2lf\n",
              i,sarr[i].name,
              sarr[i].age,sarr[i].class,
              sarr[i].height
              );
    }
    return;
}

void rdata(student *arr,int n){
    clear();
    pfile(arr,n);
    return;
}

void mod(){
    ls();
    int id;
    do{
        printf("modify id: ");
        scanf("%d",&id);
    }while (id <0 || id >=sc);

    printf("modify : new item : (name, age, class, height)\n");
    printf("mysql > ");
    scanf("%s%d%d%lf",sarr[id].name,
         &sarr[id].age,
         &sarr[id].class,
         &sarr[id].height
         );
    mod2(sarr + id);
    //rdata(sarr,sc);
    return;
}


void ads(){
    printf("add new item : (name, age, class, height)\n");
    printf("mysql > ");
    scanf("%s%d%d%lf",sarr[sc].name,
          &sarr[sc].age,
         &sarr[sc].class,
         &sarr[sc].height
         );
    sarr[sc].offset = pfile(sarr+sc,1);
    sc++;
    printf("add a new student success");
    return;
}

void rdelet(){
    if (sc == 0){
        printf("There is no student\n");
        return;
    }
    ls();
    int id;
    do{
        printf("delete id: ");
        scanf("%d",&id);
    }while(id < 0 || id >=sc);
    char s[100];
    printf("confim (y / n) : ");
    getchar();
    scanf("%[^\n]",s);
    if (s[0] != 'y') return;
    for (int i = id+1; i <sc; i++){
        long offset = sarr[i-1].offset;
        sarr[i-1] = sarr[i];
        sarr[i-1].offset = offset;
    }
    sc-=1;
    rdata(sarr,sc);
    return;
}

enum no_type{
    list = 1,
    add,
    modify,
    delete,
    quit
};

int usage(){
    int no;
    do{
        printf("%d : list students\n",list);
        printf("%d : add a new student\n",add);
        printf("%d : modify a  student\n",modify);
        printf("%d : delete a stuent\n",delete);
        printf("%d : quit\n",quit);
        printf("mysql >");
        scanf("%d",&no);
    }while(no < list || no >quit);
    return no;
}

int main(){
    sc = rfile(sarr);
    while (1){
        int no = usage();
        printf("inupt no: %d\n",no);
        switch (no){
            case list: {
                ls();
            }break;
            case add: {
                ads();
            }break;
            case modify: {
                mod();
            } break;
            case delete: {
                rdelet();
            } break;
            case quit: printf("quit\n");exit(0);
        }
    }
    return 0;
}
