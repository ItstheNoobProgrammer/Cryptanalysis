#include<bits/stdc++.h>
using namespace std;
const int a = 17;
const int b = 20;

string encryptMessage(string msg)
{
string cipher = "";
for (int i = 0; i < msg.length(); i++)
{
if(msg[i]!=' ')
cipher = cipher +
(char) ((((a * (msg[i]-'A') ) + b) % 26) + 'A');
else
cipher += msg[i];
}
return cipher;
}

void decryptCipher(string cipher)
{
for(int j=0;j<26;j++){
for(int k=0;k<26;k++)
{
string msg = "";
int a_inv = 0;
int flag = 0;
for (int i = 0; i < 26; i++)
{
flag = (j * i) % 26;
if (flag == 1)
{
a_inv = i;
}
}
for (int i = 0; i < cipher.length(); i++)
{
if(cipher[i]!=' ')
msg = msg +
(char) (((a_inv * ((cipher[i]+'A' - k)) % 26)) + 'A');
else
msg += cipher[i];
}
cout<<msg<<"\t"<<j<<"\t"<<k<<endl;
}}
//return 0;
}

int main(void)
{
string msg = "AFFINE";
string cipherText = encryptMessage(msg);
//cout << "Message is : " << msg<<endl;
//cout << "Encrypted Message is : " << cipherText<<endl;
//cout << "Decrypted Message is: " << decryptCipher(cipherText);
cout<<"Cryptanalysis Part"<<endl;
decryptCipher(cipherText);
return 0;
}
