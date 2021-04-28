import random
N = 3
grid = [['.']*N for _ in range(N)]
elements = ['1','2','3','4','5','6','7','8',' ']
def clear_grid():
    for i in range(N):
        for j in range(N):
            grid[i][j] = '.'
def set_elements():
    z = 0
    for i in range(N):
      for j in range(N):
        while grid[i][j] == '.':
          x = random.randint(0, 2)
          y = random.randint(0, 2)
          if grid[x][y] == '.':
             grid[x][y] = elements[z]
             z +=1
def print_grid():
    print('--' + '---' * (N+2) + '--')
    for i in range(N):
        for j in range(N):
            print(end='|  ')
            print(grid[i][j], end='  ')
        print(end='|')
        print()
        print('--' + '---' * (N+2) + '--')
def valid_move(i,j,i2,j2):
    if((abs(i - i2) == 1 and j == j2) or (abs(j - j2) == 1 and i == i2) and (grid[i2][j2] == ' ')):
        return True
    return False
def valid_index(i,j,i2,j2):
    if(i >= 0 and i < 3 and i2 >= 0 and i2 < 3 and j >= 0 and j < 3 and j2 >= 0 and j2 < 3):
        return True
    return False
def move_elements(i,j,i2,j2):
    grid[i2][j2] = grid[i][j]
    grid[i][j] = ' '
def check_win():
   x = 0
   for i in range(N):
       for j in range(N):
           if(grid[i][j] != elements[x]):
            return False
           x+=1
   return True
def read_input(i,j,i2,j2):
    i, j, i2, j2 = map(int, input("Enter a move: ").split())
    while(not valid_move(i,j,i2,j2) or  not valid_index(i,j,i2,j2)):
       i, j, i2, j2 = map(int, input("Enter a valid move: ").split())
    return i,j,i2,j2
def play():
    print("8-puzzle Game")
    while(True):
        print()
        print_grid()
        i,j,i2,j2 = 0,0,0,0
        i,j,i2,j2 = read_input(i,j,i2,j2)
        move_elements(i,j,i2,j2)
        if(check_win()):
            print_grid()
            print("YOU WIN..!")
            break
while (True):
    clear_grid()
    set_elements()
    play()
    c = input("Play Again [Y/N]")
    if not c == 'y' and not c == 'Y':
        break
