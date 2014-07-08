#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#define p(x) printf("%s",x);
#define n(x) printf("%d",x);
#define s(x) scanf("%d",&x);
int jogx1[]={0,0,0,0,1,1,1,1,2,2,2,2};
int inix1[]={0,0,0,0,1,1,1,1,2,2,2,2};
int jogy1[]={1,3,5,7,0,2,4,6,1,3,5,7};
int iniy1[]={1,3,5,7,0,2,4,6,1,3,5,7};
int jogz1[]={0,0,0,0,0,0,0,0,0,0,0,0}; 
int jogx2[]={5,5,5,5,6,6,6,6,7,7,7,7};
int inix2[]={5,5,5,5,6,6,6,6,7,7,7,7};
int jogy2[]={0,2,4,6,1,3,5,7,0,2,4,6}; 
int iniy2[]={0,2,4,6,1,3,5,7,0,2,4,6}; 
int jogz2[]={0,0,0,0,0,0,0,0,0,0,0,0}; 
int campo[8][8];
void comeca();
void imprimir();
void inicia(int f1,int f2);
void joga(int jogx[],int jogy[],int x,int m,int vez);
void normal(int jogx[],int jogy[],int x,int m,int vez);
int vere(int jogx[],int jogy[],int x,int m,int vez);
int come(int jogx1[],int jogy1[],int jogx2[],int jogy2[],int m,int x,int vez);
int vence(int *f1,int *f2);

int main(){
int vez,x,v,i,j,m,pass,f1=0,f2=0;
srand(time(NULL));
jogar: 
comeca();
inicia(f1,f2);

for(vez=0;vez < 20;vez++){
v = vence(&f1,&f2);
if(v > 0)
break;

if(vez%2==0){

v: do{
p("jogador: ");
s(x)
if(jogx1[x-1] == -1)
x = 13;
}while(x > 12 || x < 1);

do{
p("mover :\n");
p("1 - esquerda\n");
p("2 - direita\n");
s(m);
}while(m < 1 || m > 2);

joga(jogx1,jogy1,x,m,vez);

if (vere(jogx1,jogy1,x,m,vez) == 0 || come(jogx1,jogy1,jogx2,jogy2,m,x,vez) == 0)
goto v;

} else{
x:
x = rand()%12;
if(jogx2[x] == -1)
goto x;
printf("jog %d ",x+13);

//do{
m = (rand()%2)+1;
printf("pos %d\n",m);
//}while(m < 1 || m > 2);

joga(jogx2,jogy2,x,m,vez);
if (vere(jogx2,jogy2,x,m,vez) == 0 || come(jogx2,jogy2,jogx1,jogy1,m,x,vez) == 0)
goto x;
}
inicia(f1,f2);
}
p("\n\nTIME ");
n(v);
p(" GANHOU\n");
p("vamos jogar novamente ???\n")
p("1 -- SIM\n")
p("2 -- NAO\n")
__fpurge(stdin);
if(getchar() == '1')
goto jogar;

return(0);
}

void imprimir(){
int i,j;
for(i=0;i<8;i++){
   for(j=0;j<8;j++)
      printf("%2d|",campo[i][j]);
printf("\n");
}
}

void inicia(int f1,int f2){
int i,j,w = 1, u = 13;
system("clear");
p("jogadores fora de campo :\n")
printf(" TIME 1: %d\n",f1);
printf(" TIME 2: %d\n",f2);

for(i=0;i<8;i++){
   for(j=0;j<8;j++){
      campo[i][j] = 0;
	}
}

for(j=0;j<12;j++){
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

void  joga(int jogx[],int jogy[],int x,int m,int vez){
int asd,casa = 1,i;
vez = vez%2;
if(vez == 0){
asd = 1;
if(jogz1[x-asd] == -1){
p("quantas casas vai andar ")
s(casa)
}
switch(m){
case 1://esquerda 1
jogx[x-asd] += casa;
jogy[x-asd] -= casa;
break;
case 2://direita 1
jogx[x-asd] += casa;
jogy[x-asd] += casa;
break;
}
}
else{
asd = 0;
if(jogz2[x-asd] == -1)
casa = rand()%5;

switch(m){
case 1://esquerda 2
jogx[x-asd] -= casa;
jogy[x-asd] -= casa;
break;
case 2://direita 2
jogx[x-asd] -= casa;
jogy[x-asd] += casa;
break;
}
}
}

void normal(int jogx[],int jogy[],int x,int m,int vez){
int asd,casa = 1;
vez = vez%2;
if(vez == 0){
asd = 1;
switch(m){
case 1://esquerda 1
jogx[x-asd] -= casa;
jogy[x-asd] += casa;
break;
case 2://direita 1
jogx[x-asd] -= casa;
jogy[x-asd] -= casa;
break;
}
} else{
asd = 0;

switch(m){
case 1://esquerda 2
jogx[x-asd] += casa;
jogy[x-asd] += casa;
break;
case 2://direita 2
jogx[x-asd] += casa;
jogy[x-asd] -= casa;
break;
}
}
}

int vere(int jogx[],int jogy[],int x,int m,int vez){
int pass = 1,i,asd;
vez = vez%2;
if(vez == 0)
asd = 1;
else
asd = 0;
//NAO SAI DO CAMPO
 
if(jogx[x-asd] < 0 || jogx[x-asd] > 7 || jogy[x-asd] < 0 || jogy[x-asd] > 7){
normal(jogx,jogy,x,m,vez);
p("fora do campo\n\n");
pass = 0;
}

//NAO FICA EM CIMA DO AMIGOS

for(i = 0;i < 12; i++){
if((x-asd) != i){
if(jogx[x-asd] == jogx[i] && jogy[x-asd] == jogy[i]){
normal(jogx,jogy,x,m,vez);
p("tem alguem nesta posicao\n\n")
pass = 0;
}  
}
}
return(pass);
}

int come(int jogx1[],int jogy1[],int jogx2[],int jogy2[],int m,int x,int vez){
int i,j,pass = 1;
vez = vez%2;

for(i=0;i<12;i++){
for(j=0;j<12;j++){
if(jogx1[i] ==  jogx2[j] &&  jogy1[i] == jogy2[j]){
if(vez == 0){
if(campo[jogx1[i]+1][jogy1[i]-1] == 0 && m == 1){
jogx1[i]++;
jogy1[i]--;
jogx2[j]= -1;
}else if(campo[jogx1[i]+1][jogy1[i]+1] == 0 && m == 2){
jogx1[i]++;
jogy1[i]++;
jogx2[j]= -1;
}else{
normal(jogx1,jogy1,x,m,vez);
p("nao pode comer este !!!")
pass = 0;
}
} else{
if(campo[jogx1[i]-1][jogy1[i]-1] == 0 && m == 1){
jogx1[i]--;
jogy1[i]--;
jogx2[j]= -1;
}else if(campo[jogx1[i]-1][jogy1[i]+1] == 0 && m == 2){
jogx1[i]--;
jogy1[i]++;
jogx2[j]= -1; 
}else{
normal(jogx1,jogy1,x,m,vez);
p("nao pode comer este !!!")
pass = 0;
}
}
}
}
}
return(pass);
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
if(*f1 == 1)
t = 2;
else if(*f2 == 1)
t = 1;
else
t = 0;

return(t);
}

void comeca(){
int i;
for(i=0;i<12;i++){
jogx1[i] = inix1[i];
jogx2[i] = inix2[i];
jogy1[i] = iniy1[i];
jogy2[i] = iniy2[i];
jogz1[i] = 0;
jogz2[i] = 0;
}
}
