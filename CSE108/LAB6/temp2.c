#include <stdio.h>



void printtable(char arr[26][26])
{
int i = 0,j = 0, k = 0;
for(i = 0;i < 26; i++)
{
for(j = 0; j < 26; j++) //plaintext-keystream alphabet table initialization with two for loops
{
printf("%c ",arr[i][j]);
}
printf("\n");
}
}



int encrypt(char arr[26][26], char a){}
int decrypt(){}



int main()
{
    long double a;
char arr[26][26]; //plaintext- keystream table
char row[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int i = 0,j = 0, k = 0;
for(i = 0;i < 26; i++)
{
for(j = i,k = 0; j < i || k < 26; j++, k++) //plaintext-keystream alphabet table initialization with two for loops
{
if(j == 26)
j = 0;
arr[i][k] = row[j];
}
}
printtable(arr);
char plaintext[257];
char key[257];
char ciphertext[257];
printf("Enter the plaintext: ");
for(char c = getchar(), i = 0; c != '\n'; i++)
{
plaintext[i] = c;
printf("%c",plaintext[i]);
c = getchar();
}
printf("Enter the plaintext: ");
for(char c = getchar(), i = 0; c != '\n'; i++)
{
plaintext[i] = c;
printf("%c",plaintext[i]);
c = getchar();
printf("a");
}
//-----------------------------------------------------------------------------------------------------
int textlen = 0, keylen = 0;
i = 0;
while(plaintext[i]){ //getting the lengths so that we can know which one is longer
textlen++;
printf("%d\n", textlen);}
i = 0;
while(plaintext[i])
keylen++;



if(keylen > textlen)
{
key[textlen] = '\0';
}
else if(keylen < textlen)
{
for(j = keylen, i = 0; i < keylen && j < textlen; j++, i++) //j is for text, i is for key.
{
plaintext[j] = key[i];
if(i == keylen -1)
i = 0;
}
}



return 0;
}