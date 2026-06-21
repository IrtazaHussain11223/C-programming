//#include <iostream>
//#include <windows.h>
//#include <conio.h>
//#include<ctime>
//#include<cstdlib>
//
//using namespace std;
//
//
//const int screenWidth = 80;
//const int screenHeight = 24;
//int shipPositionX = screenWidth / 4;
//int shipPositionY = screenHeight - 2;
//int score = 0;
//char screen[screenHeight][screenWidth];
//int enemy[screenHeight][screenWidth];
//int lives = 5;
//char alienChar = 254;//aliens character
//int framecounter = 0;
//HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//struct Bullet
//{
//    int x, y;
//    bool active = false;
//};
//
//// Max at once
//const int maxBullets = 10;
//Bullet bullets[maxBullets];
//
//
//
//void HideCursor()
//{
//    CONSOLE_CURSOR_INFO cursorInfo;
//    cursorInfo.dwSize = 100;
//    cursorInfo.bVisible = FALSE;
//    SetConsoleCursorInfo(hStdOut, &cursorInfo);
//}
//
//void SetColor(int code)
//{
//    SetConsoleTextAttribute(hStdOut, code);
//}
//
//
//void Clear()
//{
//    for (int y = 0; y < screenHeight; y++)
//    {
//        for (int x = 0; x < screenWidth; x++)
//        {
//            screen[y][x] = ' ';
//        }
//    }
//}
//
////void enemycolor()
////{
//  //  int color = rand() % 15 + 1;
//    //SetConsoleTextAttribute(hStdOut, color);
////}
//void DrawScreen()
//{
//    //for cursor
//    COORD pos = { 0, 0 };
//    SetConsoleCursorPosition(hStdOut, pos);
//    Clear();
//
//    screen[shipPositionY][shipPositionX] = char(202);
//    for (int i = 0; i < maxBullets; i++)
//    {
//        if (bullets[i].active)
//        {
//            screen[bullets[i].y][bullets[i].x] = '^'; // Bullet
//        }
//    }
//
//
//
//    for (int y = 0; y < screenHeight; y++)
//    {
//        for (int x = 0; x < screenWidth; x++)
//        {
//            if (enemy[y][x] == 1)
//            {
//                SetColor(14);
//                cout << alienChar;
//
//            }
//            else if (screen[y][x] == char(202))
//            {
//                SetColor(2);
//                cout << char(202);
//            }
//            else if (screen[y][x] == '^')
//            {
//                SetColor(12);
//                cout << "^";
//            }
//
//            else
//            {
//                SetColor(7);
//                cout << screen[y][x];
//            }
//        }
//
//        if (y == 0)
//        {
//            SetColor(5);
//            cout << "   Score: " << score << "  Lives: " << lives;
//        }
//
//        cout << endl;
//    }
//}
//
//
//void ProcessInput()
//{
//    if (_kbhit())
//    {
//        char ch = _getch();
//        if (ch == 'a' || ch == 75)
//        { // Left
//            if (shipPositionX > 0)
//                shipPositionX--;
//        }
//        else if (ch == 'd' || ch == 77)
//        { // Right
//            if (shipPositionX < (screenWidth / 2) - 1)
//                shipPositionX++;
//        }
//        else if (ch == 32)
//        {
//            for (int i = 0; i < maxBullets; i++)
//            {
//                if (!bullets[i].active)
//                {
//                    bullets[i].x = shipPositionX;
//                    bullets[i].y = shipPositionY - 1;
//                    bullets[i].active = true;
//                    break;
//                }
//            }
//        }
//        else if (ch == 27)
//        {
//            score = 0;
//            lives = 5;
//            framecounter = 0;
//            shipPositionX = screenWidth / 4;
//        }
//    }
//}
//void Bullets()
//{
//    for (int i = 0; i < maxBullets; i++)
//    {
//        if (bullets[i].active)
//        {
//            bullets[i].y--;
//            if (bullets[i].y < 0)
//                bullets[i].active = false; // remove bullets
//        }
//    }
//}
//
//void Cross()
//{
//    for (int i = 0; i < screenWidth; i++)
//    {
//        if (enemy[screenHeight - 2][i] == 1)
//        {
//            lives--;
//            enemy[screenHeight - 2][i] = 0;
//
//            if (lives <= 0)
//            {
//                system("cls");
//                SetColor(3);
//                cout << endl << endl << endl;
//                cout << "           .................................................." << endl;
//                cout << "           .................................................." << endl;
//                cout << "           . .                                 " << char(254) << "          . ." << endl;
//                cout << "           . .                                            . ." << endl;
//                cout << "           . .         Game Over! You lost all lives      . ." << endl;
//                cout << "           . .                                            . ." << endl;
//                cout << "           . .    Press 'R' to continue or 'Q' to quit    . ." << endl;
//                cout << "           . .                                            . ." << endl;
//                cout << "           . .                                 " << char(15) << "           . ." << endl;
//                cout << "           . .                                 " << char(202) << "          . ." << endl;
//                cout << "           .................................................." << endl;
//                cout << "           .................................................." << endl;
//                cout << endl << endl;
//
//
//                char choice;
//                do
//                {
//                    choice = _getch();
//                    if (choice == 'R' || choice == 'r')
//                    {
//                        lives = 5;
//                        score = 0;
//                        system("cls");
//                        framecounter = 0;
//                        return;
//                    }
//                    else if (choice == 'Q' || choice == 'q')
//                    {
//                        system("cls");
//                        cout << endl << endl << endl;
//                        SetColor(3);
//                        cout << "           .................................................." << endl;
//                        cout << "           .................................................." << endl;
//                        cout << "           . .                                 " << char(254) << "          . ." << endl;
//                        cout << "           . .                                            . ." << endl;
//                        cout << "           . .                                            . ." << endl;
//                        cout << "           . .          Thanks for playing! Goodbye!      . ." << endl;
//                        cout << "           . .                                            . ." << endl;
//                        cout << "           . .                                            . ." << endl;
//                        cout << "           . .                                 " << char(15) << "           . ." << endl;
//                        cout << "           . .                                 " << char(202) << "          . ." << endl;
//                        cout << "           .................................................." << endl;
//                        cout << "           .................................................." << endl;
//                        cout << endl << endl;
//                        Sleep(100);
//
//                        exit(0);
//                    }
//
//                } while (true);
//
//            }
//
//        }
//    }
//}
//int spawnenemyY()
//{
//    const int width = (80 / 2) - 1;
//    return rand() % width;
//}
//
//// function for spawn
//
////function for movement
//
//
//void moveenemydown()
//{
//    for (int i = screenHeight - 2; i >= 0; i--)//reverse loop to move down i.e it starts from 2 last row 
//    {
//        for (int j = 0; j < screenWidth; j++)//starts from first colume
//        {
//            if (enemy[i][j] == 1)//checks for presence of enemy to move down
//            {
//                if (i + 1 == screenHeight - 1)//it checks weahther if the enemy has moved to 2 last row if it has it sets it to 0 and when it is checked in furthur part of code 0 prints nothing and it removes the enemy 
//                {
//                    enemy[i][j] = 0;
//                }
//                else
//                {
//                    enemy[i + 1][j] = 1;//this moves enemy down by giving the next row and same colume 1 and previos one 0
//                    enemy[i][j] = 0;
//                }
//            }
//
//        }
//    }
//}
//
//
////function for collision
//
//
//void Collision()
//{
//    for (int i = 0; i < maxBullets; i++)
//    {
//        if (bullets[i].active)
//        {
//            int a = bullets[i].x;
//            int b = bullets[i].y;
//
//            if (b >= 0 && enemy[b][a] == 1)
//            {
//                bullets[i].active = false;
//                enemy[b][a] = 0;
//                score += 10;
//            }
//        }
//    }
//}
//void win()
//{
//    int target = 10;
//    if (score >= target)
//    {
//        system("cls");
//        SetColor(10);
//        cout << endl << endl << endl;
//        cout << "           .................................................." << endl;
//        cout << "           .................................................." << endl;
//        cout << "           . .                                 " << char(254) << "          . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .         Congratulations! You Won!          . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .        Press 'R' to Restart or 'Q' to Quit . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                 " << char(15) << "           . ." << endl;
//        cout << "           . .                                 " << char(202) << "          . ." << endl;
//        cout << "           .................................................." << endl;
//        cout << "           .................................................." << endl;
//        cout << endl << endl;
//
//        char choice;
//        do
//        {
//            choice = _getch();
//            if (choice == 'R' || choice == 'r')
//            {
//                score = 0;
//                lives = 5;
//
//                system("cls");
//                return;
//            }
//            else if (choice == 'Q' || choice == 'q')
//            {
//                system("cls");
//                SetColor(7);
//                cout << "\n\n\n";
//                cout << "           .................................................." << endl;
//                cout << "           .................................................." << endl;
//                cout << "           . .                                 " << char(254) << "          . ." << endl;
//                cout << "           . .                                            . ." << endl;
//                cout << "           . .                                            . ." << endl;
//                cout << "           . .          Thanks for Playing! Goodbye!      . ." << endl;
//                cout << "           . .                                            . ." << endl;
//                cout << "           . .                                            . ." << endl;
//                cout << "           . .                                 " << char(15) << "           . ." << endl;
//                cout << "           . .                                 " << char(202) << "          . ." << endl;
//                cout << "           .................................................." << endl;
//                cout << "           .................................................." << endl;
//                cout << "\n\n\n";
//                Sleep(1000);
//                exit(0);
//            }
//        } while (true);
//    }
//}
//
//
//
//int main()
//{
//
//    HideCursor();
//
//    for (int i = 0; i < 5; i++)
//    {
//        SetConsoleTextAttribute(hStdOut, i);
//        system("cls");
//        cout << endl << endl << endl;
//        cout << "           .................................................." << endl;
//        cout << "           .................................................." << endl;
//        cout << "           . .                                 " << char(254) << "          . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                Space Shooter               . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                 " << char(15) << "           . ." << endl;
//        cout << "           . .                                 " << char(202) << "          . ." << endl;
//        cout << "           .................................................." << endl;
//        cout << "           .................................................." << endl;
//        cout << endl << endl;
//        Sleep(100);
//
//        SetConsoleTextAttribute(hStdOut, i + 1);
//        system("cls");
//        cout << endl << endl << endl;
//        cout << "           .................................................." << endl;
//        cout << "           .................................................." << endl;
//        cout << "           . .                                 " << char(254) << "          . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                Space Shooter               . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                 " << char(15) << "           . ." << endl;
//        cout << "           . .                                 " << char(202) << "          . ." << endl;
//        cout << "           .................................................." << endl;
//        cout << "           .................................................." << endl;
//        cout << endl << endl;
//        Sleep(100);
//
//        SetConsoleTextAttribute(hStdOut, i + 2);
//        system("cls");
//        cout << endl << endl << endl;
//        cout << "           .................................................." << endl;
//        cout << "           .................................................." << endl;
//        cout << "           . .                                 " << char(254) << "          . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                Space Shooter               . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                 " << char(15) << "           . ." << endl;
//        cout << "           . .                                 " << char(202) << "          . ." << endl;
//        cout << "           .................................................." << endl;
//        cout << "           .................................................." << endl;
//        cout << endl << endl;
//        Sleep(100);
//
//        SetConsoleTextAttribute(hStdOut, i + 4);
//        system("cls");
//        cout << endl << endl << endl;
//        cout << "           .................................................." << endl;
//        cout << "           .................................................." << endl;
//        cout << "           . .                                 " << char(254) << "          . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                Space Shooter               . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                            . ." << endl;
//        cout << "           . .                                 " << char(15) << "           . ." << endl;
//        cout << "           . .                                 " << char(202) << "          . ." << endl;
//        cout << "           .................................................." << endl;
//        cout << "           .................................................." << endl;
//        cout << endl << endl;
//        Sleep(100);
//    }
//    SetConsoleTextAttribute(hStdOut, 3);
//    cout << char(254) << " ";
//    Sleep(1000);
//    SetConsoleTextAttribute(hStdOut, 2);
//    cout << char(254) << " ";
//    cout << "Press any key to continue... \n";
//    _getch();
//
//    int speed = 0;
//    char level = '\0';
//    SetColor(10);
//    cout << "Which level do you want to select\n";
//    SetColor(7);
//    cout << "1 for Easy\n";
//    SetColor(9);
//    cout << "2 for Medium\n";
//    SetColor(12);
//    cout << "3 for Difficult\n";
//    cin >> level;
//    while (level != '1' && level != '2' && level != '3')
//    {
//        cout << "Enter valid choice";
//        cin >> level;
//    }
//    if (level == '1')
//        speed = 1000;
//    if (level == '2')
//        speed = 700;
//    if (level == '3')
//        speed = 500;
//    int posX = 0, posY = 0;
//
//    srand(time(0));
//    framecounter = 0;
//
//
//
//    SetConsoleTextAttribute(hStdOut, 14);
//    system("cls");
//
//    cout << endl << endl;
//    cout << "****************** INSTRUCTIONS ******************\n";
//    cout << "\n";
//    cout << "1. Use arrow keys to move your spaceship (" << char(202) << ").\n";
//    cout << "2. Press 'space' to shoot bullets.\n";
//    cout << "3. Destroy all aliens.\n";
//    cout << "4. You have 20 lives to finish the game.\n";
//    cout << "5. Press esc to reset the score and lives.\n";
//    cout << "\n";
//    cout << "**************************************************\n";
//    cout << "Press any key to start the game... \n";
//    _getch();
//
//    SetConsoleTextAttribute(hStdOut, 7); //default color
//
//a:
//
//    while (true)
//    {
//        DrawScreen();
//        ProcessInput();
//        Bullets();
//
//        if (framecounter < speed)
//        {
//            int posY = spawnenemyY();
//            enemy[0][posY] = 1;
//            framecounter++;
//        }
//        moveenemydown();
//        Collision();
//        Cross();
//        win();
//
//
//
//
//    }
//
//
//    return 0;
//}