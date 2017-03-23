#include "rsa1.h"


void dirDecrypt(char *dirName) {
    printf("Decrypting directory %s\n", dirName);
    DIR *dr;
    struct dirent *dir;
    dr = opendir (dirName);
    if (dr)
    {
        while ((dir = readdir (dr)) != NULL)
        {
            if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
                continue;
            }
            if(dir->d_name[strlen(dir->d_name) - 1] == 'c' && dir->d_name[strlen(dir->d_name) - 2] == 'n' && dir->d_name[strlen(dir->d_name) - 3] == 'e' && dir->d_name[strlen(dir->d_name) - 4] == '.') {

                char fn[100];
		strcpy(fn, dirName);
		strcat(fn, "/");
		strcat(fn, dir->d_name);
		decrypt(fn);
            }
            int j, flagD = 0;
            for(j = 0; j < strlen(dir->d_name); j++) {
                if(dir->d_name[j] == '.') {
                    flagD = 1;
                    break;
                }
            }
            if(flagD == 0) {
                printf("Opening directory %s\n", dir->d_name);
                char fn[100];
                strcpy(fn, dirName);
                strcat(fn, "/");
                strcat(fn, dir->d_name);

                dirDecrypt(fn);
            }
        }


    }
    closedir(dr);
}

void dirEncrypt(char *dirName) {
    printf("Encrypting directory %s\n", dirName);
    DIR *dr;
    struct dirent *dir;
    dr = opendir (dirName);
    if (dr)
    {
        while ((dir = readdir (dr)) != NULL)
        {
        	if(dir->d_name[0] == '.') {
        		continue;
        	}
            if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
                continue;
            }
            if(dir->d_name[strlen(dir->d_name) - 1] == 'c' && dir->d_name[strlen(dir->d_name) - 2] == 'n' && dir->d_name[strlen(dir->d_name) - 3] == 'e' && dir->d_name[strlen(dir->d_name) - 4] == '.') {
                printf("File %s already encrypted\n", dir->d_name);
                continue;
            }
            int j, flagD = 0;
            for(j = 0; j < strlen(dir->d_name); j++) {
                if(dir->d_name[j] == '.') {
                    flagD = 1;
                    break;
                }
            }
            if(flagD == 0) {
                printf("Opening directory %s\n", dir->d_name);
                char fn[100];
                strcpy(fn, dirName);
                strcat(fn, "/");
                strcat(fn, dir->d_name);

                dirEncrypt(fn);
            }
            else {
                printf("Encrypting file %s\n", dir->d_name);
                char fn[100];
                strcpy(fn, dirName);
		strcat(fn, "/");
		strcat(fn, dir->d_name);
		encrypt(fn);
            }
        }


    }
    closedir(dr);
}


