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
