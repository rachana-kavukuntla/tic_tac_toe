#include<iostream>
#include<cstdlib>
using namespace std;
char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
class temp
{
public:
int i,j;
//This fuction displays the TIC TAC TOE board 
void board()
{
    for(int i=0;i<3;i++)
    {

        for(int j=0;j<3;j++)
        {
            cout<<a[i][j];
            if(j!=2)
            {
               // char c="|";
                cout<<"|";
            }
        }
        cout<<endl;
        if(i==1||i==0)
        {
            for(int c=0;c<5;c++)
            cout<<"-";
            cout<<endl;
        }

    }
}
//Checks whether the position is empty to enter players choice.
//If the position is not empty,game will ask the player to enter another index.
int check_pos(int k, char m)
{

        int i,j;
        i = k/3;
        j= (k % 3)-1;
        if(a[i][j] == 'O' || a[i][j] == 'X'|| k<1 || k>9 && k!=0)
        {    
            int l;
            cout<<"\n Invalid \n Enter another index"<<endl;
            cin>>l; 
            check_pos(l,m);
        }
        else
            a[i][j]=m;
        
}
//Inserting the X or O in players choice index.
//Also checks whether a player wins or Game is a DRAW.
void insert()
{
    int k,player;temp t;
    int count=0;
    while(1)
    {   
        count++;
        if(count==1)
        cout<<"Enter 0 to exit";
        cout<<endl<<"   Player-1"<<endl;
        cout<<"Enter the index"<<endl;
        cin>>k;
        if(k==0)
        {
            system("clear");
            cout<<"\t\t  OUT OF THE GAME  \t\t"<<endl;
            mainmenu();
        }
        else
        {   
            check_pos(k,'X');
            system("clear");
            t.heading();
            cout<<"\t\tIf you want to quit the game, Enter '0'\t\t"<<endl;
            board();
    
            if(count >4 && !win())
            {
                    cout<<endl<<endl<<"DRAW"<<endl<<endl;
                    break;
            }
            if(win())
            {
                   system("clear");
			//clrscr();
                    cout<<endl<<endl<<"\t  GAME OVER \n\t PLAYER 1 WINS"<<endl<<endl;
                break;
            }
            
        
        }
        cout<<endl<<"   PLAYER-2"<<endl;
        cout<<"Enter the index"<<endl;
        cin>>k;
        if(k==0)
        {
            system("clear");
            cout<<"\t\t  OUT OF THE GAME  \t\t"<<endl;
            mainmenu();
        }
        else
        {   
            check_pos(k,'O');
            system("clear");
            t.heading();
            cout<<"\t\tIf you want quit the game, Enter '0'\t\t"<<endl;
            board();
            if(count > 4 && !win()) 
            {
                    cout<<endl<<"DRAW"<<endl;
                    break;
            }
            if(count >4||win())
            {
                    system("clear");
                    cout<<endl<<endl<<"\t  GAME OVER \n \t PLAYER 2 WINS"<<endl<<endl;
                    break;
            }
            
        }
    }
}

int win()
{
    for(i=0;i<3;i++)
    {
    if(a[i][0]==a[i][1]&&a[i][1]==a[i][2])
        return 1;
    for(j=0;j<3;j++)
        if(a[0][j]==a[1][j]&&a[1][j]==a[2][j])
            return 1;
    if(a[0][0]==a[1][1]&&a[1][1]==a[2][2])
        return 1;
    else if(a[0][2]==a[1][1]&&a[1][1]==a[2][0])
        return 1;
    else
        return 0;
    }
}
//heading of the game is given.
//char for each player is given.
void heading()
{
    cout<<"\t\t***** TIC TAC TOE *****"<<endl<<endl;
    cout<<"\t   $$$$$ PLAYER1-X N PLAYER2-O $$$$$"<<endl<<endl;


}
int mainmenu()
{
    temp t;int option1,option2,option3;
    t.heading();
    cout<<"\t\t*****MAIN MENU*****"<<endl;
    cout<<" 1.NEW GAME"<<endl;
    cout<<" 2.QUIT "<<endl;
    cin>>option1;
    system("clear");
    if(option1==1)
    {
        heading();
        cout<<"\t\t***** NEW GAME ***** "<<endl;
            system("clear");
            t.heading();
            board();
            t.insert();
    }
    else if(option1==2)
    {
        heading();
        cout<<"DO YOU WANT TO QUIT THE GAME"<<endl;
        cout<<"1.YES"<<endl<<"2.NO"<<endl;
        cin>>option3;
        if(option3==1)
        {
                system("clear");
                cout<<"\t\t\t       OUT OF GAME       \t\t\t"<<endl;
                exit(0);

        }
        else
        {
                system("clear");
                t.mainmenu();

        }

    }
}
};
int main()
{
    temp t;
    
    t.mainmenu();
    return 0;
}

