#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
#include <string>
#include "simon.h"
#include "shortcut_functions.h"
#include "game_functions.h"
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);


/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("Simon Game");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No exvoid SetYellowVisualClick()
{
    SendMessage (yButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)yButtonAssetClick);
}
tra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Simon Game"),       /* Title Text */
           (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX), /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           WINDOW_WIDTH,                 /* The programs width */
           WINDOW_HEIGHT,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           LoadMenu(NULL, MAKEINTRESOURCE(IDR_MENU)),                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        SendMessage (yButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)yButtonAssetIdle);
        case WM_CREATE:
        {
            srand (time(NULL));

            //Load icon
            hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
            hIcon = LoadIcon (hInstance, MAKEINTRESOURCE (IDI_ICON1));
            //Set icon
            SendMessage (hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
            //Load bitmaps for buttons
            yButtonAssetIdle = LoadBitmap (hInstance, MAKEINTRESOURCE (YELLOW_BUTTON_BITMAP));
            bButtonAssetIdle = LoadBitmap (hInstance, MAKEINTRESOURCE (BLUE_BUTTON_BITMAP));
            rButtonAssetIdle = LoadBitmap (hInstance, MAKEINTRESOURCE (RED_BUTTON_BITMAP));
            gButtonAssetIdle = LoadBitmap (hInstance, MAKEINTRESOURCE (GREEN_BUTTON_BITMAP));

            yButtonAssetHover = LoadBitmap (hInstance, MAKEINTRESOURCE (YELLOW_BUTTON_HOVER_BITMAP));
            bButtonAssetHover = LoadBitmap (hInstance, MAKEINTRESOURCE (BLUE_BUTTON_HOVER_BITMAP));
            rButtonAssetHover = LoadBitmap (hInstance, MAKEINTRESOURCE (RED_BUTTON_HOVER_BITMAP));
            gButtonAssetHover = LoadBitmap (hInstance, MAKEINTRESOURCE (GREEN_BUTTON_HOVER_BITMAP));

            yButtonAssetClick = LoadBitmap (hInstance, MAKEINTRESOURCE (YELLOW_BUTTON_CLICK_BITMAP));
            bButtonAssetClick = LoadBitmap (hInstance, MAKEINTRESOURCE (BLUE_BUTTON_CLICK_BITMAP));
            rButtonAssetClick = LoadBitmap (hInstance, MAKEINTRESOURCE (RED_BUTTON_CLICK_BITMAP));
            gButtonAssetClick = LoadBitmap (hInstance, MAKEINTRESOURCE (GREEN_BUTTON_CLICK_BITMAP));

            //Load bitmaps for screen
            scoreScreenAsset0 = LoadBitmap (hInstance, MAKEINTRESOURCE (SCORE_SCREEN_BITMAP_0));
            scoreScreenAsset1 = LoadBitmap (hInstance, MAKEINTRESOURCE (SCORE_SCREEN_BITMAP_1));
            scoreScreenAsset2 = LoadBitmap (hInstance, MAKEINTRESOURCE (SCORE_SCREEN_BITMAP_2));
            scoreScreenAsset3 = LoadBitmap (hInstance, MAKEINTRESOURCE (SCORE_SCREEN_BITMAP_3));
            scoreScreenAsset4 = LoadBitmap (hInstance, MAKEINTRESOURCE (SCORE_SCREEN_BITMAP_4));
            scoreScreenAsset5 = LoadBitmap (hInstance, MAKEINTRESOURCE (SCORE_SCREEN_BITMAP_5));
            scoreScreenAsset6 = LoadBitmap (hInstance, MAKEINTRESOURCE (SCORE_SCREEN_BITMAP_6));
            scoreScreenAsset7 = LoadBitmap (hInstance, MAKEINTRESOURCE (SCORE_SCREEN_BITMAP_7));
            scoreScreenAsset8 = LoadBitmap (hInstance, MAKEINTRESOURCE (SCORE_SCREEN_BITMAP_8));
            scoreScreenAsset9 = LoadBitmap (hInstance, MAKEINTRESOURCE (SCORE_SCREEN_BITMAP_9));

            aboutButtonAsset = LoadBitmap (hInstance, MAKEINTRESOURCE (ABOUT_BUTTON_BITMAP));
            startButtonAsset = LoadBitmap (hInstance, MAKEINTRESOURCE (START_BUTTON_BITMAP));
            scoresButtonAsset = LoadBitmap (hInstance, MAKEINTRESOURCE (SCORES_BUTTON_BITMAP));
            exitButtonAsset = LoadBitmap (hInstance, MAKEINTRESOURCE (EXIT_BUTTON_BITMAP));
            backButtonAsset = LoadBitmap (hInstance, MAKEINTRESOURCE (BACK_BUTTON_BITMAP));
            restartButtonAsset = LoadBitmap (hInstance, MAKEINTRESOURCE (RESTART_BUTTON_BITMAP));

            if (yButtonAssetIdle == NULL || bButtonAssetIdle == NULL || rButtonAssetIdle == NULL || gButtonAssetIdle == NULL
                || yButtonAssetHover == NULL || bButtonAssetHover == NULL || rButtonAssetHover == NULL || gButtonAssetHover == NULL
                || yButtonAssetClick == NULL || bButtonAssetClick == NULL || rButtonAssetClick == NULL || gButtonAssetClick == NULL
                || startButtonAsset == NULL || scoresButtonAsset == NULL || exitButtonAsset == NULL){
                ::MessageBox(NULL, _T("Failed to load button assets"), _T("Error"), MB_OK);
                return 0;
            }

            yButton = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "Yellow button",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    BUTTON_SPACING * 4,         // x position
                    BLANK_SPACE_TOP,         // y position
                    BUTTON_SIZE,        // Button width
                    BUTTON_SIZE,        // Button height
                    hwnd,     // Parent window
                    (HMENU) YELLOW_BUTTON,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

            bButton = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "Blue button",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    BUTTON_SIZE + 5 * BUTTON_SPACING,         // x position
                    BLANK_SPACE_TOP,         // y position
                    BUTTON_SIZE,        // Button width
                    BUTTON_SIZE,        // Button height
                    hwnd,     // Parent window
                    (HMENU) BLUE_BUTTON,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

            rButton = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "Red button",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    BUTTON_SPACING * 4,         // x position
                    BLANK_SPACE_TOP + BUTTON_SIZE + BUTTON_SPACING,         // y position
                    BUTTON_SIZE,        // Button width
                    BUTTON_SIZE,        // Button height
                    hwnd,     // Parent window
                    (HMENU) RED_BUTTON,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

            gButton = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "Green button",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    BUTTON_SIZE + 5 * (BUTTON_SPACING),         // x position
                    BLANK_SPACE_TOP + BUTTON_SIZE + BUTTON_SPACING,         // y position
                    BUTTON_SIZE,        // Button width
                    BUTTON_SIZE,        // Button height
                    hwnd,     // Parent window
                    (HMENU) GREEN_BUTTON,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

            startButton = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "Start Button",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    WINDOW_WIDTH/2-100,         // x position
                    WINDOW_HEIGHT/4,         // y position
                    BUTTON_SIZE,        // Button width
                    BUTTON_SIZE/2,        // Button height
                    hwnd,     // Parent window
                    (HMENU) START_BUTTON,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

            scoresButton = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "High Scores",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    WINDOW_WIDTH/2-100,         // x position
                    WINDOW_HEIGHT/4+BUTTON_SIZE/2+10,         // y position
                    BUTTON_SIZE,        // Button width
                    BUTTON_SIZE/2,        // Button height
                    hwnd,     // Parent window
                    (HMENU) SCORES_BUTTON,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

           exitButton = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "Exit Button",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    WINDOW_WIDTH/2-100,         // x position
                    WINDOW_HEIGHT/4+BUTTON_SIZE/2+200,         // y position
                    BUTTON_SIZE,        // Button width
                    BUTTON_SIZE/2,        // Button height
                    hwnd,     // Parent window
                    (HMENU) EXIT_BUTTON,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

            aboutButton = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "About Button",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    WINDOW_WIDTH-105,         // x position
                    WINDOW_HEIGHT-(BUTTON_SIZE/2),         // y position
                    BUTTON_SIZE/2,        // Button width
                    BUTTON_SIZE/4,        // Button height
                    hwnd,     // Parent window
                    (HMENU) ABOUT_BUTTON,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.


           restartButton = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "Restart Button",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    WINDOW_WIDTH-170,         // x position
                    15 ,         // y position
                    BUTTON_SIZE/2,        // Button width
                    BUTTON_SIZE/2,        // Button height
                    hwnd,     // Parent window
                    (HMENU) START_BUTTON,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

            scoreScreenThousands = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    WINDOW_WIDTH/2-105,         // x position
                    BUTTON_SPACING,         // y position
                    BUTTON_SIZE/4,        // Button width
                    BUTTON_SIZE/2,        // Button height
                    hwnd,     // Parent window
                    0,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

            scoreScreenHundreds = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    WINDOW_WIDTH/2-100+45,         // x position
                    BUTTON_SPACING,         // y position
                    BUTTON_SIZE/4,        // Button width
                    BUTTON_SIZE/2,        // Button height
                    hwnd,     // Parent window
                    0,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

            scoreScreenTens = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    WINDOW_WIDTH/2-5,         // x position
                    BUTTON_SPACING,         // y position
                    BUTTON_SIZE/4,        // Button width
                    BUTTON_SIZE/2,        // Button height
                    hwnd,     // Parent window
                    0,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

            scoreScreenOnes = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    WINDOW_WIDTH/2-100+145,         // x position
                    BUTTON_SPACING,         // y position
                    BUTTON_SIZE/4,        // Button width
                    BUTTON_SIZE/2,        // Button height
                    hwnd,     // Parent window
                    0,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

            backToMenuButton = CreateWindow(
                    "BUTTON",  // Predefined class; Unicode assumed
                    "",      // Button text
                    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_BITMAP,  // Styles
                    0,         // x position
                    0,         // y position
                    BUTTON_SIZE/4,        // Button width
                    BUTTON_SIZE/4,        // Button height
                    hwnd,     // Parent window
                    (HMENU) BACK_TO_MENU_BUTTON,       // No menu.
                    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
                    NULL);      // Pointer not needed.

            creditsText = CreateWindow("static",
                                       "November, 2019\n\nThis game was developed for Windows API course at Vilnius University.\n\nSource code can be found on my GitHub page: github.com/TomasMaciulis\n",
                                       WS_VISIBLE | WS_CHILD | WS_BORDER,
                                       0,150, 540, 120,
                                       hwnd, NULL, NULL, NULL);

            //Set bitmaps on screen
            SendMessage (scoreScreenOnes, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset0);
            SendMessage (scoreScreenTens, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset0);
            SendMessage (scoreScreenHundreds, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset0);
            SendMessage (scoreScreenThousands, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoreScreenAsset0);
            //Set bitmaps on buttons
            SendMessage (yButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)yButtonAssetIdle);
            SendMessage (bButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bButtonAssetIdle);
            SendMessage (rButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)rButtonAssetIdle);
            SendMessage (gButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)gButtonAssetIdle);
            SendMessage (startButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)startButtonAsset);
            SendMessage (scoresButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)scoresButtonAsset);
            SendMessage (exitButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)exitButtonAsset);
            SendMessage (restartButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)restartButtonAsset);
            SendMessage (aboutButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)aboutButtonAsset);
            SendMessage (backToMenuButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)backButtonAsset);

            HideAboutLayout();
            HideGameLayout();
            HideRestartButton();

            buttonSeq[buttonSeqSize] = rand() % 4 + 1;
            buttonSeqSize += 1;
            break;
    }

        case WM_COMMAND:
            {
                switch (LOWORD(wParam))
                    {
                    case YELLOW_BUTTON:
                        {
                            if (yButtonEnabled == true){
                                SetButtonVisual('y', 'c');
                                if (CheckButtonClick('y')){
                                    GameOver();
                                }

                                SetTimer(hwnd, TIMER_Y, 500, (TIMERPROC) TimerProc);

                                if (buttonSeqSize == buttonSeqIndex){
                                    buttonSeq[buttonSeqSize] = rand() % 4 + 1;
                                    buttonSeqSize += 1;
                                    SetTimer(hwnd, TIMER_DEMO, 700, (TIMERPROC) TimerProc);
                                }
                            }
                            break;
                        }
                    case BLUE_BUTTON:
                        {
                            if (bButtonEnabled == true){
                                SetButtonVisual('b', 'c');
                                if (CheckButtonClick('b')){
                                    GameOver();
                                }

                                SetTimer(hwnd, TIMER_B, 500, (TIMERPROC) TimerProc);

                                if (buttonSeqSize == buttonSeqIndex){
                                    buttonSeq[buttonSeqSize] = rand() % 4 + 1;
                                    buttonSeqSize += 1;
                                    SetTimer(hwnd, TIMER_DEMO, 700, (TIMERPROC) TimerProc);
                                }
                            }
                            break;
                        }
                    case RED_BUTTON:
                        {
                            if (rButtonEnabled == true){
                                SetButtonVisual('r', 'c');
                                if (CheckButtonClick('r')){
                                    GameOver();
                                }

                                SetTimer(hwnd, TIMER_R, 500, (TIMERPROC) TimerProc);

                                if (buttonSeqSize == buttonSeqIndex){
                                    buttonSeq[buttonSeqSize] = rand() % 4 + 1;
                                    buttonSeqSize += 1;
                                    SetTimer(hwnd, TIMER_DEMO, 700, (TIMERPROC) TimerProc);
                                }
                            }
                            break;
                        }
                    case GREEN_BUTTON:
                        {
                            if (gButtonEnabled == true){
                                SetButtonVisual('g', 'c');
                                if (CheckButtonClick('g')){
                                    GameOver();
                                }

                                SetTimer(hwnd, TIMER_G, 500, (TIMERPROC) TimerProc);
                                if (buttonSeqSize == buttonSeqIndex){
                                    buttonSeq[buttonSeqSize] = rand() % 4 + 1;
                                    buttonSeqSize += 1;
                                    SetTimer(hwnd, TIMER_DEMO, 700, (TIMERPROC) TimerProc);
                                }
                            }

                            break;
                        }
                    case START_BUTTON:
                        {
                            scoreOnes = 0;
                            scoreTens = 0;
                            scoreHundreds = 0;
                            scoreThousands = 0;
                            scoreTotal = 0;
                            UpdateScoreScreen();
                            gameOverState = 0;

                            SetTimer(hwnd, TIMER_START, 2000, (TIMERPROC) TimerProc);

                            SetButtonVisual('y', 'c');
                            SetButtonVisual('b', 'c');
                            SetButtonVisual('r', 'c');
                            SetButtonVisual('g', 'c');
                            SetTimer(hwnd, TIMER_Y, 250, (TIMERPROC) TimerProc);
                            SetTimer(hwnd, TIMER_B, 250, (TIMERPROC) TimerProc);
                            SetTimer(hwnd, TIMER_R, 250, (TIMERPROC) TimerProc);
                            SetTimer(hwnd, TIMER_G, 250, (TIMERPROC) TimerProc);

                            HideMenuLayout();
                            ShowGameLayout();
                            HideRestartButton();
                            //GameStart();
                            break;
                        }
                    case SCORES_BUTTON:
                        {
                            HANDLE file;
                            DWORD b_read;
                            BOOL fileReadResult;

                            file = CreateFile("high_score", GENERIC_READ,
                                                0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

                            if (file == INVALID_HANDLE_VALUE){
                                CloseHandle(file);
                                MessageBox(hwnd, "No high score yet", "", MB_OK);
                                break;
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
                                MessageBox(hwnd, "No high score yet", "", MB_OK);
                            }

                            CloseHandle(file);

                            MessageBox(hwnd, highScoreFromFile, "Current High Score", MB_OK);

                            break;
                        }
                    case EXIT_BUTTON:
                        {
                            DialogBox(NULL, MAKEINTRESOURCE(EXIT_DIALOG), hwnd, (DLGPROC)DialogProc);
                            break;
                        }
                    case ABOUT_BUTTON:
                        {
                            HideMenuLayout();
                            ShowAboutLayout();
                            break;
                        }
                    case BACK_TO_MENU_BUTTON:
                        {
                            HideAboutLayout();
                            HideGameLayout();
                            ShowMenuLayout();
                            GameOver();
                            break;
                        }
            case MENU_EXIT:
                DialogBox(NULL, MAKEINTRESOURCE(EXIT_DIALOG), hwnd, (DLGPROC)DialogProc);
                break;
            }
            break;
        }


        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}

BOOL CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_INITDIALOG:
            return TRUE;
        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case EXIT_NO:
                    EndDialog(hDlg, 0);
                    return 1;

                case EXIT_YES:
                    PostQuitMessage(1);
                    return 1;
            }

	    return 1;
        case WM_CLOSE:
            EndDialog(hDlg, 0);
            return 1;
        case WM_DESTROY:
            EndDialog(hDlg, 0);
            return 1;
    }
    return FALSE;
}


