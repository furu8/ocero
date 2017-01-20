#include <stdio.h>
#define SIZE 8

typedef enum {WHT=-1, EMP=0, BLK=+1, OUT=+2} Piece;

Piece cell[SIZE][SIZE];

void init(void)
{
    int i, j;
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            cell[i][j] = EMP; 
        }
    }
    cell[4][4] = cell[3][3] = WHT;
    cell[3][4] = cell[4][3] = BLK;
}
    
void output(void) 
{
    int i, j;
    
    printf("  x0x1x2x3x4x5x6x7\n");
    
    for(i = 0; i < SIZE; i++) {
        printf("y%d", i);
        for(j = 0; j < SIZE; j++) {
            switch (cell[i][j]) {
                case WHT : printf("œ"); break;
                case BLK : printf("Z"); break;
                case EMP : printf("E"); break;
            }
        }
        printf("\n");
    }
}

void input(int player)
{
    int x, y; //x‚ª‰¡ y‚ªc cell[y][x]‚Æ‚â‚é
    
    while (1){
        printf("x:"); scanf("%d", &x);
        printf("y:"); scanf("%d", &y);
        if (x >= SIZE || y >= SIZE || x < 0 || y < 0) { 
            printf("³‚µ‚¢”‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
            continue;
        }
        break;
    }
    
    cell[y][x] = player;
    
}

int last(void)
{
    int i, j, x, y;
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if ( cell[y][x] == EMP) {
                return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    int player = BLK;
    
    init();
    while (last) {
        output();
        input(player);
        player *= -1;
    }
    
    return 0;
}
