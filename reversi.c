#include <stdio.h>
#define SIZE 8

typedef enum {WHT=-1, EMP=0, BLK=+1, OUT=+2} Piece;

Piece cell[SIZE][SIZE];

//----盤面の初期化
void init(void)
{
    int i, j;
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            cell[i][j] = BLK; 
        }
    }
    cell[4][4] = cell[3][3] = EMP;
    cell[3][4] = cell[4][3] = BLK;
}
    
//----盤面の出力
void output(void) 
{
    int i, j;
    
    printf("  x0x1x2x3x4x5x6x7\n");
    
    for(i = 0; i < SIZE; i++) {
        printf("y%d", i);
        for(j = 0; j < SIZE; j++) {
            switch (cell[i][j]) {
                case WHT : printf("●"); break;
                case BLK : printf("〇"); break;
                case EMP : printf("・"); break;
            }
        }
        printf("\n");
    }
}

//----入力処理
void input(int player)
{
    int x, y; //xが横 yが縦 cell[y][x]とやる
    
    while (1){
        printf("x:"); scanf("%d", &x);
        printf("y:"); scanf("%d", &y);
        if (x >= SIZE || y >= SIZE || x < 0 || y < 0) { 
            printf("正しい数を入力してください\n");
            continue;
        }
        break;
    }
    
    cell[y][x] = player;
    
}

//----終了判定
int endCheck(void)
{
    int i, j;
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if ( cell[j][i] == EMP) {
                return 1;
            }
        }
    }
    return 0;
}

//----勝利判定
void winCheck(void)
{
    int i, j;
    int b = 0, w = 0;
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if ( cell[j][i] == BLK ) {
                b++;
            }
            if ( cell[j][i] == WHT ) {
                w++;
            }
        }
    }
    
    if ( b > w ) {
        printf("黒の勝ち");
    } else if ( w > b ) {
        printf("白の勝ち");
    } else {
        printf("引き分け");
    }
}

//----メイン関数
int main(void)
{
    int player = BLK;
    
    init();
    while (1) {
        output();
        input(player);
        if ( endCheck() == 0 ) {
            output();
            break;
        }
        player *= -1;
    }
    
    winCheck();
    return 0;
}
