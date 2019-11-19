//includes
#include <windows.h>
#include <tchar.h>
#include <time.h>
#include <stdlib.h>

//icon
#define IDI_ICON1 102
//buttons
#define GREEN_BUTTON 1001
#define RED_BUTTON 1002
#define YELLOW_BUTTON 1003
#define BLUE_BUTTON 1004
#define START_BUTTON 1005
#define SCORES_BUTTON 1006
#define EXIT_BUTTON 1007
#define BACK_TO_MENU_BUTTON 1008
#define RESTART_BUTTON 1009
#define ABOUT_BUTTON 1010
//bitmaps
#define YELLOW_BUTTON_BITMAP 1105
#define BLUE_BUTTON_BITMAP 1106
#define RED_BUTTON_BITMAP 1107
#define GREEN_BUTTON_BITMAP 1108
#define YELLOW_BUTTON_HOVER_BITMAP 1109
#define BLUE_BUTTON_HOVER_BITMAP 1110
#define RED_BUTTON_HOVER_BITMAP 1111
#define GREEN_BUTTON_HOVER_BITMAP 1112
#define YELLOW_BUTTON_CLICK_BITMAP 1113
#define BLUE_BUTTON_CLICK_BITMAP 1114
#define RED_BUTTON_CLICK_BITMAP 1115
#define GREEN_BUTTON_CLICK_BITMAP 1116
#define START_BUTTON_BITMAP 1117
#define EXIT_BUTTON_BITMAP 1118
#define SCORES_BUTTON_BITMAP 1119
#define BACK_BUTTON_BITMAP 1120
#define RESTART_BUTTON_BITMAP 1121
#define ABOUT_BUTTON_BITMAP 1132

#define SCORE_SCREEN_BITMAP_0 1122
#define SCORE_SCREEN_BITMAP_1 1123
#define SCORE_SCREEN_BITMAP_2 1124
#define SCORE_SCREEN_BITMAP_3 1125
#define SCORE_SCREEN_BITMAP_4 1126
#define SCORE_SCREEN_BITMAP_5 1127
#define SCORE_SCREEN_BITMAP_6 1128
#define SCORE_SCREEN_BITMAP_7 1129
#define SCORE_SCREEN_BITMAP_8 1130
#define SCORE_SCREEN_BITMAP_9 1131
//menu
#define IDR_MENU 101
#define MENU_EXIT 1100
//dialog
#define EXIT_DIALOG 1200
#define EXIT_YES 1201
#define EXIT_NO 1202
//timers
#define TIMER_Y 1300
#define TIMER_B 1301
#define TIMER_R 1302
#define TIMER_G 1303
#define TIMER_Y_C 1304
#define TIMER_B_C 1305
#define TIMER_R_C 1306
#define TIMER_G_C 1307
#define TIMER_DEMO 1308
#define TIMER_START 1309

//button handles
HWND yButton;
HWND bButton;
HWND rButton;
HWND gButton;
HWND startButton;
HWND scoresButton;
HWND exitButton;
HWND backToMenuButton;
HWND restartButton;
HWND aboutButton;
HWND scoreScreenOnes;
HWND scoreScreenTens;
HWND scoreScreenHundreds;
HWND scoreScreenThousands;
HWND creditsText;
//parameters
int BUTTON_SIZE = 200;
int BLANK_SPACE_TOP = 140;
int BUTTON_SPACING = 15;
int WINDOW_WIDTH = 545;
int WINDOW_HEIGHT = 630;
//window handle
HWND hwnd;
HINSTANCE hInstance;

//icon handle
HICON hIcon;

//bitmap handles
HBITMAP yButtonAssetIdle;
HBITMAP bButtonAssetIdle;
HBITMAP rButtonAssetIdle;
HBITMAP gButtonAssetIdle;

HBITMAP yButtonAssetHover;
HBITMAP bButtonAssetHover;
HBITMAP rButtonAssetHover;
HBITMAP gButtonAssetHover;

HBITMAP yButtonAssetClick;
HBITMAP bButtonAssetClick;
HBITMAP rButtonAssetClick;
HBITMAP gButtonAssetClick;

HBITMAP startButtonAsset;
HBITMAP aboutButtonAsset;
HBITMAP scoresButtonAsset;
HBITMAP backButtonAsset;
HBITMAP restartButtonAsset;
HBITMAP exitButtonAsset;

HBITMAP scoreScreenAsset0;
HBITMAP scoreScreenAsset1;
HBITMAP scoreScreenAsset2;
HBITMAP scoreScreenAsset3;
HBITMAP scoreScreenAsset4;
HBITMAP scoreScreenAsset5;
HBITMAP scoreScreenAsset6;
HBITMAP scoreScreenAsset7;
HBITMAP scoreScreenAsset8;
HBITMAP scoreScreenAsset9;
//array things
int buttonSeq [9999];
int buttonSeqSize = 0;
int buttonSeqCurrentPosition = 0;
int buttonSeqIndex = 0;

bool yButtonEnabled = false;
bool bButtonEnabled = false;
bool rButtonEnabled = false;
bool gButtonEnabled = false;

int scoreOnes = 0;
int scoreTens = 0;
int scoreHundreds = 0;
int scoreThousands = 0;
int scoreTotal = 0;
int gameOverState = 0;
