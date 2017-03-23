#include "rsa1.h"

int prime(long int pr) { 
	int i; 
	j = sqrt(pr); 
	for(i = 2; i <= j; i++) { 
		if((pr % i) == 0) 
			return 0; 
	} 
	return 1; 
}

void ce() { 
	int k = 0; 
	for(i = 2; i < t; i++) { 
		if((t % i) == 0) 
			continue; 
		flag = prime(i); 
		if(flag == 1 && (i != p) && (i != q)) { 
			e[k] = i; 
			flag = cd(e[k]); 
			if(flag > 0) { 
				d[k] = flag; 
				k++;
			}
			if(k == 99) 
				break; 
		}
	}
}

long int cd(long int x) { 
	long int k = 1; 
	while(1) { 
		k = k + t; 
		if(k % x == 0) 
			return(k / x); 
	} 
} 

