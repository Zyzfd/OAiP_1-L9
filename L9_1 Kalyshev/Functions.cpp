#include "Functions.h"

#define N 10
#define M 15

int a[N][M] = {
{ 3, 0, 1, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 2,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 2,   4, 0, 0, 0, 0,   0, 2, 0, 0, 0 },
{ 0, 0, 0, 0, 2,   2, 2, 2, 2, 2,   0, 2, 0, 0, 0 },

{ 0, 0, 0, 0, 0,   0, 0, 0, 4, 2,   0, 2, 0, 0, 0 },
{ 0, 0, 1, 0, 0,   0, 0, 0, 0, 2,   0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0,   0, 1, 0, 0, 0,   0, 2, 0, 0, 0 },
{ 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 2, 4, 0, 0 },
{ 0, 0, 1, 0, 1,   0, 0, 0, 0, 0,   0, 2, 0, 0, 0 }
};

int steps = 0;
int gold = 0;
int step = 0;
int moster_eaten = 0;

void moveToLeft() {
    int i, j;
    i = 0;
    while (i < N) {
        j = 1;
        while (j < M) {
            if (a[i][j] == 3) {
                if (a[i][j - 1] == 0) {
                    a[i][j - 1] = 3;
                    a[i][j] = 0;
                    steps++;
                }
                else if (a[i][j - 1] == 1) {
                    a[i][j - 1] = 3;
                    a[i][j] = 0;
                    steps++;
                    gold++;
                }
                else if (a[i][j - 1] == 4) {
                    if (gold > 4) {
                        a[i][j - 1] = 3;
                        a[i][j] = 0;
                        steps++;
                        gold++;
                    }
                    else {
                        a[i][j] = 0;
                        steps++;
                    }
                }
            }
            j++;
        }
        i++;
    }
}

void moveToRight() {
    int i = 0;
    while (i < N) {
        int j = M - 2;
        while (j >= 0) {
            if (a[i][j] == 3) {
                if (a[i][j + 1] == 0) {
                    a[i][j + 1] = 3;
                    a[i][j] = 0;
                    steps++;
                }
                else if (a[i][j + 1] == 1) {
                    a[i][j + 1] = 3;
                    a[i][j] = 0;
                    steps++;
                    gold++;
                }
                else if (a[i][j + 1] == 4) {
                    if (gold > 4) {
                        a[i][j + 1] = 3;
                        a[i][j] = 0;
                        steps++;
                        gold++;
                        moster_eaten = 1;
                    }
                    else {
                        a[i][j] = 0;
                        steps++;
                    }
                }
            }
            j--;
        }
        i++;
    }
}

void moveUp() {
    int i = 1;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                if (a[i - 1][j] == 0) {
                    a[i - 1][j] = 3;
                    a[i][j] = 0;
                    steps++;
                }
                else if (a[i - 1][j] == 1) {
                    a[i - 1][j] = 3;
                    a[i][j] = 0;
                    steps++;
                    gold++;
                }
                else if (a[i - 1][j] == 4) {
                    if (gold > 4) {
                        a[i - 1][j] = 3;
                        a[i][j] = 0;
                        steps++;
                        gold++;
                        moster_eaten = 1;
                    }
                    else {
                        a[i][j] = 0;
                        steps++;
                    }
                }
            }
            j++;
        }
        i++;
    }
}

void moveDown() {
    int i = N - 2;
    while (i >= 0) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                if (a[i + 1][j] == 0) {
                    a[i + 1][j] = 3;
                    a[i][j] = 0;
                    steps++;
                }
                else if (a[i + 1][j] == 1) {
                    a[i + 1][j] = 3;
                    a[i][j] = 0;
                    steps++;
                    gold++;
                }
                else if (a[i + 1][j] == 4) {
                    if (gold > 4) {
                        a[i + 1][j] = 3;
                        a[i][j] = 0;
                        steps++;
                        gold++;
                        moster_eaten = 1;
                    }
                    else {
                        a[i][j] = 0;
                        steps++;
                    }
                }
            }
            j++;
        }
        i--;
    }
}

int sizeX = 36;
int sizeY = 30;

void DrawField(HDC hdc) {

    HBRUSH hBrushEmptyCell; //создаЄм кисть дл€ пустого пол€
    hBrushEmptyCell = CreateSolidBrush(RGB(200, 200, 200)); // серый

    HBRUSH hBrushGold; //создаЄм кисть дл€ пол€ с золотом
    hBrushGold = CreateSolidBrush(RGB(255, 255, 0)); // желтый

    HBRUSH hBrushWall; //создаЄм кисть дл€ стены
    hBrushWall = CreateSolidBrush(RGB(0, 0, 0)); // черный

    HBRUSH hBrushMan; //создаЄм кисть дл€ игрока
    hBrushMan = CreateSolidBrush(RGB(0, 0, 255)); // синий

    HBRUSH hBrushMonster; //создаЄм кисть дл€ игрока
    hBrushMonster = CreateSolidBrush(RGB(255, 0, 0)); // синий

    int i, j;
    i = 0;
    while (i < N) {
        j = 0;
        while (j < M) {
            RECT rect = { j * sizeX,i * sizeY,  (j + 1) * sizeX,(i + 1) * sizeY };
            if (a[i][j] == 0) {
                FillRect(hdc, &rect, hBrushEmptyCell);
            }
            else if (a[i][j] == 1) {
                FillRect(hdc, &rect, hBrushGold);
            }
            else if (a[i][j] == 2) {
                FillRect(hdc, &rect, hBrushWall);
            }
            else if (a[i][j] == 3) {
                FillRect(hdc, &rect, hBrushMan);
            }
            else if (a[i][j] == 4) {
                FillRect(hdc, &rect, hBrushMonster);
            }
            else {
                // тут никогда не должны оказатьс€
            }
            j++;
        }
        i++;
    }

    HFONT hFont;
    hFont = CreateFont(20,
        0, 0, 0, 0, 0, 0, 0,
        DEFAULT_CHARSET,
        0, 0, 0, 0,
        L"Courier New"
    );
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(0, 128, 128));

    TCHAR  string1[] = _T("сделано ходов:");
    TCHAR  string2[] = _T("собрано золота:");
    TextOut(hdc, 10, sizeY * (N + 1), (LPCWSTR)string1, _tcslen(string1));
    TextOut(hdc, 10, sizeY * (N + 1) + 20, (LPCWSTR)string2, _tcslen(string2));

    char sSteps[5];
    TCHAR  tsSteps[5];
    sprintf(sSteps, "%d", steps);
    OemToChar(sSteps, tsSteps);
    TextOut(hdc, 220, sizeY * (N + 1), (LPCWSTR)tsSteps, _tcslen(tsSteps));

    char sGold[5];
    TCHAR  tsGold[5];
    sprintf(sGold, "%d", gold);
    OemToChar(sGold, tsGold);
    TextOut(hdc, 220, sizeY * (N + 1) + 20, (LPCWSTR)tsGold, _tcslen(tsGold));

    DeleteObject(hFont);
    DeleteObject(hBrushEmptyCell);
    DeleteObject(hBrushGold);
    DeleteObject(hBrushWall);
    DeleteObject(hBrushMan);

} // конец функции void DrawField(HDC hdc) 


void newWallLeft() {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                if (j != 0) {
                    a[i][j - 1] = 2;
                }
            }
            j++;
        }
        i++;
    }
}

void newWallRight() {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                if (j != M - 1) {
                    a[i][j + 1] = 2;
                }
            }
            j++;
        }
        i++;
    }
}

void newWallUp() {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                if (i != 0) {
                    a[i - 1][j] = 2;
                }
            }
            j++;
        }
        i++;
    }
}

void newWallDown() {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                if (i != N - 1) {
                    a[i + 1][j] = 2;
                }
            }
            j++;
        }
        i++;
    }
}

void destroyWallRight() {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                j++;
                while (j < M) {
                    if (a[i][j] == 2) {
                        a[i][j] = 0;
                    }
                    j++;
                }
            }
            j++;
        }
        i++;
    }
}

void destroyWallLeft() {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                j--;
                while (j >= 0) {
                    if (a[i][j] == 2) {
                        a[i][j] = 0;
                    }
                    j--;
                }
                break;
            }
            j++;
        }
        i++;
    }
}

void destroyWallAround() {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                if (i - 1 < 0 and j - 1 < 0) {
                    if (a[i + 1][j] == 2) {
                        a[i + 1][j] = 0;
                    }
                    if (a[i + 1][j + 1] == 2) {
                        a[i + 1][j + 1] = 0;
                    }
                    if (a[i][j + 1] == 2) {
                        a[i][j + 1] = 0;
                    }
                }

                else if (i - 1 < 0 and j + 1 > M - 1) {
                    if (a[i + 1][j] == 2) {
                        a[i + 1][j] = 0;
                    }
                    if (a[i + 1][j - 1] == 2) {
                        a[i + 1][j - 1] = 0;
                    }
                    if (a[i][j - 1] == 2) {
                        a[i][j - 1] = 0;
                    }
                }

                else if (i + 1 > N - 1 and j - 1 < 0) {
                    if (a[i - 1][j] == 2) {
                        a[i - 1][j] = 0;
                    }
                    if (a[i - 1][j + 1] == 2) {
                        a[i - 1][j + 1] = 0;
                    }
                    if (a[i][j + 1] == 2) {
                        a[i][j + 1] = 0;
                    }
                }

                else if (i + 1 > N - 1 and j + 1 > M - 1) {
                    if (a[i - 1][j] == 2) {
                        a[i - 1][j] = 0;
                    }
                    if (a[i - 1][j - 1] == 2) {
                        a[i - 1][j - 1] = 0;
                    }
                    if (a[i][j - 1] == 2) {
                        a[i][j - 1] = 0;
                    }
                }

                else if (i - 1 < 0) {
                    if (a[i + 1][j] == 2) {
                        a[i + 1][j] = 0;
                    }
                    if (a[i + 1][j + 1] == 2) {
                        a[i + 1][j + 1] = 0;
                    }
                    if (a[i][j + 1] == 2) {
                        a[i][j + 1] = 0;
                    }
                    if (a[i + 1][j - 1] == 2) {
                        a[i + 1][j - 1] = 0;
                    }
                    if (a[i][j - 1] == 2) {
                        a[i][j - 1] = 0;
                    }
                }

                else if (i + 1 > N - 1) {
                    if (a[i - 1][j] == 2) {
                        a[i - 1][j] = 0;
                    }
                    if (a[i - 1][j + 1] == 2) {
                        a[i - 1][j + 1] = 0;
                    }
                    if (a[i][j + 1] == 2) {
                        a[i][j + 1] = 0;
                    }
                    if (a[i - 1][j - 1] == 2) {
                        a[i - 1][j - 1] = 0;
                    }
                    if (a[i][j - 1] == 2) {
                        a[i][j - 1] = 0;
                    }
                }

                else if (j - 1 < 0) {
                    if (a[i - 1][j] == 2) {
                        a[i - 1][j] = 0;
                    }
                    if (a[i - 1][j + 1] == 2) {
                        a[i - 1][j + 1] = 0;
                    }
                    if (a[i][j + 1] == 2) {
                        a[i][j + 1] = 0;
                    }
                    if (a[i + 1][j + 1] == 2) {
                        a[i + 1][j + 1] = 0;
                    }
                    if (a[i + 1][j] == 2) {
                        a[i + 1][j] = 0;
                    }
                }

                else if (j + 1 > M - 1) {
                    if (a[i - 1][j] == 2) {
                        a[i - 1][j] = 0;
                    }
                    if (a[i - 1][j - 1] == 2) {
                        a[i - 1][j - 1] = 0;
                    }
                    if (a[i][j - 1] == 2) {
                        a[i][j - 1] = 0;
                    }
                    if (a[i + 1][j - 1] == 2) {
                        a[i + 1][j - 1] = 0;
                    }
                    if (a[i + 1][j] == 2) {
                        a[i + 1][j] = 0;
                    }
                }

                else {
                    if (a[i - 1][j] == 2) {
                        a[i - 1][j] = 0;
                    }
                    if (a[i - 1][j + 1] == 2) {
                        a[i - 1][j + 1] = 0;
                    }
                    if (a[i][j + 1] == 2) {
                        a[i][j + 1] = 0;
                    }
                    if (a[i + 1][j + 1] == 2) {
                        a[i + 1][j + 1] = 0;
                    }
                    if (a[i + 1][j] == 2) {
                        a[i + 1][j] = 0;
                    }
                    if (a[i - 1][j - 1] == 2) {
                        a[i - 1][j - 1] = 0;
                    }
                    if (a[i][j - 1] == 2) {
                        a[i][j - 1] = 0;
                    }
                    if (a[i + 1][j - 1] == 2) {
                        a[i + 1][j - 1] = 0;
                    }
                }
            }
            j++;
        }
        i++;
    }
}

void MoveMonsters() {
    if (step >= steps) {
        int i = 0;
        while (i < N) {
            int j = 0;
            while (j < M) {
                if (a[i][j] == 4) {
                    int di = rand() % 3 - 1; // от -1 до +1
                    int dj = 0;

                    if (di == 0) {
                        dj = rand() % 3 - 1; // от -1 до +1
                    }

                    if (di != 0 || dj != 0) {
                        if (i + di >= 0 && i + di < N
                            && j + dj >= 0 && j + dj < M)
                        {
                            if (a[i + di][j + dj] == 0 || a[i + di][j + dj] == 3 || a[i + di][j + dj] == 1) {
                                a[i][j] = 0;
                                a[i + di][j + dj] = -4;
                            }
                        }
                    }
                }
                j++;
            }
            i++;
        }

        i = 0;
        while (i < N) {
            int j = 0;
            while (j < M) {
                if (a[i][j] == -4) {
                    a[i][j] = 4;
                }
                j++;
            }
            i++;
        }
    }
    
    step = steps;
}

void MoveMonstersRage() {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 4) {
                int di = rand() % 3 - 1; // от -1 до +1
                int dj = 0;

                if (di == 0) {
                    dj = rand() % 3 - 1; // от -1 до +1
                }

                if (di != 0 || dj != 0) {
                    if (i + di >= 0 && i + di < N
                        && j + dj >= 0 && j + dj < M)
                    {
                        if (a[i + di][j + dj] == 0 || a[i + di][j + dj] == 3 || a[i + di][j + dj] == 1) {
                            a[i][j] = 0;
                            a[i + di][j + dj] = -4;
                        }
                    }
                }
            }
            j++;
        }
        i++;
    }

    i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == -4) {
                a[i][j] = 4;
            }
            j++;
        }
        i++;
    }
}

void MoveMonstersChoose() {
    if (moster_eaten == 1) {
        MoveMonstersRage();
    }
    else {
        MoveMonsters();
    }
}

void generateLevel() {
    //  оды €чеек
    // 0 - свободно
    // 1 - золото
    // 2 - стена
    // 3 - игрок
    // 4 - ћќЌ—“–!

    // всЄ заново!
    steps = 0;
    gold = 0;

    // все €чейки делаем свободными
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            a[i][j] = 0;
        }
    }

    // в часть €чеек помещаем много «ќЋќ“ј
    int k;
    for (k = 0; k < (N * M) / 2; k++) {
        i = rand() % N;
        j = rand() % M;
        a[i][j] = 1;
    }

    // в часть €чеек помещаем —“≈Ќџ
    for (k = 0; k < (N * M) / 5; k++) {
        i = rand() % N;
        j = rand() % M;
        a[i][j] = 2;
    }

    // в одну из €чеек помещаем игрока
    i = rand() % N;
    j = rand() % M;
    a[i][j] = 3;

}

void generateLevelWithMonsters() {
    //  оды €чеек
    // 0 - свободно
    // 1 - золото
    // 2 - стена
    // 3 - игрок
    // 4 - ћќЌ—“–!

    // всЄ заново!
    steps = 0;
    gold = 0;

    // все €чейки делаем свободными
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            a[i][j] = 0;
        }
    }

    // в часть €чеек помещаем много «ќЋќ“ј
    int k;
    for (k = 0; k < (N * M) / 2; k++) {
        i = rand() % N;
        j = rand() % M;
        a[i][j] = 1;
    }

    // в часть €чеек помещаем —“≈Ќџ
    for (k = 0; k < (N * M) / 5; k++) {
        i = rand() % N;
        j = rand() % M;
        a[i][j] = 2;
    }

    // в часть €чеек помещаем ћќЌ—“–ќ¬
    for (k = 0; k < (N * M) / 20; k++) {
        i = rand() % N;
        j = rand() % M;
        a[i][j] = 4;
    }

    // в одну из €чеек помещаем игрока
    i = rand() % N;
    j = rand() % M;
    a[i][j] = 3;

}

void insertGold() {
    int i; int j;
    while (true)
    {
        int i = rand() % N;
        int j = rand() % M;
        if (a[i][j] == 0) {
            a[i][j] = 1;
            break;
        }
    }
    
}

char filename[] = "C:\\Users\\yanka\\OneDrive\\stuff\\9laba.txt";

int saveLevel() {
    FILE* fin = fopen(filename, "wt");

    if (fin == NULL) {
        printf("File %s is not opened", filename);
        return 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fprintf(fin, "%d", a[i][j]);
            fprintf(fin, "%s", " ");
        }
        fprintf(fin, "%s", "\n");
    }

    fclose(fin);
    return 1;
}

int loadLevel() {
    FILE* fin = fopen(filename, "rt");

    if (fin == NULL) {
        printf("File %s is not opened", filename);
        return 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fscanf_s(fin, "%d", &a[i][j]);
        }
    }

    fclose(fin);
    return 1;
}