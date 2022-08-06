#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct PathTrack
{
    struct PathTrack *pre;
    int x, y;
    struct PathTrack *next;
} ptk;
void createMaze(int length, int width);
void basicSetting(int length, int width);
int PathSearch(ptk *start, int **maze);
ptk *addPath(ptk *start, int sgn);
ptk *withdrawPath(ptk *start);
int main()
{
    int length, width,flag;
    printf("Enter the length and width of maze:\n");
    scanf("%d%d", &length, &width);
    basicSetting(length, width);
    FILE *fp = fopen("maze.txt", "a+");
    int **maze = (int **)malloc((length + 2) * sizeof(int *));
    for (int i = 0; i < length + 2; ++i)
        maze[i] = (int *)malloc((width + 2) * sizeof(int));
    for (int i = 0; i < length + 2; ++i)
    {
        for (int j = 0; j < width + 2; ++j)
        {
            char tmp;
            fscanf(fp, " %c ", &tmp);
            if (tmp == '#')
                maze[i][j] = -2;
            else if (tmp == '-')
                maze[i][j] = 0;
        }
    }
    printf("Now enter the coordinates of start:\n");
    int startx, starty;
    scanf("%d%d", &startx, &starty);
    maze[startx][starty] = 0;
    printf("Now enter the coordinates of destination:\n");
    int endx, endy;
    scanf("%d%d", &endx, &endy);
    maze[endx][endy] = -1;
    ptk *start = (ptk *)malloc(sizeof(ptk));
    start->x = startx;
    start->y = starty;
    start->pre = NULL;
    start->next = NULL;
    clock_t beginning = clock();
    flag = PathSearch(start, maze);
    clock_t ending = clock();
    if (flag == -1)
        fprintf(fp, "\nSo SAD,it's no way!");
    else
    {
        int cnt = 1;
        ptk *tmp = start;
        while (tmp)
        {
            maze[tmp->x][tmp->y] = cnt++;
            tmp = tmp->next;
        }
        fprintf(fp, "\nOne Path:\n");
        for (int i = 0; i < length + 2; ++i)
        {
            for (int j = 0; j < width + 2; ++j)
                if (maze[i][j] == -2)
                    fprintf(fp, "  #  ");
                else if (maze[i][j] == -3 || maze[i][j] == 0)
                    fprintf(fp, "  -  ");
                else
                    fprintf(fp, "[%03d]", maze[i][j]);
            fprintf(fp, "\n");
        }
    }
    fprintf(fp, "Elapsed time:%f s", (double)(ending - beginning)/CLOCKS_PER_SEC);
    while (start)
    {
        ptk *cup = start->next;
        free(start);
        start = cup;
    }
    for (int i = 0; i < length + 2; ++i)
        free(maze[i]);
    free(maze);
    fclose(fp);
}
void createMaze(int length, int width)
{
    FILE *fp = fopen("maze.txt", "w");
    printf("Enter the ratio of barrier to blank:\n");
    float ratio;
    scanf("%f", &ratio);
    for (int i = 0; i < length + 2; ++i)
    {
        for (int j = 0; j < width + 2; ++j)
        {
            if (i == 0 || i == length + 1 || j == 0 || j == width + 1)
                fprintf(fp, " # ");
            else
            {
                int flag = rand() % 100;
                if (flag < ratio * 100)
                    fprintf(fp, " # ");
                else
                    fprintf(fp, " - ");
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}
void basicSetting(int length, int width)
{
    int flag;
    printf("Enter 1 if Maze is ready,or enter other key\n");
    scanf("%d", &flag);
    if (flag != 1)
    {
        srand(time(0));
        do
        {
            createMaze(length, width);
            printf("Created successfully!\n");
            printf("Enter 1 if you want to reset the maze,\
or enter 0.\n");
            scanf("%d", &flag);
        } while (flag);
        printf("Now you can amend the maze in maze.txt.\n");
        system("pause");
    }
}
int PathSearch(ptk *start, int **maze)
{
    int flag;
    if (start->pre == NULL && maze[start->x][start->y] == -3)
        return -1;
    else if (maze[start->x][start->y] == -1)
        return 1;
    maze[start->x][start->y] = -3;
    if (maze[start->x + 1][start->y] > -2)
        flag = PathSearch(addPath(start, 1), maze);
    else if (maze[start->x][start->y + 1] > -2)
        flag = PathSearch(addPath(start, 2), maze);
    else if (maze[start->x - 1][start->y] > -2)
        flag = PathSearch(addPath(start, 3), maze);
    else if (maze[start->x][start->y - 1] > -2)
        flag = PathSearch(addPath(start, 4), maze);
    else if (start->pre == NULL)
        return -1;
    else
        flag = PathSearch(withdrawPath(start), maze);
    return flag;
}
ptk *addPath(ptk *start, int sgn)
{
    ptk *new = (ptk *)malloc(sizeof(ptk));
    int x = start->x, y = start->y;
    switch (sgn)
    {
    case 1:
        x += 1;
        break;
    case 2:
        y += 1;
        break;
    case 3:
        x -= 1;
        break;
    case 4:
        y -= 1;
        break;
    }
    new->x = x;
    new->y = y;
    new->pre = start;
    new->next = NULL;
    start->next = new;
    return new;
}
ptk *withdrawPath(ptk *start)
{
    ptk *cup = start->pre;
    start->pre->next = NULL;
    free(start);
    return cup;
}