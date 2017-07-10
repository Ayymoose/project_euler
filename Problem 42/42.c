#include <stdio.h>
#include <omp.h>
#include <string.h>

int is_triangle_number(int n) {
	int m=1;
	while (2*n != m*m + m) {
		if (2*n < m*m + m) return 0; 
		m++;
	}
	return m;
}

// Returns whether string is triangle word
int triangle_word(char *string) {
	int triangle = 0;
	//Ignore double quotes
	for (int i=1; i<strlen(string)-1; i++) {
		// A 65 - 1 = 64
		// B 66 - 2 = 64
		// C 67 - 3 =  64
		// ...
		triangle += string[i] - 64; 
	}
	return is_triangle_number(triangle);
}

int main() {

	const char *file = "p042_words.txt";
	FILE *fp = fopen(file,"r");
	if (fp) {
		char word[16345];
		int read = fscanf(fp,"%s",word);
		if (read) {
			char *token = strtok(word,",");
			int num_triangle_words = 0;
			while (token != NULL) {
				if (triangle_word(token)) {
					num_triangle_words++;
				}
				token = strtok(NULL,",");
			}
			printf("Number of triangle words = %d\n",num_triangle_words);
		} else {
			printf("No matches\n");
		}
		fclose(fp);
	} else {
		fprintf(stderr,"Failed to open '%s'\n",file); 
	}
	return 0;
}
