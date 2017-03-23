#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 
#include <dirent.h>

extern long int p,q,n,t,flag,e[1000],d[1000],temp[1000],j,m[1000],en[1000],i; 
char msg[100]; 
int prime(long int); 
void ce(); 
long int cd(long int); 
void encrypt(char *); 
void decrypt(char *); 
void dirDecrypt(char *);
void dirEncrypt(char *);

#define MAX_SIZE 100
