#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int number_needed(string a, string b){

  int array[26] = {0}; //tamanho do alfabeto
  
  for(int i = 0; i < (int) a.size(); i++) //indexando e contando tipo countsort
    array[a[i]- 97 ]++;
  
  for(int j = 0; j < (int) b.size(); j++) //indexando e decrementando tipo countsort
    array[b[j]- 97 ]--;
  
  long long int ans = 0;
  
  for(int i = 0; i < 26; i++) //somando todos caracters que apareceram e abs
    ans += abs(array[i]);
  
  return ans;
}

int main(){

	char* a = (char *)malloc(512000 * sizeof(char));
    scanf("%s",a);
    char* b = (char *)malloc(512000 * sizeof(char));
    scanf("%s",b);

    int total=0;
    total = anagram(a, b);
    printf("%d\n", total);
    //printf("%s\n", a);

	return 0;
}