#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

#define MAXSIZE 58

void print_matrix(std::vector<std::vector<char>> matrix){       //OK
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){ 
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

class Player{ //canvas[y][x]
public:
    int x; //d: x++  l: x--
    int y; //u
    Player(){
        x = 0; y = 0;
    }
};

int main(){
    DWORD mode;
    HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);

    // 获取终端模式
    GetConsoleMode(hstdin, &mode);
  
    // 设置终端模式，禁用输入缓冲区和回显
    SetConsoleMode(hstdin, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

    vector<vector<char>> canvas;
    Player player;
    for(int i = 0; i < MAXSIZE; i++){
        canvas.push_back({});
        for(int j = 0; j < MAXSIZE; j++)
        canvas[i].push_back(' ');
    }
    canvas[0][0] = '1';

    print_matrix(canvas);

    char command;
    while(1){
        canvas[player.y][player.x] = ' ';
        
        INPUT_RECORD record;
        DWORD numRead;
        ReadConsoleInput(hstdin, &record, 1, &numRead);
        if (record.EventType == KEY_EVENT && record.Event.KeyEvent.bKeyDown) {
        command = record.Event.KeyEvent.uChar.AsciiChar;
        }

        switch (command){ //lurd
            case 'a': player.x--; break;
            case 'w': player.y--; break;
            case 'd': player.x++; break;
            case 's': player.y++; break;
        }

        if(player.x < 0)        player.x++;
        if(player.x >= MAXSIZE) player.x--;
        if(player.y < 0)        player.y++;
        if(player.y >= MAXSIZE) player.y--;

        canvas[player.y][player.x] = '1';
        system("cls");
        print_matrix(canvas);
    }







    return 0;
}