//#include <iostream>
//using namespace std;
//
//void process(char**& p, const int& n, const int& m, char p1[][100])
//{
//    int count = 0;
//    for (int i = 0; i < n; i++)
//    {
//       for (int j = 0; j < m; j++)
//       {
//       if (p1[i][j] == '#')
//       {
//       count++;
//       }
//       }
//    }
//
//    p = new char* [count];
//    count = 0;
//
//    int row = 0;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (p1[i][j] == '#')
//            {
//                int b = j + 1;
//                for (int k = 0; p1[i][b] != '#' && p1[i][b] != '\0'; k++)
//                {
//                    count++;
//                    b++;
//                }
//
//                char temp[100];
//                int f = 0;
//                int index = j + 1;
//
//                for (; p1[i][index] != '#' && p1[i][index] != '\0' && p1[i][index] != ' '; index++)
//                {
//                    temp[f] = p1[i][index];
//                    f++;
//                }
//                temp[f] = '\0';
//
//                bool isDuplicate = false;
//                for (int t = 0; t < row; t++)
//                {
//                    int u;
//                    for (u = 0; p[t][u] == temp[u] && p[t][u] != '\0' && temp[u] != '\0'; u++);
//                    if (p[t][u] == '\0' && temp[u] == '\0')
//                    {
//                        isDuplicate = true;
//                        break;
//                    }
//                }
//                if (isDuplicate || f == 0)
//                {
//                    continue;
//                }
//
//                p[row] = new char[count + 1];
//                count = 0;
//                b = 0;
//                if (row > n)
//                {
//                    break;
//                }
//                b = j + 1;
//                int r = 0;
//                for (int k = 0; p1[i][b] != '#' && p1[i][b] != '\0'; k++)
//                {
//                    p[row][r] = p1[i][b];
//                    cout << p[row][r];
//                    r++;
//                    b++;
//                }
//                cout << endl;
//                p[row][r] = '\0';
//                row++;
//            }
//        }
//    }
//}
//
//int main()
//{
//    const int N = 20;
//    const int M = 100;
//    char array[N][M] =
//    {
//        "I love programming! #coding #developer #tech",
//        "Just read a great book about AI! #reading #AI #books",
//        "The weather today is fantastic! #sunny #beautiful",
//        "Had an amazing workout session! #fitness #health #motivation",
//        "Finally, coffee time! #coffee #morning #energy",
//        "Learning C programming! #coding #learning",
//        "Can't wait for the weekend! #weekendvibes #excited",
//        "Enjoying a relaxing day at the beach! #vacation #beach #relax",
//        "New project starting today! #work #project #goals",
//        "Running in the park! #fitness #nature",
//        "Loving this tech conference! #tech #developer #AI",
//        "Weekend vibes and relaxation time! #weekendvibes #vacation #relax",
//        "Fitness goals achieved today! #fitness #health #motivation",
//        "Finally got my first coffee today! #coffee #morning #energy",
//        "Building a new app with C! #coding #developer",
//        "Taking a walk at the beach. #beach #vacation #nature",
//        "Just finished an AI course! #AI #learning #tech",
//        "Work is so rewarding today! #work #project #goals",
//        "A morning walk to clear my mind! #morning #fitness #nature",
//        "Amazing sunny day! #sunny #beautiful #weekendvibes"
//    };
//
//    char** ptr = NULL;
//    process(ptr, N, M, array);
//    for (int i = 0; i < N; i++)
//    {
//        delete[] * (ptr + i);
//    }
//    delete[] ptr;
//
//}
