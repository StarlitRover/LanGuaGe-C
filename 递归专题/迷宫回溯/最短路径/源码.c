#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct PathTrack
{
    int x, y;
    struct PathTrack *next;
} ptk;
void createMaze(int length, int width);
void basicSetting(int length, int width);
void markMaze(int **maze, ptk *dst, ptk *src);
void PathTrack(int **maze, ptk *start);
void freeLink(ptk *start);
int main()
{
    int length, width;
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
                maze[i][j] = -1;
            else if (tmp == '-')
                maze[i][j] = 0;
        }
    }
    printf("Now enter the coordinates of start:\n");
    ptk *start = (ptk *)malloc(sizeof(ptk));
    scanf("%d%d", &start->x, &start->y);
    maze[start->x][start->y] = 0;
    start->next = NULL;
    printf("Now enter the coordinates of destination:\n");
    ptk *end = (ptk *)malloc(sizeof(ptk));
    scanf("%d%d", &end->x, &end->y);
    end->next = NULL;
    maze[end->x][end->y] = 1;
    clock_t beginning = clock();
    markMaze(maze, start, end);
    PathTrack(maze, start);
    clock_t ending = clock();
    if (maze[start->x][start->y] == 0)
        fprintf(fp, "\nSo SAD,it's no way!\n");
    else
    {
        fprintf(fp, "\nOne of the shortest Paths:\n");
        for (int i = 0; i < length + 2; ++i)
        {
            for (int j = 0; j < width + 2; ++j)
            {
                if (maze[i][j] == -1)
                    fprintf(fp, "  #  ");
                else if (maze[i][j] >= 0)
                    fprintf(fp, "  -  ");
                else
                    fprintf(fp, "[%03d]", -maze[i][j] - 1);
            }
            fprintf(fp, "\n");
        }
    }
    fprintf(fp, "Elapsed time:%f s", (double)(ending - beginning) / CLOCKS_PER_SEC);
    fclose(fp);
    for (int i = 0; i < length + 2; ++i)
        free(maze[i]);
    free(maze);
    free(start);
    system("pause");
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
void markMaze(int **maze, ptk *dst, ptk *src)
{
    if (src == NULL)
        return;
    ptk *tmp = src, *start = NULL, *new = NULL, *tail = NULL;
    while (tmp)
    {
        int step = maze[tmp->x][tmp->y];
        for (int i = 0; i < 4; ++i)
        {
            int x = tmp->x, y = tmp->y;
            switch (i)
            {
            case 0:
                ++x;
                break;
            case 1:
                ++y;
                break;
            case 2:
                --x;
                break;
            case 3:
                --y;
                break;
            }
            if (maze[x][y] == 0)
            {
                new = (ptk *)malloc(sizeof(ptk));
                new->x = x;
                new->y = y;
                new->next = NULL;
                if (tail != NULL)
                    tail = tail->next = new;
                else
                    tail = start = new;
                maze[x][y] = step + 1;
            }
        }
        tmp = tmp->next;
    }
    freeLink(src);
    if (maze[dst->x][dst->y] != 0)
        return;
    markMaze(maze, dst, start);
}
void PathTrack(int **maze, ptk *start)
{
    int x = start->x, y = start->y;
    int tracker = maze[x][y], step = maze[x][y];
    maze[x][y] = -2;
    while (--tracker)
    {
        if (maze[x + 1][y] == tracker)
            x += 1;
        else if (maze[x][y + 1] == tracker)
            y += 1;
        else if (maze[x - 1][y] == tracker)
            x -= 1;
        else if (maze[x][y - 1] == tracker)
            y -= 1;
        maze[x][y] = -(step - maze[x][y] + 2);
    }
}
void freeLink(ptk *start)
{
    while (start)
    {
        ptk *tmp = start->next;
        free(start);
        start = tmp;
    }
}