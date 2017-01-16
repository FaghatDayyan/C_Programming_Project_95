#include <stdio.h>
#include <string.h>
#include <time.h>
#include <dirent.h> 
#include <unistd.h>
#include <Windows.h>
#include <errno.h>
#include <Stdlib.h>
#include <conio.h>

//structs
struct information
{
    char firstname[21];
    char lastname[21];
    char user[21];
    char pass[21];
    char email[51];
    char age[4];
    char sex[2];
    char access[2];
    double time;

}info;

//global variable
char root[]={"C:\\Users\\Farshid Adavi"};
char n[200]={"C:\\Users\\Farshid Adavi\\root"};
char current[200]={"C:\\Users\\Farshid Adavi\\root"};
char command[400];
char first[100];
char second[100];
char third[100];
short int a=0;

//functions
int Login(void); //Check For Login Or register
void Signup(void); //Register
void Pass(void); //check pass
int AdminAccess(void); //Admin Access
int UserAccess(void); //User Access
int Access(void);
int Accessu(void);
void split (void);
int check(void);
int copyfile(void);
int movefile(void);
int showcontent(void);
int pwd(void);
int changedirectory(void);
int gotolastdirectory(void);
int edame1(void);
int edame(void);
int makedir(void);
int clear(void);
int printhistory(void);
int gettime(void);
int filedifference(void);
int catfile(void);
int removefile(void);
int helpsth(void);
int changeuser(void);



int main()
{
	strcpy(info.firstname,"ali");
    strcpy(info.lastname,"ebrahimi");
    strcpy(info.age,"19");
    strcpy(info.email,"eb.a76@gmail.com");
    strcpy(info.sex,"M");
    strcpy(info.user,"aliali");
    strcpy(info.pass,"12345678");
    strcpy(info.access,"0");
    FILE *ptr = fopen("userpass.txt","ab");
    FILE *ptr1 = fopen("temp.txt","ab");
    FILE *ptr2 = fopen("adminpass.txt","ab");
    //fwrite(&info,sizeof(struct information),1,ptr);
    //fwrite(&info,sizeof(struct information),1,ptr2);
    fclose(ptr1);
    fclose(ptr);
	fclose(ptr2);

    switch (Login())
    {
    	case 0:
   			Login();
   			break;
    	case 1:
   			if(!AdminAccess());
   				return 0;
   				break;
    	case 2:
   			if(!UserAccess());
   				return 0;
   				break;
    }
	scanf("...");
    return 0;
}

int Login(void)
{

	struct information temp;
    puts("please enter username and password\nif you're not registered yet, please enter \"sign up\" ");
    char user[21],pass[21];

    scanf("%20s%20s",user,pass);
    if(!(strcmp(user,"sign")) && !(strcmp(pass,"up")))
    {
        Signup();
        return 0;
    }

    FILE *ptr=fopen("userpass.txt","rb+");
    FILE *ptr2=fopen("adminpass.txt","rb+");
    fread(&info,sizeof(struct information),1,ptr);
    while((strcmp(info.user,user)))
    {
        if((feof(ptr)))
            break;
        fread(&info,sizeof(struct information),1,ptr);

    }

   if(!strcmp(info.user,user))
   {
       if(!strcmp(info.pass,pass))
       {
		   fread(&temp,sizeof(struct information),1,ptr2);
    	   while((strcmp(temp.user,user)))
    	   {
        	   if((feof(ptr2)))
           	   break;
       		   fread(&temp,sizeof(struct information),1,ptr2);

    	   }
		   if(!strcmp(temp.user,user))
		   	   return 1;
		   else
           	   return 2;
       }
       else
       {
           puts("Wrong Username  password\n");
           Login();

       }


   }

    else
   {

       puts("Wrong Username or password\n");
       Login();
   }

}

void Signup(void)
{
    FILE *ptr = fopen("temp.txt","ab+");
    char pass1[21];
    printf("welcome to our program\nFIRST NAME: ");
    scanf("%s",info.firstname);
    printf("LAST NAME: ");
    scanf("%s",info.lastname);
    printf("AGE: ");
    scanf("%s",info.age);
    printf("SEX(F/M): ");
    scanf("%s",info.sex);
    printf("USERNAME: ");
    scanf("%s",info.user);
    printf("PASSWORD: ");
    scanf("%s",info.pass);
    printf("RE-ENTER PASSWORD: ");
    scanf("%s",pass1);
    printf("E-MAIL: ");
    scanf("%s",info.email);
    if((strcmp(info.pass,pass1)));
        Pass();
    fwrite(&info,sizeof(struct information),1,ptr);
    printf("Register Completed Successfully,Wait For Admin to Confirm :)\n");
}
void Pass(void)
{
    char pass1[21];
    printf("Passwords Do Not Match!\nEnter Password Again: ");
    scanf("%s",info.pass);
    printf("Re-Enter Password: ");
    scanf("%s",pass1);
    if(strcmp(pass1,info.pass))
        Pass();
}
int AdminAccess(void)
{
	int order;
	struct information tempp;
	printf("you are admin 01																		%s %s\n",info.firstname,info.lastname);
	FILE *ptr =fopen("temp.txt","r");
	if(ptr != NULL)
		printf("some new users are waiting for your confirmation...\n enter 1 to confirm them or enter 2 to let them go\n");
		scanf("%d",&order);
		if(order==2)
		{
			remove("ptr2");

		}
		if(order==1)
		{
			fread(&tempp,sizeof(struct information),1,ptr);
			FILE *ptr2=fopen("userpass.txt","ab");
			fwrite(&tempp,sizeof(struct information),1,ptr2);
			fclose(ptr2);
			remove("ptr2");
		}
	if(!Access())
		return 0;
}
int UserAccess(void)
{
	printf("you are user 00																		%s %s\n",info.firstname,info.lastname);
	if(!Accessu())
		return 0;
}
void split (void){
	int i;
	for(int i=0;i<=99;i++){
		first[i]='\0';
		second[i]='\0';
		third[i]='\0';
	}
	for(i=0;command[i]!=' '&&command[i]!='\n'&&command[i]!='\0';i++){
		first[i]=command[i];
	}
	i++;
	int k=0;
	for(;command[i]!=' '&&command[i]!='\n'&&command[i]!='\0';i++){
		second[k]=command[i];
		k++;
	}
	i++;
	k=0;
	for(;command[i]!=' '&&command[i]!='\n'&&command[i]!='\0';i++){
		third[k]=command[i];
		k++;
	}
}


int check(void)
{		
		
		if(strcmp("exit",first)==0){
		return 0;
		}
		
		if(strcmp("cp",first)==0)
		{
			return 1;
		}
		if(strcmp("mv",first)==0)
		{
			return 2;
		}

		if(strcmp("time",first)==0)
		{
			return 5;
		}
		if(strcmp("history",first)==0)
		{
			return 6;
		}
		if(strcmp("ls",first)==0)
		{
			return 12;
		}
    	
		if(strcmp("cd",first)==0)
		{
			if(strcmp("..",second)==0)
			{
				return 10;
				
			}
			else
			{
				return 11;
			}
		}
		
		if(strcmp("pwd",first)==0)
		{
			return 8;
		}
		if(strcmp("mkdir",first)==0)
		{
			return 13;
		}
		if(strcmp("diff",first)==0)
		{
			return 7;
		}
		
		if(strcmp("cat",first)==0)
		{
			return 14;
		}	
		if(strcmp("rm",first)==0)
		{
			if(!strcmp("-r",second))
			{
				return 16;
			}
			else
			{
				return 15;
			}
		}
		if(strcmp("cal",first)==0)
		{
			return 17;
		}
		if(strcmp("wc",first)==0)
		{
			return 18;
		}
		
			if(strcmp("help",first)==0)
		{
			return 19;
		}
		
			if(strcmp("clear",first)==0)
		{
			return 22;
		}
		
			if(strcmp(">",second)==0)
		{
			return 23;
		}
		
			if(strcmp(">>",second)==0)
		{
			return 24;
		}
			if(strcmp("su",first)==0)
		{
			return 26;
		}
			if(strcmp("passwd-|",first)==0)
		{
			return 27;
		}
			if(strcmp("passwd",first)==0)	
		{
			return 28;
		}
			if(strcmp("create",first)==0)	
		{
			return 29;
		}
			if(strcmp("exif",first)==0)	
		{
			return 30;
		}
		return 25;
}

int copyfile(void)
{

	char c;
	FILE *file1=fopen(second,"r");
	FILE *file2=fopen(third,"w");
	c=fgetc(file1);

	while(c!=-1)
	{
		fprintf(file2,"%c",c);

		c=fgetc(file1);
	}
	printf("your file has been copied successfully\n");
	fclose(file2);

}
int movefile()
{

char temp[100];
int status;
 char c;
 strcpy(temp,current);
 strcat(temp,"\\\\");
 strcat(temp,second);
 FILE *file1=fopen(temp,"r");
 FILE *file2=fopen(third,"w");
 c=fgetc(file1);

 while(c!=-1)
 {
  fprintf(file2,"%c",c);

  c=fgetc(file1);
 }
 fclose(file2);
 fclose(file1);
    status = remove(temp);
 
   if( status == 0 )
      printf("%s file moved successfully.\n",second);
   else
   {
      remove(third);
      printf("Unable to move the file\n");
      perror("Error");
   }
}

int showcontent()
	{
		char you[260];
	  DIR           *d;
	  struct dirent *dir;
	  d = opendir(current);
	  if (d)
	  {
        while ((dir = readdir(d)) != NULL)
	    {
         printf("%s\n", dir->d_name);
        }

    closedir(d);
  	  }

	}
   
   int pwd()
   {
   	printf(current);
   	puts("");
   	
   }
   
   int changedirectory()
   
   {
   		char u[100];
   	  	int i;int k=0;
   	  	if (second[k]=='\\' && second[k+1]=='\\')
   	  	{
		strcat(root,second);
			 
   		DIR           *d;
	  struct dirent *dir;
	  d = opendir(root);
	  if (d)
	  {
		printf("DIRECTORY NAME: ");
		printf(second);
		puts("");
    closedir(d);
    
	strcpy(current,root);
  	  }
  	  else {
  	  	printf("not such directory\n");
   	    i=strlen(root);
   	    while (i > 0){
   	    if (	root[i - 1]== '\\' )
   	    {
   		
   		root[i-2]=0;
   		break;
     	}
   	
		i--;
   	    } 
  	    }
   	  	}
   	  	
   	  	else
   	  	{
   	  	
   	  	 

   	    strcat(current,"\\\\");
		strcat(current,second);
	 DIR           *d;
	  struct dirent *dir;
	  d = opendir(current);
	  if (d)
	  {
		printf("DIRECTORY NAME: ");
		printf(second);
		puts("");
    closedir(d);
  	  }
  	  else {
  	  	printf("not such directory\n");
   	    i=strlen(current);
   	    while (i > 0){
   	    if (	current[i - 1]== '\\' )
   	    {
   		
   		current[i-2]=0;
   		break;
     	}
   	
		i--;
   	    } 
  	    }
	}



   	 
   }
   
   int gotolastdirectory()
   {
   	int i;
   	i=strlen(current);
   	if(!strcmp(current, root))
   		return 0;
   	while (i > 0){
   	if (	current[i - 1]== '\\' )
   	{
   		
   		current[i-2]=0;
   		break;
   	}
   	
		i--;
   	}
  
   }
   
int edame1()
{
		char c;

	char temp1[100];
	char temp2[100];
	strcpy(temp1,current);
	strcat(temp1,"\\\\");
	strcat(temp1,first);
	strcat(temp1,".txt");

	FILE *ptr;
	if((ptr=fopen(temp1,"r"))!=NULL)
	{
			strcpy(temp2,current);
			strcat(temp2,"\\\\");
			strcat(temp2,third);
			FILE *ptr3=fopen(temp2,"a");
			c=fgetc(ptr);
			while(c!=-1)
		{
	   		fprintf(ptr3,"%c",c);

			c=fgetc(ptr);
		}
		fclose(ptr);
		fclose(ptr3);
	}
	
	else 
	{
		char temp[100];
		strcpy(temp,current);
		strcat(temp,"\\\\");
		strcat(temp,third);
		FILE *ptr2=fopen(temp,"a");
		fprintf(ptr2,"%s",first);
		
		fclose(ptr2);
	}
	
}

int edame()
{

		char c;

	char temp1[100];
	char temp2[100];
	strcpy(temp1,current);
	strcat(temp1,"\\\\");
	strcat(temp1,first);
	strcat(temp1,".txt");

	FILE *ptr;
	if((ptr=fopen(temp1,"r"))!=NULL)
	{
			strcpy(temp2,current);
			strcat(temp2,"\\\\");
			strcat(temp2,third);
			FILE *ptr3=fopen(temp2,"w");
			c=fgetc(ptr);
			while(c!=-1)
		{
	   		fprintf(ptr3,"%c",c);

			c=fgetc(ptr);
		}
		fclose(ptr);
		fclose(ptr3);
	}
	
	else 
	{
		char temp[100];
		strcpy(temp,current);
		strcat(temp,"\\\\");
		strcat(temp,third);
		FILE *ptr2=fopen(temp,"w");
		fprintf(ptr2,"%s",first);
		
		fclose(ptr2);
	}
	
}	



   
 int makedir()
 {
 	strcat(current,"\\\\");
	strcat(current,second);
 	int a=mkdir(current);
 	if (a==0)
 	{
 		printf("New Directory Has Been Made...");
 	}
 	else 
 	{
 		printf("Oops , Directory can't be created...'");
 	}
 }
 int clear()
 {
 	for (int i=0;i<50;i++)
 	printf("\n");
 	
COORD coord;
  coord.X = 0;
  coord.Y = 20;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
  }
   int printhistory()
	{
		FILE *showhistory=fopen("..\\history1.txt","r");
		while(!feof(showhistory))
		{
			char c=fgetc(showhistory);
			printf("%c",c);
		}
		
		
	}
	
	int changeuser(void)
	{
		char pass[21];
		struct information temp,temp1;
		if(!strcmp(info.access,"1"))
		{
		FILE *ptr=fopen("userpass.txt","rb+");
    FILE *ptr2=fopen("adminpass.txt","rb+");
    fread(&temp,sizeof(struct information),1,ptr);
    while((strcmp(temp.user,second)))
    {
        if((feof(ptr)))
            break;
        fread(&temp,sizeof(struct information),1,ptr);

    }

   if(!strcmp(temp.user,second))
   {
   			info=temp;
		   fread(&temp1,sizeof(struct information),1,ptr2);
    	   while((strcmp(temp1.user,second)))
    	   {
        	   if((feof(ptr2)))
           	   break;
       		   fread(&temp,sizeof(struct information),1,ptr2);

    	   }
		   if(!strcmp(temp1.user,second))
		   	   AdminAccess();
		   else
           	   UserAccess();
       }
       else
       {
           puts("Username not found\n");
           AdminAccess();

       }

	
		}
		else
		{
			
	FILE *ptr=fopen("userpass.txt","rb+");
    FILE *ptr2=fopen("adminpass.txt","rb+");
    fread(&temp,sizeof(struct information),1,ptr);
    while((strcmp(temp.user,second)))
    {
        if((feof(ptr)))
            break;
        fread(&temp,sizeof(struct information),1,ptr);

    }

   if(!strcmp(temp.user,second))
   {
   
   printf("please enter password");
   scanf("%20s",pass);
   if(!strcmp(pass,temp.pass))
   		{	info=temp;
		   fread(&temp1,sizeof(struct information),1,ptr2);
    	   while((strcmp(temp1.user,second)))
    	   {
        	   if((feof(ptr2)))
           	   break;
       		   fread(&temp,sizeof(struct information),1,ptr2);

    	   }
		   if(!strcmp(temp1.user,second))
		   	   AdminAccess();
		   else
           	   UserAccess();
       }
       else
       {
           puts("Username not found\n");
           UserAccess();

       }
	}
	
			
			
		}
	}
	
	int gettime()
	{
	  time_t rawtime;
	  struct tm * timeinfo;
	
	  time ( &rawtime );
	  timeinfo = localtime ( &rawtime );
	  printf ( "Current local time and date: %s", asctime (timeinfo) );
	}
	
		int filedifference()
	{
	    char ch1, ch2,c;
	    	char temp1[100];
			char temp2[100];
			strcpy(temp1,current);
			strcat(temp1,"\\\\");
			strcat(temp1,second);
			strcat(temp1,".txt");
			strcpy(temp2,current);
			strcat(temp2,"\\\\");
			strcat(temp2,second);
			strcat(temp2,".txt");
		FILE *file1=fopen(temp1,"rb");
		FILE *file2=fopen(temp2,"rb");
		//FILE *file3=fopen("E:\\root\\telldiff.txt","w");
		
	    if (file1 == NULL)
		 {
	      printf("Cannot open %s for reading ", second);
			return 0;
	 	  } 
	   else if (file2 == NULL) {
	      printf("Cannot open %s for reading ", third);
			return 0;
	   } else 
	   {
	      ch1 = getc(file1);
	      ch2 = getc(file2);
    	}
    	
      while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2)) {
      	 //fprintf(file3,"%c",ch1);
         ch1 = getc(file1);
         ch2 = getc(file2);
      }

      if (ch1 == ch2)
         printf("Files are identical \n");
         
      else if (ch1 != ch2)
         printf("Files are Not identical \n");
      fclose(file1);
      fclose(file2);
   }
   
  int catfile()
{
	char test[200];
	strcpy(test,current);
	strcat(test,"\\\\");
	strcat(test,second);
	strcat(test,".txt");
	char c;
	FILE *filee=fopen(test,"r");
	if(filee==NULL)
	{
		printf("Not Such A File");
	}
	else
	{
		printf("File Name: ");
		printf(second);
		puts("");
	}
	while (! feof(filee))
	{
		c=fgetc(filee);
		printf("%c",c);
	}
	fclose(filee);
}

	int removefile()
	{
		char test[200];
		strcpy(test,current);
		strcat(test,"\\\\");
		strcat(test,second);
		strcat(test,".txt");
		int status;
		status = remove(test);
		
	    if( status == 0 )
	      printf("%s file deleted successfully.\n",second);
	    else
	    {
	      printf("Unable to delete the file\n");
	      perror("Error");
	    }
		
	}
	
	int removedir()
	{
		char tempp[200];
		for(int i=0;current[i]!='\0';i++)
		{
			tempp[i]=current[i];
		}
		strcat(tempp,"\\\\");
	    strcat(tempp,third);
	    
	    if(rmdir(tempp))
		printf("Error");
		else
		puts("deleted");
	
			     
	}
	
	int wordcount()
{
	int w=0,l=0;
	char c;
	char tempp[200];
	strcpy(tempp,current);
		strcat(tempp,"\\\\");
	    strcat(tempp,second);
	    strcat(tempp,".txt");
	FILE *ptr=fopen(tempp,"r");
	   if(ptr==NULL)
     {
         printf("file not found\n");
         return 0;
      }
	c=fgetc(ptr);
	while(!feof(ptr))
	{
		if(c==' ')
		w++;
		if(c=='\n')
		l++;
		c=fgetc(ptr);
		
	}
	fclose(ptr);
	printf("number of lines : %d\n",l+1);
	printf("number of lines : %d\n",w+1);

}

int helpsth()

{
	if(strcmp("su",second)==0)
		{
			printf("""su username"" is for changing username\n");
		}
		
	if(strcmp("passwd",second)==0)
		{
			if(strcmp("-|",third)==0)
			printf("""passwd -| username"" is for admin to set time for user\n");
			else
			printf("""passwd username"" changes the password\n");
		}
		
		
	
		
		
	if(strcmp("create",second)==0 && strcmp("user",third)==0)
		{
			printf("""create user"" is for admin to create a new user\n");
		}
		
	if(strcmp("cal",second)==0)
		{
			printf("""cal"" shows the calander of the current month\n");
		}
		
		
	if(strcmp("time",second)==0)
		{
			printf("""time"" gets the system time and shows you the current time\n");
		}
		
	if(strcmp("clear",second)==0)
		{
			printf("""clear"" clears the console screen\n");
		}
		
	if(strcmp("exit",second)==0)
		{
			printf("""exit"" well...obvious...it ends the program\n");
		}
		
		if(strcmp("history",second)==0)
		{
			printf("""history"" well...obvious...it ends the program\n");
		}
		
		if(strcmp("cd",second)==0)
		{
			printf("""cd"" changes the direcory\n");
		}
		
		if(strcmp("cd..",second)==0)
		{
			printf("""cd.."" will go to the last directory\n");
		}
		
		if(strcmp("pwd",second)==0)
		{
			printf("""pwd"" shows you the current place that you are in the system\n");
		}
		
		if(strcmp("mkdir",second)==0)
		{
			printf("""mkdir"" makes a folder by the name that you enter  mkdir filename\n");
		}
		
		if(strcmp(">",second)==0)
		{
			printf(""">""If you write an expression before'>' and a file name after '>' your expression will be written in the file and from the begining of it.\n If you write the name of a file before'>' the whole contents of the first file\n will be written in the next file\n");
		}
		
		if(strcmp(">>",second)==0)
		{
			printf(""">>""If you write an expression before'>>' and a file name after '>>' your expression will be written in the file and not from the begining.\n If you write the name of a file before'>>' the whole contents of the first file\n will be written in the next file\n");
		}
		
		if(strcmp("cat",second)==0)
		{
			printf("""cat"" shows you the content of a file\n");
		}
		
		if(strcmp("rm",second)==0)
		{
		if(strcmp("-r",third)==0)
		{
			printf("""rm -r"" will delete a folder\n");
		}
			else
			
			printf("""rm"" will delete a file\n");
		}
		
		
		if(strcmp("cp",second)==0)
		{
			printf("""cp"" will copy a file into another file\n");
		}
		
		if(strcmp("mv",second)==0)
		{
			printf("""mv""will move a file\n");
		}
		
		if(strcmp("ls",second)==0)
		{
			printf("""ls""will show the content of a folder\n");
		}
		
		if(strcmp("exif",second)==0)
		{
			printf("""exif"" will show you all information about a file...who made it...the time it was made etc.\n");
		}
		
		if(strcmp("wc",second)==0)
		{
			printf("""wc""will counts the number of words and lines in a file\n");
		}
		
		if(strcmp("diff",second)==0)
		{
			printf("""diff"" tells you whether two files are the same or not\n");
		}
		
		if(strcmp(second,"myeditor")==0){
		printf("Myeditor:\n");
  		printf("CTRL+R: Read the file CTRL+E: Exit the programme\n\n");
	  	printf("CTRL+R : Enter the name of file if this file exists you can see its contests & if this file doesn't exist the editor gets the name of file and creat it then you cand read it\n\n");
  		printf("CTRL+W: Writing in the file(writing end of the file) CTRL+S: Search a string in the file C:Copy & Past CTRL+E: Exit and go back to myeditor environment\n\\n");
  		printf("CTRL+W: Write in the end of file then CTRL+S: Save the changes CTRL+C: Do not save the changes\n\n");
  		printf("CTRL+S: Searching in the file -> gets a string and if it exists in the file the cursor goes to the begining of it and if it dosen't exist you see a massagebox which tells it doesn't exist. CTRL+E: Exit and go back to myeditor environment\n\n");
  		printf("C OR c : Copy & Past -> you can move cursor in the editor environment by --> e:key up d:key down s:key left f:key right . So in the beging of the word that you want to copy press CTRL+C and the press CTRL+A to past this word in the end of file. CTRL+E: Exit and go back to myeditor environment\n\n");
  		printf("CTRL+E: Exit and go back to myeditor environment\n\n");}
}

 
 

int Access (void)
{
	while(true)
	{
    FILE *history= fopen("..\\history1.txt","a");
	fgets(command,400,stdin);
    fprintf(history,"%s",command);
	fclose(history);
	history = NULL;
	split();

    
    switch(check())
	{
		
		case 0:
            return 0;
            
        case 1:
        	 copyfile();	
        	 break;
        case 2:
       		 movefile();
        	 break;
	
    	case 5:
	   		gettime();
		   	break;
		
		case 6:
	   		printhistory();
	   		break;
	   	
	   	case 7:
	   		filedifference();
	   		break;
	   	
	   	case 8:
	   		pwd();
	   		break;
	   		
	   	case 11:
	   		changedirectory();
	   		break;
	   		
	   	case 10:
	   		gotolastdirectory();
	   		break;
	   		
	   	case 12:
	   		showcontent();
	   		break;
	   		
	   	case 13:
	   		makedir();
	   		break;
	   		
	   	case 14:
	   		catfile();
	   		break;
		
		case 15:
	   		removefile();
	   		break; 
			   
		case 16:
			removedir();
			break;
			
		case 18:
	   	wordcount();
	   	break;	
	   		
	   	case 19:
	   		
	   		helpsth();
	   		break;
	   		
	   	case 22:
	   		clear();
	   		break;
	   	
	   	case 23:
	   		edame();
	   		break;
	   		
	   	case 24:
	   		edame1();
	   		break;
	   	
		case 26:
			changeuser();
			break;	
    }
}


}

int Accessu(void)
{
		while(true)
	{
    FILE *history= fopen("..\\history1.txt","a");
	fgets(command,400,stdin);
    fprintf(history,"%s",command);
	fclose(history);
	history = NULL;
	split();

    
    switch(check())
	{
		
		case 0:
            return 0;
            
        case 1:
        	 copyfile();	
        	 break;
        case 2:
       		 movefile();
        	 break;
	
    	case 5:
	   		gettime();
		   	break;
		
		case 6:
	   		printhistory();
	   		break;
	   	
	   	case 7:
	   		filedifference();
	   		break;
	   	
	   	case 8:
	   		pwd();
	   		break;
	   		
	   	case 11:
	   		changedirectory();
	   		break;
	   		
	   	case 10:
	   		gotolastdirectory();
	   		break;
	   		
	   	case 12:
	   		showcontent();
	   		break;
	   		
	   	case 13:
	   		makedir();
	   		break;
	   		
	   	case 14:
	   		catfile();
	   		break;
		
		case 15:
	   		removefile();
	   		break; 
			   
		case 16:
			removedir();
			break;
			
		case 18:
	   	wordcount();
	   	break;	
	   		
	   	case 19:
	   		
	   		helpsth();
	   		break;
	   		
	   	case 22:
	   		clear();
	   		break;
	   	
	   	case 23:
	   		edame();
	   		break;
	   		
	   	case 24:
	   		edame1();
	   		break;
	   		
	   	case 26:
			changeuser();
			break;	
	   		
    }
}

}


