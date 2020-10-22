#include <stdio.h>

int main(){

char ptv[30000] = {0};
int ptr = 0;
ptr += 1;
ptv[ptr]+=8;
while(ptv[ptr]){
ptv[ptr] -= 1;
ptr -= 1;
ptv[ptr]+=9;
ptr += 1;
}
ptr -= 1;
putchar(ptv[ptr]);
ptr += 2;
ptv[ptr]+=1;
ptr += 1;
ptv[ptr] -= 1;
while(ptv[ptr]){
ptv[ptr]+=1;
}
ptv[ptr]+=2;
ptr += 1;
ptv[ptr]+=2;
ptr += 1;
ptv[ptr]+=3;
while(ptv[ptr]){
ptr += 1;
while(ptv[ptr]){
ptv[ptr] -= 1;
ptr += 1;
ptv[ptr]+=3;
ptr -= 2;
ptv[ptr]+=3;
ptr += 1;
}
ptr -= 2;
}
ptr += 1;
ptv[ptr] -= 5;
putchar(ptv[ptr]);
ptr += 1;
ptv[ptr] -= 1;
ptr += 1;
ptv[ptr]+=3;
putchar(ptv[ptr]);
putchar(ptv[ptr]);
ptv[ptr]+=3;
putchar(ptv[ptr]);
ptr += 1;
ptv[ptr] -= 1;
putchar(ptv[ptr]);
ptr -= 2;
ptv[ptr]+=1;
while(ptv[ptr]){
ptr += 1;
while(ptv[ptr]){
ptv[ptr]+=1;
ptr += 1;
ptv[ptr]+=1;
}
ptr += 2;
}
ptr -= 1;
ptv[ptr] -= 14;
putchar(ptv[ptr]);
ptr += 2;
putchar(ptv[ptr]);
ptv[ptr]+=3;
putchar(ptv[ptr]);
ptv[ptr] -= 6;
putchar(ptv[ptr]);
ptv[ptr] -= 8;
putchar(ptv[ptr]);
ptr += 1;
ptv[ptr]+=1;
putchar(ptv[ptr]);
ptr += 1;
ptv[ptr]+=1;
putchar(ptv[ptr]);

}