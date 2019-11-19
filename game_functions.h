#ifndef GAME_FUNCTIONS_H_INCLUDED
#define GAME_FUNCTIONS_H_INCLUDED

#endif // GAME_FUNCTIONS_H_INCLUDED
#include <sstream>
#include <string>
int GameStart();
int GameOver();
int CheckButtonClick(char button);
int getRecord();
void validateHighScoreFile();
void SetRecord();
void AddPoint();
void UpdateScoreScreen();
VOID CALLBACK TimerProc(HWND, UINT, UINT, DWORD);

int GameStart()
{
    DisableGameButtons();
    buttonSeqIndex = 0;
    if(gameOverState == 0){
     if (buttonSeq[buttonSeqCurrentPosition] == 1){
        buttonSeqCurrentPosition += 1;
        SetButtonVisual('y', 'c');
        SetTimer(hwnd, TIMER_Y, 400, (TIMERPROC) TimerProc);
        SetTimer(hwnd, TIMER_DEMO, 500, (TIMERPROC) TimerProc);
        return 0;
    }

     if (buttonSeq[buttonSeqCurrentPosition] == 2){
        buttonSeqCurrentPosition += 1;
        SetButtonVisual('b', 'c');
        SetTimer(hwnd, TIMER_B, 400, (TIMERPROC) TimerProc);
        SetTimer(hwnd, TIMER_DEMO, 500, (TIMERPROC) TimerProc);
        return 0;
    }

    else if (buttonSeq[buttonSeqCurrentPosition] == 3){
        buttonSeqCurrentPosition += 1;
        SetButtonVisual('r', 'c');
        SetTimer(hwnd, TIMER_R, 400, (TIMERPROC) TimerProc);
        SetTimer(hwnd, TIMER_DEMO, 500, (TIMERPROC) TimerProc);
        return 0;
    }

    else if (buttonSeq[buttonSeqCurrentPosition] == 4){
        buttonSeqCurrentPosition += 1;
        SetButtonVisual('g', 'c');
        SetTimer(hwnd, TIMER_G, 400, (TIMERPROC) TimerProc);
        SetTimer(hwnd, TIMER_DEMO, 500, (TIMERPROC) TimerProc);
        return 0;
    }
    else{
        buttonSeqCurrentPosition = 0;
        EnableGameButtons();
        return 0;
    }
  }
  return 1;
}

int GameOver()
{
    DisableGameButtons();
    for (int i=0;i<9999;i++){
        buttonSeq[i] = 0;
    }
    buttonSeqSize = 0;
    buttonSeqCurrentPosition = 0;

    buttonSeq[buttonSeqSize] = rand() % 4 + 1;
    buttonSeqSize += 1;
    return 0;
}

void createHighScoreFile() {
    HANDLE file;
    DWORD b_read;
    BOOL fileReadResult;
    DWORD b_written;
    LPCSTR score = "0";

    file = CreateFile("high_score", GENERIC_WRITE,
                       0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    b_written = 0;
    WriteFile(file, score, strlen(score), &b_written, NULL);

    CloseHandle(file);
       // MessageBox(hwnd, "File cannot be open", "File", MB_OK);
}

int getRecord() {
    HANDLE file;
    DWORD b_read;
    BOOL fileReadResult;

    file = CreateFile("high_score", GENERIC_READ,
                        0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (file == INVALID_HANDLE_VALUE){
        CloseHandle(file);
        return 0;
       // MessageBox(hwnd, "File cannot be open", "File", MB_OK);
    }

    CHAR highScoreFromFile[2048] = {0};
    b_read = 0;
    CHAR t_read[5] = {0};
    fileReadResult = ReadFile(file, highScoreFromFile, 2048, &b_read, NULL);
    if (strlen(highScoreFromFile)){

    }
    else{
        createHighScoreFile();
        CloseHandle(file);
        return 0;
        MessageBox(hwnd, "No high score yet", "File", MB_OK);
    }

    CloseHandle(file);

    return std::stoi(highScoreFromFile);
}

void setRecord(LPCSTR score) {
    HANDLE file;
    DWORD b_written;
    BOOL fileWriteResult;

    file = CreateFile("high_score", GENERIC_WRITE,
                       0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    b_written = 0;
    WriteFile(file, score, strlen(score), &b_written, NULL);

    CloseHandle(file);

    MessageBox(hwnd, "You've set a new record!", "New Record!", MB_OK);
}

int CheckButtonClick (char button)
{
    int buttonId = 0;

    if (button == 'y'){
        buttonId = 1;
    }
    else if (button == 'b'){
        buttonId = 2;
    }
    else if (button == 'r'){
        buttonId = 3;
    }
    else if (button == 'g'){
        buttonId = 4;
    }

    if (buttonSeq[buttonSeqIndex] != buttonId){
        DisableGameButtons();

        std::string message = "Game over! Your score is ";
        std::string scoreString = std::to_string(scoreTotal);
        std::string temp_str = message + scoreString;

        char const* scoreTotalString = scoreString.c_str();
        char const* scoreFinalString = temp_str.c_str();

        //validateHighScoreFile();
        if (scoreTotal > getRecord()) {
            setRecord(scoreTotalString);
        }

        ::MessageBox(hwnd, scoreFinalString, _T(""), MB_OK);
        gameOverState = 1;
        ShowRestartButton();
        return 1;
    }

    else{
        buttonSeqIndex += 1;
        AddPoint();
        UpdateScoreScreen();
        return 0;
    }

}

VOID CALLBACK TimerProc(
    HWND hwnd,        // handle to window for timer messages
    UINT message,     // WM_TIMER message
    UINT idTimer,     // timer identifier
    DWORD dwTime)     // current system time
{
    switch(message){
        case WM_TIMER:
            if (idTimer == TIMER_Y){
                KillTimer(hwnd, TIMER_Y);
                SetButtonVisual('y', 'i');
            }
            else if (idTimer == TIMER_B){
                KillTimer(hwnd, TIMER_B);
                SetButtonVisual('b', 'i');
            }
            else if (idTimer == TIMER_R){
                KillTimer(hwnd, TIMER_R);
                SetButtonVisual('r', 'i');
            }
            else if (idTimer == TIMER_G){
                KillTimer(hwnd, TIMER_G);
                SetButtonVisual('g', 'i');
            }
            else if (idTimer == TIMER_Y_C){
                KillTimer(hwnd, TIMER_Y_C);
                SetButtonVisual('y', 'c');
            }
            else if (idTimer == TIMER_B_C){
                KillTimer(hwnd, TIMER_B_C);
                SetButtonVisual('b', 'c');
            }
            else if (idTimer == TIMER_R_C){
                KillTimer(hwnd, TIMER_R_C);
                SetButtonVisual('r', 'c');
            }
            else if (idTimer == TIMER_G_C){
                KillTimer(hwnd, TIMER_G_C);
                SetButtonVisual('g', 'c');
            }
            else if (idTimer == TIMER_START) {
                KillTimer(hwnd, TIMER_START);
                GameStart();
            }
            else if (idTimer == TIMER_DEMO) {
                KillTimer(hwnd, TIMER_DEMO);
                GameStart();
            }
            break;
    }
}

void AddPoint()
{
   scoreTotal += 1;
   scoreOnes += 1;
   if (scoreOnes == 10) {
    scoreOnes = 0;
    scoreTens += 1;
   }
   if (scoreTens == 10) {
    scoreTens = 0;
    scoreHundreds += 1;
   }
   if (scoreHundreds == 10) {
    scoreHundreds = 0;
    scoreThousands += 1;
   }
   if (scoreThousands == 10) {
    scoreOnes = 0;
    scoreTens = 0;
    scoreHundreds = 0;
    scoreThousands = 0;
   }
}

void UpdateScoreScreen()
{
    switch (scoreOnes) {
    case 0:
        SendMessage (scoreScreenOnes, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset0);
        break;
    case 1:
        SendMessage (scoreScreenOnes, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset1);
        break;
    case 2:
        SendMessage (scoreScreenOnes, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset2);
        break;
    case 3:
        SendMessage (scoreScreenOnes, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset3);
        break;
    case 4:
        SendMessage (scoreScreenOnes, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset4);
        break;
    case 5:
        SendMessage (scoreScreenOnes, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset5);
        break;
    case 6:
        SendMessage (scoreScreenOnes, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset6);
        break;
    case 7:
        SendMessage (scoreScreenOnes, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset7);
        break;
    case 8:
        SendMessage (scoreScreenOnes, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset8);
        break;
    case 9:
        SendMessage (scoreScreenOnes, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset9);
        break;
    }

    switch (scoreTens) {
    case 0:
        SendMessage (scoreScreenTens, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset0);
        break;
    case 1:
        SendMessage (scoreScreenTens, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset1);
        break;
    case 2:
        SendMessage (scoreScreenTens, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset2);
        break;
    case 3:
        SendMessage (scoreScreenTens, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset3);
        break;
    case 4:
        SendMessage (scoreScreenTens, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset4);
        break;
    case 5:
        SendMessage (scoreScreenTens, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset5);
        break;
    case 6:
        SendMessage (scoreScreenTens, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset6);
        break;
    case 7:
        SendMessage (scoreScreenTens, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset7);
        break;
    case 8:
        SendMessage (scoreScreenTens, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset8);
        break;
    case 9:
        SendMessage (scoreScreenTens, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset9);
        break;
    }

    switch (scoreHundreds) {
    case 0:
        SendMessage (scoreScreenHundreds, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset0);
        break;
    case 1:
        SendMessage (scoreScreenHundreds, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset1);
        break;
    case 2:
        SendMessage (scoreScreenHundreds, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset2);
        break;
    case 3:
        SendMessage (scoreScreenHundreds, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset3);
        break;
    case 4:
        SendMessage (scoreScreenHundreds, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset4);
        break;
    case 5:
        SendMessage (scoreScreenHundreds, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset5);
        break;
    case 6:
        SendMessage (scoreScreenHundreds, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset6);
        break;
    case 7:
        SendMessage (scoreScreenHundreds, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset7);
        break;
    case 8:
        SendMessage (scoreScreenHundreds, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset8);
        break;
    case 9:
        SendMessage (scoreScreenHundreds, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset9);
        break;
    }

    switch (scoreThousands) {
    case 0:
        SendMessage (scoreScreenThousands, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset0);
        break;
    case 1:
        SendMessage (scoreScreenThousands, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset1);
        break;
    case 2:
        SendMessage (scoreScreenThousands, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset2);
        break;
    case 3:
        SendMessage (scoreScreenThousands, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset3);
        break;
    case 4:
        SendMessage (scoreScreenThousands, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset4);
        break;
    case 5:
        SendMessage (scoreScreenThousands, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset5);
        break;
    case 6:
        SendMessage (scoreScreenThousands, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset6);
        break;
    case 7:
        SendMessage (scoreScreenThousands, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset7);
        break;
    case 8:
        SendMessage (scoreScreenThousands, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset8);
        break;
    case 9:
        SendMessage (scoreScreenThousands, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset9);
        break;
    }
}
