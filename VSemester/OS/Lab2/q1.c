#include<stdio.h> 
#include<stdlib.h> 
#include<sys/stat.h> 
#include<sys/types.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<string.h> 
#include<dirent.h> 

int main()
{ 
	DIR* d = opendir("/home/oslab/Documents/210905033/OSL/Lab2/sample_files");
	char* buff; 
	
	if(d == NULL)
	{ 
		printf("Incorrent directory path!\n"); 
		exit(0); 
	} 
	
	struct dirent *directory; 	
	struct stat mystat;

	printf("File Permission		Login 		Name\n");
	
	while((directory = readdir(d)) != NULL)
	{

		lstat(directory->d_name, &mystat);
		
		if(S_ISDIR(mystat.st_mode))
		{ 
			if(strcmp(".", directory->d_name) == 0 || strcmp("..", directory->d_name) == 0) 
				continue;  
			printf("d"); 
		} 
		else
			printf("-"); 
		
		if(mystat.st_mode & S_IRUSR)
			printf("r"); 
		else 
			printf("-"); 
		
		if(mystat.st_mode & S_IWUSR)
			printf("w"); 
		else 
			printf("-"); 
		
		if(mystat.st_mode & S_IXUSR)
			printf("-"); 
		else 
			printf("-"); 
		
		if(mystat.st_mode & S_IRGRP) 
			printf("r"); 
		else
			printf("-"); 
		
		if(mystat.st_mode & S_IWGRP)
			printf("w"); 
		else 
			printf("-"); 
		
		if(mystat.st_mode & S_IXGRP)
			printf("-"); 
		else
			printf("-"); 
		
		if(mystat.st_mode & S_IROTH)
			printf("r"); 
		else
			printf("-"); 
		
		if(mystat.st_mode & S_IWOTH)
			printf("w"); 
		else
			printf("-"); 
		
		if(mystat.st_mode & S_IXOTH)
			printf("-\t\t"); 
		else
			printf("-\t\t"); 
		
		buff = getlogin(); 
		printf("%s\t\t", buff); 

		printf("%s\n",directory->d_name); 
	} 
} 