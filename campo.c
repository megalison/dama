#include <stdio.h>

int main(){
char cam[16][16];
int i,j;
for(i =0;i<16;i++){
    for(j=0;j<16;j++){
        cam[i][j] = 32;
        cam[0][j] = '=';
        cam[15][j] = '=';
        cam[i][0] = '|';
        cam[i][15] = '|';
}
}

for(i =0;i<16;i++){
    for(j=0;j<16;j++){
        printf("%c",cam[i][j]);
}
printf("\n");
}
}

