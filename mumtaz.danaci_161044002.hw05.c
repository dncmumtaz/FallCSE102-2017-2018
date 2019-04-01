#include <stdio.h>
typedef enum {white_man, black_man, white_king, black_king, empty} piece;
typedef enum {white = 10, black = 20} player;
void init_board(piece board[][8]);
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
//int check_end_of_game(piece board[][8]);
void display_board(piece board[][8]);
//void sample_game_1();
//void sample_game_2();

int main (){
    
    int from_x, from_y, to_x, to_y;
    int represent;
    
    piece board[8][8];
    player p;
    init_board(board);
   
    represent = move(board, from_x, from_y, to_x, to_y, p);
   
 
    return (0) ; 
}

void init_board(piece board[][8]){ /* this funtion generate tablo of game.*/
    
    int i, j;

    for( i = 0 ; i < 8 ; i++){  /*first row*/
        board[0][i] = empty;
     }
     
     for( i = 1 ; i < 3 ; i++){  /* second and third row*/
         for( j = 0 ; j < 8 ; j++){
             board[i][j] = black_man;         
         }
     }
     
     for( i = 3 ; i < 5 ; i++){    /* 4th and 5th row*/
         for( j = 0 ; j < 8 ; j++){
             board[i][j] = empty;
         }
     }
     


     for( i = 5 ; i < 7 ; i++){      /* 6th and 7th row*/
         for( j = 0 ; j < 8 ; j++){
             board[i][j] = white_man;
         }
     }
     
     for( i = 0 ; i < 8 ; i++){  /* last row*/
        board[7][i] = empty;
     }
}

int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){
   
  
    int temp_whitex, temp_whitey;
    int  exit = 0;                /*the general exit condition*/
    int controla = 1 , controlb = 1 , controlc = 1;
    int control2a = 1, control2b = 1, control2c = 1;
    int option1 = 0, option2 = 0;
    int last_movex, last_movey;
    int count = 0;
    printf("white must start to game .\n");
    p = white;
    
    temp_whitex = 7;
    temp_whitey = 7;
   
    while(  exit == 0 ){
           
        while( p == white && exit == 0  ){
           
            if(count!=0){           
                   temp_whitex = last_movex;
                   temp_whitey = last_movey;
               }
               option2 = 1;
               while( board[temp_whitex-1][temp_whitey] == 'b' && board[temp_whitex-2][temp_whitey] == '_' ||
            board[temp_whitex][temp_whitey-1] == 'b' && board[temp_whitex][temp_whitey-2] == '_' ||
            board[temp_whitex][temp_whitey+1] == 'b' && board[temp_whitex][temp_whitey+2] == '_' ){
               
                   if(controla != 0 && controlb != 0 && controlc != 0 ){
                    if( board[temp_whitex-1][temp_whitey] == 'b' && board[temp_whitex-2][temp_whitey] == '_' ){
                        printf("white have to play otomaticly!\n");
                        board[temp_whitex][temp_whitey] = empty;
                        board[temp_whitex-2][temp_whitey] = white_man;
                        board[temp_whitex+1][temp_whitey] = empty;
                        
                        last_movex = temp_whitex;
                        if(temp_whitex != 1 && temp_whitex != 0)
                            temp_whitex -= 2;
                        
                        if(board[temp_whitex-1][temp_whitey] == 'b' && board[temp_whitex-2][temp_whitey] == '_'){
                            controla = 0;    
                        }
                 
                    }           
                    
                    if( board[temp_whitex][temp_whitey-1] == 'b' && board[temp_whitex][temp_whitey-2] == '_'){
                        printf("white have to play otomaticly!\n"); 
                        board[temp_whitex][temp_whitey-1] = empty;
                        board[temp_whitex][temp_whitey-2] = white_man;
                        board[temp_whitex][temp_whitey] = empty;
                        
                        last_movey = temp_whitey;
                        if(temp_whitey != 1 && temp_whitey != 0)
                            temp_whitey -= 2;
                            
                        if(board[temp_whitex][temp_whitey-1] == 'b' && board[temp_whitex][temp_whitey-2] == '_'){
                            controlb = 0;
                        }
                        
                    }
                    if( board[temp_whitex][temp_whitey+1] == 'b' && board[temp_whitex][temp_whitey+2] == '_' ){
                        printf("white have to play otomaticly!\n");
                        board[temp_whitex][temp_whitey+1] = empty;
                        board[temp_whitex][temp_whitey+2] = white_man;
                        board[temp_whitex][temp_whitey] = empty;
                        
                        last_movey = temp_whitey;
                        if(temp_whitey != 7 && temp_whitey != 8)
                            temp_whitey += 2;
                        if(board[temp_whitex][temp_whitey+1] == 'b' && board[temp_whitex][temp_whitey+2] == '_'){
                            controlc = 0;
                        }
                        
                    }
                    option2 = 0;
                    p = black;
                }
            }     
                
           
        
            if(option2  == 1){
                printf("Where from? First x axis then y axis : ");
                scanf("%d",&from_x);
                scanf("%d",&from_y);
        
                printf("to where ? first x axis then y axis : ");
                scanf("%d",&to_x);
                scanf("%d",&to_y);
                
                if( board[to_x][to_y] != 'w' && board[to_x][to_y] != 'b'){
                                       
                    board[from_x][from_y] = empty ;        
                    board[to_x][to_y] = white_man ;   
                    p = black;          
                }                                                                  
                
                else{
                    exit = 1;
                       printf("wrong touching , game over fool \n");                
                }
                last_movex = temp_whitex;
                last_movey = temp_whitey;
                
       
            }
            display_board(board);
            printf("Turn is Black!\n");
             
                
                   
         
        }
         printf("------------------------------------");
         temp_whitex = last_movex;
		    temp_whitey = last_movey;
		    printf("%d,     %d",temp_whitex, temp_whitey);
        
		    
   
		       
         
                
        while( exit == 0 && p == black && temp_whitex < 7){
        
        	
            
            option1 = 1;
            
             
           
		       
		    
            
            while( board[temp_whitex+1][temp_whitey] == 'w' && board[temp_whitex+2][temp_whitey] == '_'
             || board[temp_whitex][temp_whitey-1] == 'w' && board[temp_whitex][temp_whitey-2] == '_' ||
            board[temp_whitex][temp_whitey+1] == 'w' && board[temp_whitex][temp_whitey+2] == '_'  ){        
              
                if( control2a != 0 && control2b != 0 && control2c != 0 ) { 
                            
                
                    if(board[temp_whitex+1][temp_whitey] == 'w' && board[temp_whitex+2][temp_whitey] == '_'  ){
                        printf("Black have to play otomaticly!\n");
                        board[temp_whitex+1][temp_whitey] = empty;
                        board[temp_whitex+2][temp_whitey] = black_man;
                        board[temp_whitex][temp_whitey] = empty;
                        
                        last_movex = temp_whitex;
                        if(temp_whitex != 6 && temp_whitex != 7 )
                            temp_whitex +=2;
                        if(board[temp_whitex-1][temp_whitey] == 'b' && board[temp_whitex-2][temp_whitey] == '_')
                            control2a = 0;    
                    }
                    if(board[temp_whitex+1][temp_whitey] == 'w' && board[temp_whitex+2][temp_whitey] == '_' ){
                        printf("Black have to play otomaticly!\n");
                        board[temp_whitex][temp_whitey-1] = empty;
                        board[temp_whitex][temp_whitey-2] = black_man;
                        board[temp_whitex][temp_whitey] = empty;
                        
                        last_movey = temp_whitey;
                        if(temp_whitey != 1 && temp_whitey != 0)
                            temp_whitey -= 2;
                        if(board[temp_whitex+1][temp_whitey] == 'w' && board[temp_whitex+2][temp_whitey] == '_' )
                        control2b = 0;    
                    }
                    if(board[temp_whitex][temp_whitey+1] == 'w' && board[temp_whitex][temp_whitey+2] == '_'){
                        printf("Black have to play otomaticly!\n");
                        board[temp_whitex][temp_whitey+1] = empty;
                        board[temp_whitex][temp_whitey+2] = black_man;
                        board[temp_whitex][temp_whitey] = empty;
                    
                        last_movey = temp_whitey;
                        if(temp_whitey != 6 && temp_whitey != 7)
                            temp_whitey += 2;
                    }
                    if(board[temp_whitex][temp_whitey+1] == 'w' && board[temp_whitex][temp_whitey+2] == '_')
                    
                    control2c = 0;
                }
                option1 = 0;
            }
            
           
   
        
                if( board[to_x][to_y] != 'w' && board[to_x][to_y] != 'b'){
                          
                   
                    board[from_x][from_y] = empty ;        
                    board[to_x][to_y] = black_man ; 
                
                  
                }
            
                   else{
                    exit = 1;
                       printf("wrong touching , game over fool \n");
                }
                last_movex = to_x ;
                last_movey = to_y ;                
            }
                printf("Turn is white! \n");
                p = white;       
           }
        display_board(board);
        count++;
     }    
    
      

}

int check_end_of_game(piece board[][8]){
    
    int i,j;
    int total_white =0, total_black =0;
    
    for( i = 0 ; i < 8 ; i++ ){
        for( j = 0 ; j < 8 ; j++){
            if(board[i][j] == white )
                total_white++;
            if( board[i][j] == black )
                total_black++;                
        }
    }
    
    if( total_white != 0 && total_black != 0)
        return -1;
    if( total_white == 0 )
        return black;
    if( total_black == 0 )
        return white;

}
void display_board(piece board[][8]){   /* this funtion display the *pull* of game*/
    
    int i, j, controller;
    
    for( i = 0 ; i < 8 ; i++){      /* this loop control desing of game */
        for( j = 0 ; j < 8 ; j++){
            controller = board[i][j];
            if( controller == 0){
                board[i][j] = 'w' ; /*the enum statements*/
            }
            else if( controller == 1){  /*the enum statements*/
                board[i][j] = 'b';    
            }
            else if( controller == 2){  /*the enum statements*/
                board[i][j] = 'W';
            }
            else if ( controller == 3){    /*the enum statements*/
                board[i][j] = 'B';
            }
            else if(controller == 4)
                board[i][j] = '_';  /*the enum statements*/
            printf("%c", board[i][j]); 
        }
        printf("\n");
        
    }
}

    

//void sample_game_1();
//void sample_game_2();


