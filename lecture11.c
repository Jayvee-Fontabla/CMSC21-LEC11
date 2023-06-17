#include <stdio.h>
#include <stdbool.h> 
// bool 
#include <ctype.h> 
// toupper, isaplha


/*
Function responsible for user input
*/
void scan_word(int occurences[26]){
	char c;
	while ((c = getchar()) != '\n') {
		if (isalpha(c)){
			occurences[toupper(c) - 'A']++;
		}
	}
}

/*
This function checks whether or not the two words are anagrams or not
*/
bool is_anagram(int occurences1[26], int occurences2[26]){
	for (int i = 0; i < 26; i++) {
		if (occurences1[i] != occurences2[i]) {
			printf("The words are not anagrams.\n");
			return false;
		}
	}
	printf("The words are anagrams.\n");
	return true;
}

int main(void) {
	
	int occurences1[26] = {0}, occurences2[26]= {0};
	bool same;

	printf("Enter first word: ");
	scan_word(occurences1);
	printf("Enter second word: ");
	scan_word(occurences2);

	same = is_anagram(occurences1, occurences2);
	return 0;
}