#include "rsa1.h"

long int p,q,n,t,flag,e[1000],d[1000],temp[1000],j,m[1000],en[1000],i; 

void main() {  
	printf("\nENTER FIRST PRIME NUMBER\n"); 
	scanf("%ld", &p); 
	flag = prime(p); 
	if(flag == 0)  { 
		printf("\nWRONG INPUT. Enter PRIME number\n");  
		exit(1); 
	} 
	printf("\nENTER ANOTHER PRIME NUMBER\n"); 
	scanf("%ld", &q);
	flag = prime(q); 
	if(flag == 0 || p == q) { 
		printf("\nWRONG INPUT. Enter PRIME Number.\n"); 
		exit(1); 
	} 
	
	for(i = 0; msg[i] != '\0'; i++) 
		m[i] = msg[i];
	n = p * q;
	t = (p - 1) * (q - 1); 
	ce();
	printf("\nPOSSIBLE VALUES OF e AND d ARE\n"); 
	for(i = 0; i < (j - 1); i++) 
		printf("\n%ld\t%ld",e[i],d[i]); 

	char fName[100] = "test.txt";
	
	char dirName[500] = "~/Dirr";
	
	DIR *dr;
	struct dirent *dir;
    
	dr = opendir (dirName);
	char ext[20][20];

	int di = 0;
	if (dr)
	{
		printf("\n\n===\n\nEXTERNAL DRIVES LIST\n");
		while ((dir = readdir (dr)) != NULL)
		{
			if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
				continue;
			}
			strcpy (ext[di], dir->d_name);
			printf ("\n%d. %s\n", di, dir->d_name);
			di++;
		}

		closedir (dr);

		printf ("Enter which external drive to encrypt\n");
		scanf ("%d", &di);
		strcat (dirName, "/");
		strcat (dirName, ext[di]);
		while(1) { 
			printf("\n\nDo you want to ?\n1. Encrypt all inner files?\n2. Decrypt all encrypted files\n3. Exit\n");
			int choice;
			scanf("%d", &choice);
			if(choice == 1) {
				printf ("Showing details for %s external drive\n", ext[di]);
				dirEncrypt(dirName);
			}
			else if(choice == 2) {
				printf ("Showing details for %s external drive\n", ext[di]);
				dirDecrypt(dirName);
			}
			else if(choice == 3) {
				exit(0);
			}
		}
	}
	
}

