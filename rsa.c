#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(long m,long n)
{
  while(n!=0)
 {
   long r=m%n;
   m=n;
   n=r;
 }
 return m;
} 
int rsa(char message[50])
{
  long p=0,q=0,n=0,e=0,d=0,phi=0;
  long nummes[100]={0};
  long encrypted[100]={0},decrypted[100]={0};
  long i=0,j=0,nofelem=0;
  printf("\n ENter value of p and q\n");
  scanf("%ld%ld",&p,&q);
  n=p*q;
  phi=(p-1)*(q-1);
  for(i=2;i<phi;i++)
  if(gcd(i,phi)==1)
  break;
  e=i;
  for(i=2;i<phi;i++)
  if((e*i-1)%phi==0)
  break;
  d=i;
  for(i=0;i<strlen(message);i++)
  nummes[i]=message[i]-96;
  nofelem=strlen(message);
  for(i=0;i<nofelem;i++)
  {
     encrypted[i]=1;
     for(j=0;j<e;j++)
     encrypted[i]=(encrypted[i]*nummes[i])%n;
  }
 printf("ENcrypted message\n");
 for(i=0;i<nofelem;i++)
 {
    printf("%ld",encrypted[i]);
    printf("%c",(char)(encrypted[i]+96));
 }
 for(i=0;i<nofelem;i++)
 {
    decrypted[i]=1;
    for(j=0;j<d;j++)
    decrypted[i]=(decrypted[i]*encrypted[i])%n;
 }
 printf("Decrypted message\n");
 for(i=0;i<nofelem;i++)
 printf("%c",(char)(decrypted[i]+96));
 return 0;
 }
 int main()
 {
  char msg[100];
  printf("ENter the message to be encrypted\n");
  scanf("%s",msg);
  rsa(msg);
  return;
 }
 

