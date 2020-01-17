#include<stdio.h>
#include<string.h>
int decrypt(char[],int);
int main()
{
char str_message[500], ch,encrypt_msg[500];
int j, key;
printf("Enter a message to encrypt: ");
scanf("%s",str_message);
printf("Enter the key: ");
scanf("%d", &key);
for(j = 0; str_message[j] != '\0'; ++j){
ch = str_message[j];
if(ch >= 'a' && ch <= 'z'){ for(int i=0;str_message[i]!='\0';i++)
encrypt_msg[i]=str_message[i];
ch = ch + key;
if(ch > 'z'){
ch = ch - 'z' + 'a' - 1;
}
str_message[j] = ch;
}
else if(ch >= 'A' && ch <= 'Z'){
ch = ch + key;
if(ch > 'Z'){
ch = ch - 'Z' + 'A' - 1;
}
str_message[j] = ch;
}
}
printf("Encrypted message: %s \n", str_message);
for(int i=0;i<strlen(str_message);i++)
encrypt_msg[i]=str_message[i];
printf("Decrypted message:");
decrypt(encrypt_msg,key);
//cryptanalysis
printf("Cryptanalysis");
for(int i=0;i<26;i++)
{
for(int i=0;i<strlen(str_message);i++)
encrypt_msg[i]=str_message[i];
//printf("%s \n ",encrypt_msg);
decrypt(encrypt_msg,i);
}
return 0;
}
int decrypt(char str[20],int key)
{
char ch;
for(int j = 0; str[j] != '\0'; ++j){
ch = str[j];
if(ch >= 'a' && ch <= 'z'){
ch = ch - key;
if(ch < 'a'){
ch = ch + 'z' - 'a' + 1;
}
str[j] = ch;
}
else if(ch >= 'A' && ch <= 'Z'){
ch = ch - key;
if(ch < 'A'){
ch = ch + 'Z' - 'A' + 1;
}
str[j] = ch;
}
}
printf("%s,key=%d \n", str,key);
return 0;
}
