#include <bits/stdc++.h>
using namespace std;
const int N = 3;
char grid[N][N];
char elements[9] = {'1','2','3','4','5','6','7','8',' '};
void clear_grid()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            grid[i][j] = '.';
        }
    }
}
bool check_full()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j] == '.')
                return false;
        }
    }
    return true;
}
void set_elements()
{
    int x = 0;
    srand(time(0));
    while(!check_full())
    {
         int i = rand() % 3;
         int j = rand() % 3;
         if(grid[i][j] == '.')
         {
             grid[i][j] = elements[x];
             x++;
         }
    }
}
void print_grid() {
    cout << "--";
    for (int i = 0; i < N+2; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            cout << "|  ";
            cout << grid[i][j] << "  ";
        }
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < N+2; cout << "---", i++);
        cout << "--\n";
    }
}
bool valid_move(int i,int j,int i2,int j2)
{
    if((abs(i - i2) == 1 && j == j2) || (abs(j - j2) == 1 && i == i2) && (grid[i2][j2] == ' '))
        return true;
    return false;
}
bool valid_index(int i,int j, int i2,int j2)
{
    if(i >= 0 && i < 3 && i2 >= 0 && i2 < 3 && j >= 0 && j < 3 && j2 >= 0 && j2 < 3)
        return true;
    return false;
}
void move_elements(int i,int j,int i2,int j2)
{
    grid[i2][j2] = grid[i][j];
    grid[i][j] = ' ';
}
bool check_win()
{
   int x = 0;
   for(int i = 0; i < N; i++)
   {
       for(int j = 0; j < N; j++)
       {
           if(grid[i][j] != elements[x])
            return false;
           x++;
       }
   }
   return true;
}
int read_input(int &i, int &j, int &i2, int &j2)
{
    cout<<"Enter a move: ";
    cin>>i>>j>>i2>>j2;
    while(!valid_move(i,j,i2,j2) || !valid_index(i,j,i2,j2))
    {
        cout<<"Enter a valid move: ";
        cin>>i>>j>>i2>>j2;
    }
}
void play()
{
    cout<<"8-puzzle Game"<<endl;
    while(true)
    {
        print_grid();
        int i,j,i2,j2;
        read_input(i,j,i2,j2);
        move_elements(i,j,i2,j2);
        if(check_win())
        {
            print_grid();
            cout<<"YOU WIN..!"<<endl;
            break;
        }
    }
}
int main()
{
    while (true)
    {
        clear_grid();
        set_elements();
        play();
        char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
