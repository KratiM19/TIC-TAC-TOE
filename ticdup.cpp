#include<iostream>
using namespace std;
int choice;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
bool draw;
int row,coloumn;
void display()
{
	system("cls");
cout<<"\t    T I C   T A C   T O I\n\n";
cout<<"\t\tPlayer1 [X] \n"<<"\t\tPlayer2 [0]\n\n";
cout<<"\t\t\t      |     |     \n";
cout<<"\t\t\t   "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
cout<<"\t\t\t _____|_____|_____\n";
cout<<"\t\t\t      |     |     \n";
cout<<"\t\t\t   "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";   
cout<<"\t\t\t _____|_____|_____\n";
cout<<"\t\t\t      |     |     \n";
cout<<"\t\t\t   "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
cout<<"\t\t\t      |     |     \n\n";
	}
	void player_turn()
	{
		if(turn=='X')
		cout<<"\t\t\tPLAYER 1[X] TURN :";
		if(turn=='o')
		cout<<"\t\t\tPLAYER 2[X] TURN :";
		cin>>choice;
		switch(choice)
		{
		case 1: row=0;coloumn=0;break;
    	case 2: row=0;coloumn=1;break;
    	case 3: row=0;coloumn=2;break;
    	case 4: row=1;coloumn=0;break;
    	case 5: row=1;coloumn=1;break;
    	case 6: row=1;coloumn=2;break;
    	case 7: row=2;coloumn=0;break;
    	case 8: row=2;coloumn=1;break;
    	case 9: row=2;coloumn=2;break;
				default:
    		cout<<"invalid";
    		break;
    	}
    	if(turn=='X'&& board[row][coloumn]!='X'&& board[row][coloumn]!='o')
	{
		board[row][coloumn]='X';
		turn='o';
	}
	else if(turn=='o'&& board[row][coloumn]!='X'&& board[row][coloumn]!='o')
	{
		
		board[row][coloumn]='o';
		turn='X';
	}
	else
	{
		cout<<"invalid choice\n Please select another number";
		player_turn();
	}
			
	}
bool gameover()
{
for(int i=0;i<3;i++)
if(board[0][i]==board[1][i]&&board[0][i]==board[2][i]||board[i][0]==board[i][1]&&board[i][0]==board[i][2])
return false;
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
if(board[i][j]!='X'&&board[i][j]!='o')
return true;
draw='true';
return false;


}
int main()
{
while(gameover())
{
display();
player_turn();
display();
}
if(turn=='X'&&draw==false)
cout<<"PLAYER 2[o] WIN/n CONGRATUTIONS!!!! Game Over";
else if(turn=='o'&&draw==false)
cout<<"PLAYER 1[X] WIN/n CONGRATUTIONS!!!! Game Over";
else
{
	cout<<"GAME DRAW !!!!";
}
}



