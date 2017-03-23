#include "rsa1.h"

void encrypt(char *fName) { 

	FILE *fp = fopen(fName, "r+");
	char fName2[200] = "";
	strcat(fName2, fName);
	strcat(fName2, ".enc");
	FILE *fp2 = fopen(fName2, "a+");
	char ch = 'a';
	int cnt = 0;

	while((ch = getc(fp)) != EOF) {
		char str[MAX_SIZE + 1];	
		cnt = 0;
		while((cnt < MAX_SIZE-1 && (ch != EOF))) {
			str[cnt] = ch;
		    	cnt++;
		    	ch = getc(fp);
		}
		
		str[cnt] = '\0';
		printf("String is : %s\n", str);
		
		

		
		long int pt, ct, key = e[0], k, len; 

		len = strlen(str);

		int tc = 0;
		for(tc = 0; tc < len; tc++) {
			m[tc] = str[tc];
		}
		i = 0;
		while(i != len) { 
			pt = m[i]; 
			printf("%ld ", pt);
			pt = pt - 96;
			k = 1; 
			for(j = 0; j < key; j++) { 
				k = k * pt; 
				k = k % n; 
			} 
			temp[i] = k;

			ct = k + 96; 
			en[i] = ct; 
			i++;
		}
		printf("temp = %s \n", (char *) temp);
		en[i] = -1; 
		printf("\nTHE ENCRYPTED MESSAGE IS\n"); 

		for(i = 0; en[i] != -1; i++) {
			printf("%ld", en[i]); 
			fwrite(&en[i], 1, sizeof(long int), fp2); 
		}	
	}

	fclose(fp);	
	fclose(fp2);
	
	char remCmd[30] = "rm ";
	strcat(remCmd, fName);
	system(remCmd);

} 
void decrypt(char *fileName) { 
	printf("Decrypting file %s\n", fileName);

	char fileNewName[250];
	int cntr;
	for(cntr = 0; cntr < (strlen(fileName) - 4); cntr++)
		fileNewName[cntr] = fileName[cntr];
	fileNewName[cntr] = '\0';
	FILE *fp2 = fopen(fileName, "r+");
	FILE *fp3 = fopen(fileNewName, "w+");
	long int longi;
	i = 0;
	while(fread(&longi, 1, sizeof(long int), fp2) && longi != -1) {
		printf("Value of longi = %ld\n", longi);
		longi -= 96;
		long int pt, ct, key = d[0], k;

		ct = longi; 
		k = 1; 
		for(j = 0; j < key; j++) { 
			k = k * ct; 
			k = k % n; 
		} 
		pt = k + 96; 
		m[i] = pt; 
		i++;

	}
	m[i] = -1; 
	printf("\nTHE DECRYPTED MESSAGE IS\n"); 
	for(i = 0; m[i] != -1; i++) {
		printf("%c", (char) m[i]);
		fprintf(fp3, "%c", (char) m[i]);
	}
	printf("\n"); 
	fclose(fp2);
	fclose(fp3);
	char remCmd[30] = "rm ";
	strcat(remCmd, fileName);
	system(remCmd);

}

