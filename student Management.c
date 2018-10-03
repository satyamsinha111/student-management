/*Project on maintaining the records of student in a coaching*/
//declaring header files
#include<stdio.h>//contains the declartion of input output and also of files
#include<stdlib.h>//contains defination of stdin
#include<string.h>//contains defination if strings
#include<windows.h>//contains the defination to move curser and console of windows based system
#include<conio.h>//contains defination of console screen
//defination of structure
struct student{
	char name[20],school[20];
	int age,rl,cl;
};
//defination of gotoxy
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//declaring variables
int choice;
int x,y,id,s,r;
void delay(long x){
	int i;
	for(i=0;i<=x;i++){

	}
}
//declaring function for deleting files
void Delete(){
	struct student s1;
	FILE *fp1;
	FILE *fp2;
	fp1=fopen("rec.dat","rb");
	fp2=fopen("replica.dat","wb");
	if(fp1==NULL){
		printf("No file found!!!");
		exit(0);
	}
	printf("Enter the id you want to delete:");
	scanf("%d",&id);
	while(fread(&s1,sizeof(s1),1,fp1)!=0){
		if(id!=s1.cl){
			fwrite(&s1,sizeof(s1),1,fp2);
		}
		}
	fclose(fp1);
	fclose(fp2);
	remove("rec.dat");
	rename("replica.dat","rec.dat");
	printf("Record deleted succesfully.....");
	gotoxy(20,26);
	 printf("Do you want to exit..");
	 scanf("%d",&choice);
	 if(choice==1){
	 	system("cls");
	 	UI();
	 }
	if(choice==0){
		system("cls");
		Delete();
	}
}
//defination for searching algorithm
void search(){
	struct student s1;
	char n[10];
	int age;
	FILE *fp;
	fp=fopen("rec.dat","rb");
	if(fp==NULL){
		gotoxy(20,22);
		printf("No File found!!");
		exit(0);
	}
    gotoxy(12,10);
	printf("Search:");
	scanf("%d",&age);
	for(x=10;x<=50;x++){
     	gotoxy(x,7);
     	printf(".");
     	delay(1000000);
	 }
	  for(y=7;y<=12;y++){
     	gotoxy(10,y);
     	printf(".");
        delay(1000000);
	 }
	  for(x=10;x<=50;x++){
     	gotoxy(x,12);
     	printf(".");
     	delay(1000000);
	 }
	  for(y=7;y<=12;y++){
     	gotoxy(50,y);
     	printf(".");
     	delay(1000000);
	 }
    for(x=15;x<=60;x++){
     	gotoxy(x,16);
     	printf(".");
     	delay(1000000);
	 }
	  for(y=16;y<=27;y++){
     	gotoxy(15,y);
     	printf(".");
        delay(1000000);
	 }
	  for(x=15;x<=60;x++){
     	gotoxy(x,27);
     	printf(".");
     	delay(1000000);
	 }
	  for(y=16;y<=27;y++){
     	gotoxy(60,y);
     	printf(".");
     	delay(1000000);
	 }
	 	while(fread(&s1,sizeof(s1),1,fp)!=0)
	{
	  if(s1.cl==age){
	  	gotoxy(17,18);
		printf("Name of the student is %s\n",s1.name);
		gotoxy(17,20);
		printf("School of the student is %s\n",s1.school);
		gotoxy(17,22);
		printf("Roll number of student is %d\n",s1.rl);
		gotoxy(17,24);
		printf("Age of the student is %d\n",s1.age);
		gotoxy(17,26);
		printf("ID of the student is %d\n",s1.cl);
		fclose(fp);
	}
	else{
            gotoxy(17,22);
        printf("Sorry! No result found!!!");
	}
	}
	gotoxy(20,26);
	 printf("Do you want to exit..");
	 scanf("%d",&choice);
	 if(choice==1){
	 	system("cls");
	 	UI();
	 }
	if(choice==0){
		system("cls");
	    search();
	}
}
//defination to list all records
void List(){
	struct student s1;
	FILE *fp;
	fp=fopen("rec.dat","rb");
	if(fp==NULL){
		 gotoxy(17,22);
        printf("Sorry! No result found!!!");
        exit(0);
	}
	while(fread(&s1,sizeof(s1),1,fp)>0){
		printf("%s=%d\n",s1.name,s1.cl);
	}
	fclose(fp);
	gotoxy(20,26);
	 printf("Do you want to exit..");
	 scanf("%d",&choice);
	 if(choice==1){
	 	system("cls");
	 	UI();
	 }
	if(choice==0){
		system("cls");
		List();
	}
}
//defination to change password
void ChangePassword(){
    FILE *fp;
    char pss[30],cpss[30],str[40];
    fp=fopen("pss.txt","w");
    fflush(stdin);
    printf("Enter the password:");
    gets(pss);
    printf("Enter confirm password:");
    gets(cpss);
    if(strcmp(pss,cpss)==0)
    {
        printf("password created successfully");
        fputs(cpss,fp);
    }
    else{
        printf("password don`t match");
    }
    fclose(fp);
    gotoxy(20,26);
	 printf("Do you want to exit..");
	 scanf("%d",&choice);
	 if(choice==1){
	 	system("cls");
	 	UI();
	 }
	if(choice==0){
		system("cls");
		ChangePassword();
	}
}
//defination to add records
void add(){
	system("cls");
	struct student s1;
	FILE *fp;
	fp=fopen("rec.dat","ab");

	if(fp==NULL){
		gotoxy(20,22);
		printf("No file found!!");
		exit(0);
	}
	for(x=10;x<=60;x++){
     	gotoxy(x,7);
     	printf(".");
     	delay(1000000);
	 }
	  for(y=7;y<=20;y++){
     	gotoxy(10,y);
     	printf(".");
        delay(1000000);
	 }
	  for(x=10;x<=60;x++){
     	gotoxy(x,20);
     	printf(".");
     	delay(1000000);
	 }
	  for(y=7;y<=20;y++){
     	gotoxy(60,y);
     	printf(".");
     	delay(1000000);
	 }
	 fflush(stdin);
	 gotoxy(17,9);
	 printf("Enter the name of student--->");
	 gets(s1.name);
	 gotoxy(17,11);
	 printf("Enter the school of student--->");
	 gets(s1.school);
	 gotoxy(17,13);
	 printf("Enter the roll no. of student--->");
	 scanf("%d",&s1.rl);
	 gotoxy(17,15);
	 printf("Enter the age of student--->");
	 scanf("%d",&s1.age);
	 gotoxy(17,17);
	 printf("Enter the ID of student--->");
	 scanf("%d",&s1.cl);
	 fwrite(&s1,sizeof(s1),1,fp);
	 gotoxy(20,22);
	 printf("Record added successfully");
	 fclose(fp);
	 gotoxy(20,26);
	 printf("Do you want to exit..");
	 scanf("%d",&choice);
	 if(choice==1){
	 	system("cls");
	 	UI();
	 }
	if(choice==0){
		system("cls");
		add();
	}
	 for(x=0;x<=79;x++){
	 	gotoxy(x,37);
	 	printf("x");
	 	delay(1000000);
	 }
}
//defination to modify records
void Modify(){
	struct student s1;
	FILE *fp1;
	FILE *fp2;
	fp1=fopen("rec.dat","rb");
	fp2=fopen("replica.dat","ab");
	if(fp1==NULL){
		printf("No file found!!!");
		exit(0);
	}
	printf("Enter the id you want to modify:");
	scanf("%d",&id);
	while(fread(&s1,sizeof(s1),1,fp1)!=0){
		if(id!=s1.cl){

			fwrite(&s1,sizeof(s1),1,fp2);
		}
	}
	for(x=10;x<=60;x++){
     	gotoxy(x,7);
     	printf(".");
     	delay(1000000);
	 }
	  for(y=7;y<=20;y++){
     	gotoxy(10,y);
     	printf(".");
        delay(1000000);
	 }
	  for(x=10;x<=60;x++){
     	gotoxy(x,20);
     	printf(".");
     	delay(1000000);
	 }
	  for(y=7;y<=20;y++){
     	gotoxy(60,y);
     	printf(".");
     	delay(1000000);
	 }
	fflush(stdin);
	 gotoxy(17,9);
	 printf("Enter the name of student--->");
	 gets(s1.name);
	 gotoxy(17,11);
	 printf("Enter the school of student--->");
	 gets(s1.school);
	 gotoxy(17,13);
	 printf("Enter the roll no. of student--->");
	 scanf("%d",&s1.rl);
	 gotoxy(17,15);
	 printf("Enter the age of student--->");
	 scanf("%d",&s1.age);
	 gotoxy(17,17);
	 printf("Enter the ID of student--->");
	 scanf("%d",&s1.cl);
	 fwrite(&s1,sizeof(s1),1,fp2);
	fclose(fp1);
	fclose(fp2);
	remove("rec.dat");
	rename("replica.dat","rec.dat");
	printf("Record modified succesfully.....");
    gotoxy(20,26);
	 printf("Do you want to exit..");
	 scanf("%d",&choice);
	 if(choice==1){
	 	system("cls");
	 	UI();
	 }
	if(choice==0){
		system("cls");
		Modify();
	}

}
//defination for user interface
void UI(){
	int choice;
     for(x=10;x<=60;x++){
     	gotoxy(x,2);
     	printf(".");
     	delay(1000000);
	 }
	  for(y=2;y<=10;y++){
     	gotoxy(10,y);
     	printf(".");
        delay(1000000);
	 }
	  for(x=10;x<=60;x++){
     	gotoxy(x,10);
     	printf(".");
     	delay(1000000);
	 }
	  for(y=2;y<=10;y++){
     	gotoxy(60,y);
     	printf(".");
     	delay(1000000);
	 }
	 gotoxy(23,4);
	 printf("\aStudent record system\a");
	 for(x=10;x<=60;x++){
	 	gotoxy(x,6);
	 	printf("-");
	 	delay(1000000);
	 }
	 gotoxy(25,8);
	 printf("Technical Academy");
	 gotoxy(11,9);
	 printf("Adress:7 no. burnpur road near policeline asansol");
	 for(x=0;x<=79;x++){
	 	gotoxy(x,12);
	 	printf("*");
	 	delay(1000000);
	 }
	 for(x=10;x<=60;x++){
     	gotoxy(x,14);
     	printf(".");
     	delay(1000000);
	 }
	  for(y=14;y<=35;y++){
     	gotoxy(10,y);
     	printf(".");
        delay(1000000);
	 }
	  for(x=10;x<=60;x++){
     	gotoxy(x,35);
     	printf(".");
     	delay(1000000);
	 }
	  for(y=14;y<=35;y++){
     	gotoxy(60,y);
     	printf(".");
     	delay(1000000);
	 }
	 gotoxy(17,16);
	 printf("Here are the features of the system");
	 gotoxy(20,18);
	 printf("1:Add student record");
	 gotoxy(20,20);
	 printf("2:Delete student record");
	 gotoxy(20,22);
	 printf("3:Modify student record");
	 gotoxy(20,24);
	 printf("4:Search student record");
	 gotoxy(20,26);
	 printf("5:See all records");
	 gotoxy(20,28);
	 printf("6:Change password");
	 gotoxy(20,30);
	 printf("7:Shut down");
	 for(x=10;x<=60;x++){
	 	gotoxy(x,32);
	 	printf("-");
	 	delay(1000000);
	 }
	 for(x=0;x<=79;x++){
	 	gotoxy(x,37);
	 	printf("x");
	 	delay(1000000);
	 }
	  gotoxy(19,34);
	 printf("Enter your choice:");
	 scanf("%d",&choice);
	 switch(choice){
	 	case 1:{
	 		system("cls");
	 		printf("\a");
	 		add();
			break;
		 }
		 case 2:{
		system("cls");
		 	printf("\a");
		 	Delete();
			break;
		 }
		 case 3:{
		 system("cls");
		 	printf("\a");
		 	Modify();
			break;
		 }
		   case 4:{
		   	system("cls");
		 	printf("\a");
		 	search();
			break;
		 }
	 	case 5:{
	 		system("cls");
	 		printf("\a");
	 		List();
			break;
		 }
		 case 6:{
		 	system("cls");
		 	printf("\a");
		 	ChangePassword();
			break;
		 }
		 case 7:{
            system("cls");
            printf("\a");
            exit(0);
            break;
		 }
	 }
}
//here is the main funstion which is called by os program will start from here
int main()
{
    while(1){
        system("cls");
    char str[60],pasword[60],c;
   FILE *fp;
   fp=fopen("pss.txt","r");
   fflush(stdin);
   printf("Enter the password:");
   gets(pasword);
   while(fgets(str,59,fp)!=NULL)
   {
       if(strcmp(pasword,str)==0)
       {
           system("cls");
           UI();
       }
       else{
        printf("password does not matches");
        printf("try again(y/n)");
        scanf("%c",&c);
        if(c=='y'){
            system("cls");
            break;
        }
        if(c=='n'){
            exit(0);
        }
       }
   }
   fclose(fp);
    }
	return 0;
}
