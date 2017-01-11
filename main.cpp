#include <stdio.h>
#include <string.h>

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

}info;

//global variable
short int a=0;

//functions
void Login(void); //Check For Login Or register
void Signup(void); //Register
void pass(void); //check pass

int main()
{
    FILE *ptr=fopen("userpass.txt","w");
    FILE *ptr1 = fopen("temp.txt","ab+");
    fclose(ptr1);
    fclose(ptr);
    Login();
    while(a)
    {
        a = 0;
        Login();
    }
    
    return (0);
}

void Login(void)
{

    puts("please enter username and password\nif you're not registered yet, please enter \"sign up\" ");
    char user[21],pass[21];

    scanf("%20s%20s",user,pass);
    if(!(strcmp(user,"sign")) && !(strcmp(pass,"up")))
    {
        Signup();
        a=1;
        return;
    }

    FILE *ptr=fopen("userpass.txt","rb+");
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
           return;
       }
       else
       {
           puts("Wrong Username or password\n");
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
        pass();
    fwrite(&info,sizeof(struct information),1,ptr);
    printf("Register Completed Successfully,Wait For Admin to Confirm :)\n");
}
void pass(void)
{
    char pass1[21];
    printf("Passwords Do Not Match!\nEnter Password Again: ");
    scanf("%s",info.pass);
    printf("Re-Enter Password: ");
    scanf("%s",pass1);
    if(strcmp(pass1,info.pass))
        pass();
}