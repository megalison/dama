
// LINHA 187...


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define p(x) printf("%s",x);
#define n(x) printf("%d",x);
#define s(x) scanf("%d",&x);
int jogx1[]={0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
int jogy1[]={0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7};
int jogz1[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
int jogx2[]={6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7};
int jogy2[]={0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7}; 
int jogz2[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
int campo[8][8];
void imprimir();
void inicia(int f1,int f2);
void normal(int jogx[],int jogy[],int x,int m,int vez);
int vere(int jogx[],int jogy[],int x,int m,int vez);
void joga(int jogx[],int jogy[],int x,int m,int vez);
int come(int jogx1[],int jogy1[],int jogx2[],int jogy2[],int m,int x,int vez);
void dama();
int main(){
int vez,x,i,j,m,pass,v;
int f1 = 0,f2 = 0;
srand(time(NULL));

for(vez=0;m = -1;vez++){
inicia(f1,f2);
if(vez%2==0){
do{
do{
p("X : ");
s(x)
if(jogx1[x-1] == -1)
x = 0;
}while(x > 16 || x < 1);
pass = 1;
do{
p("mover :\n");
p("1 - cima\n");
p("2 - baixo\n");
p("3 - esquerda\n");
p("4 - direita\n");
s(m);
}while(m < 1 || m > 4);

joga(jogx1,jogy1,x,m,vez);

if(vere(jogx1,jogy1,x,m,vez) == 0 || come(jogx1, jogy1, jogx2,jogy2,m,x,vez) == 0)
pass = 0;

}while(pass == 0);
dama();
v = vence(&f1,&f2);
if(v >  0)
break;
}
else{
do{
v:
do{
x = rand()%16;
if(jogx2[x] == -1)
x = 0;
}while(x > 16 || x < 1);
do{
m = rand()%4;
}while(m < 1 || m > 4);

joga(jogx2,jogy2,x,m,vez);

if(vere(jogx2,jogy2,x,m,vez) == 0 || come(jogx2, jogy2, jogx1,jogy1,m,x,vez) == 0)
goto v;
}while(pass == 0);
dama();
v = vence(&f1,&f2);
if(v >  0)
break;
}
}
system("clear");
printf("O TIME %d GANHOU \n",v);
p("ATE A PROXIMA VEZ\n")
return(0);
}

void inicia(int f1,int f2){
int i,j,w=1,u=17;
system("clear");
p("jogadores fora de campo :\n")
printf(" TIME 1: %d\n",f1);
printf(" TIME 2: %d\n",f2);

for(i=0;i<8;i++){
   for(j=0;j<8;j++){
      campo[i][j] = 0;
	}
}

for(j=0;j<16;j++){
if(jogz1[j] == -1)
campo[jogx1[j]][jogy1[j]] = w+100;
else
campo[jogx1[j]][jogy1[j]] = w;
if(jogz2[j] == -1)
campo[jogx2[j]][jogy2[j]] = u+100;
else
campo[jogx2[j]][jogy2[j]] = u;
u++;
w++;
}

imprimir();
}

void imprimir(){
int i,j;
for(i=0;i<8;i++){
   for(j=0;j<8;j++)
      printf("%2d|",campo[i][j]);
printf("\n");
}
}

void normal(int jogx[],int jogy[],int x,int m,int vez){
int asd;
vez %= 2;
if(vez == 0)
asd = 1;
else
asd = 0;

switch(m){
case 1:
jogx[x-asd]++;
break;
case 2:
jogx[x-asd]--;
break;
case 3:
jogy[x-asd]++;
break;
case 4:
jogy[x-asd]--;
break;
}
}

int vere(int jogx[],int jogy[],int x,int m,int vez){
int pass = 1,i,asd;
vez = vez%2;
if(vez == 0)
asd = 1;
else
asd = 0;

if(jogx[x-asd] < 0||jogx[x-asd] > 7||jogy[x-asd] < 0||jogy[x-asd] > 7){
normal(jogx,jogy,x,m,vez);
p("fora do campo\n\n");
pass = 0;
}
for(i = 0;i < 16; i++){
if((x-asd) != i){
if(jogx[x-asd] == jogx[i] && jogy[x-asd] == jogy[i]){
normal(jogx,jogy,x,m,vez);
pass = 0;
}  
}
}
return(pass);
}

void joga(int jogx[],int jogy[],int x,int m,int vez){
int asd,casa = 1,i;
vez = vez%2;
if(vez == 0){
asd = 1;
if(jogz1[x-asd] == -1){
p("quantas casas vai andar ")
s(casa)
}
}
else{
asd = 0;
if(jogz2[x-asd] == -1)
casa = rand()%5;
}
/*for(i=0;i<casa;i++)
if(jogx[x-asd]+i
*/
switch(m){
case 1:
jogx[x-asd]-= casa;
break;
case 2:
jogx[x-asd]+=casa;
break;
case 3:
jogy[x-asd]-=casa;
break;
case 4:
jogy[x-asd]+=casa;
break;
}
}

int come(int jogx1[],int jogy1[],int jogx2[],int jogy2[],int m,int x,int vez){
int i,j,pass = 1;
vez = vez%2;

for(i=0;i<16;i++){
for(j=0;j<16;j++){
if(jogx1[i] ==  jogx2[j] &&  jogy1[i] == jogy2[j]){
if(vez == 0){
if(m == 2 && campo[jogx1[i]+1][jogy1[i]] == 0){
jogx1[i]++;
jogx2[j]= -1;
} else{
normal(jogx1,jogy1,x,m,vez);
pass = 0;
}
} else{
if(m == 1 && campo[jogx1[i]-1][jogy1[i]] == 0){
jogx1[i]--;
jogx2[j]=-1;
} else{
normal(jogx1,jogy1,x,m,vez);
pass = 0;
}
}
}
}
}
return(pass);
}

void dama(){
int i;
for(i=0;i<16;i++){
if(jogx1[i] == 7)
jogz1[i] = -1;
if(jogx2[i] == 0)
jogz2[i] = -1;
}
}

int vence(int *f1,int *f2){
int i,t,t2 = 0,t1 = 0;

for(i = 0;i < 16;i++){
if(jogx1[i] == -1) 
t1++;
if(jogx2[i] == -1)
t2++;
}
*f1 = t1;
*f2 = t2;
if(*f1 == 3)
t = 2;
else if(*f2 == 3)
t = 1;
else
t = 0;

return(t);
}

 
























