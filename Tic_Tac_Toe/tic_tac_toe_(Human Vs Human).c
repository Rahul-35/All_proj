#include<stdio.h>
#include<stdlib.h>
char matrix[3][3];
char check();
void init_matrix();
void get_player1_move();
void get_player2_move();
void disp_matrix();
int main()
{
        char done;
       printf("************WELCOME TO THE GAME OF TIC TAC TOE*****************\n");
        printf("PLAYER-1 will be playing against against PLAYER-2.\n");
        done=' ';
        init_matrix();
        do{
                disp_matrix();
                get_player1_move();
                done=check();
               if(done!=' ') break;
                disp_matrix();
		get_player2_move();
                done=check();
        }while(done==' ');
        if(done=='X')printf("\n*************PLAYER-1 WON!!!********************\n");
	else if(done=='O') printf("\n**********PLAYER-2 WON!!!*********\n");
	else printf("\n*********MATCH DRAWN**********\n");
        disp_matrix();
        return(0);
}
void init_matrix()
{
        int i,j;
        for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                        matrix[i][j]=' ';
        }
}
void get_player1_move()
{
   
               int x,y;
        printf("Enter X,Y coordinates for your move PLAYER-1: ");
        scanf("%d%*c%d",&x,&y);
        x--;
        y--;
        if(matrix[x][y]!=' '){
                printf("Invalid move,try again.\n");
                get_player1_move();
        }
        else
                matrix[x][y]='X';
}
void get_player2_move()
{

               int x,y;
        printf("Enter X,Y coordinates for your move PLAYER-2: ");
        scanf("%d%*c%d",&x,&y);
        x--;
        y--;
        if(matrix[x][y]!=' '){
                printf("Invalid move,try again.\n");
                get_player2_move();
        }
        else
                matrix[x][y]='O';
}

void disp_matrix()
{
        int t;
        for(t=0;t<3;t++){
                printf(" %c | %c | %c ",matrix[t][0],matrix[t][1],matrix[t][2]);
                if(t!=2)
                        printf("\n---|---|---\n");
        }
        printf("\n");

}
char check()
{
        int i;
        for(i=0;i<3;i++)
	{
                if(matrix[i][0]==matrix[i][1] && matrix[i][1]==matrix[i][2])
                        return matrix[i][0];
	}
        for(int j=0;j<3;j++)
	{       if(matrix[0][j]==matrix[1][j] && matrix[1][j]==matrix[2][j])
                        return matrix[0][j];
}
	if(matrix[0][0]==matrix[1][1] && matrix[0][i]==matrix[2][2])
                        return matrix[0][0];
	if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
                        return matrix[0][2];

}
