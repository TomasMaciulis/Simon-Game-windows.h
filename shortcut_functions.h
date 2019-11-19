#ifndef SHORTCUT_FUNCTIONS_H_INCLUDED
#define SHORTCUT_FUNCTIONS_H_INCLUDED



#endif // SHORTCUT_FUNCTIONS_H_INCLUDED


void SetButtonVisual (char button, char assetType);

void ShowGameLayout();
void ShowMenuLayout();
void ShowRestartButton();
void ShowAboutLayout();
void HideAboutLayout();
void HideGameLayout();
void HideMenuLayout();
void HideRestartButton();
void EnableGameButtons();
void DisableGameButtons();

void SetButtonVisual (char button, char assetType)
{
    if (assetType == 'c'){
            if (button == 'y') {
                SendMessage (yButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)yButtonAssetClick);
            }
            else if (button == 'b'){
                SendMessage (bButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bButtonAssetClick);
            }
            else if (button == 'r'){
                SendMessage (rButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)rButtonAssetClick);
            }
            else if (button == 'g'){
                SendMessage (gButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)gButtonAssetClick);
            }
    }

    else if (assetType == 'i'){
        if (button == 'y') {
                SendMessage (yButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)yButtonAssetIdle);
            }
            else if (button == 'b'){
                SendMessage (bButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bButtonAssetIdle);
            }
            else if (button == 'r'){
                SendMessage (rButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)rButtonAssetIdle);
            }
            else if (button == 'g'){
                SendMessage (gButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)gButtonAssetIdle);
            }
    }
}

void ShowGameLayout ()
{
    ShowWindow (yButton, SW_SHOW);
    ShowWindow (bButton, SW_SHOW);
    ShowWindow (rButton, SW_SHOW);
    ShowWindow (gButton, SW_SHOW);
    ShowWindow (scoreScreenOnes, SW_SHOW);
    ShowWindow (scoreScreenTens, SW_SHOW);
    ShowWindow (scoreScreenHundreds, SW_SHOW);
    ShowWindow (scoreScreenThousands, SW_SHOW);
    ShowWindow (backToMenuButton, SW_SHOW);
}

void ShowMenuLayout ()
{
    ShowWindow (startButton, SW_SHOW);
    ShowWindow (scoresButton, SW_SHOW);
    ShowWindow (exitButton, SW_SHOW);
    ShowWindow (aboutButton, SW_SHOW);
    HideRestartButton();
}

void HideGameLayout ()
{
    ShowWindow (yButton, SW_HIDE);
    ShowWindow (bButton, SW_HIDE);
    ShowWindow (rButton, SW_HIDE);
    ShowWindow (gButton, SW_HIDE);
    ShowWindow (scoreScreenOnes, SW_HIDE);
    ShowWindow (scoreScreenTens, SW_HIDE);
    ShowWindow (scoreScreenHundreds, SW_HIDE);
    ShowWindow (scoreScreenThousands, SW_HIDE);
    ShowWindow (backToMenuButton, SW_HIDE);
}

void HideAboutLayout()
{
    ShowWindow (creditsText, SW_HIDE);
    ShowWindow (backToMenuButton, SW_HIDE);
}

void ShowAboutLayout()
{
    ShowWindow (creditsText, SW_SHOW);
    ShowWindow (backToMenuButton, SW_SHOW);
}

void HideMenuLayout ()
{
    ShowWindow (aboutButton, SW_HIDE);
    ShowWindow (startButton, SW_HIDE);
    ShowWindow (scoresButton, SW_HIDE);
    ShowWindow (exitButton, SW_HIDE);
}

void EnableGameButtons()
{
    yButtonEnabled = true;
    bButtonEnabled = true;
    rButtonEnabled = true;
    gButtonEnabled = true;
}

void DisableGameButtons()
{
    yButtonEnabled = false;
    bButtonEnabled = false;
    rButtonEnabled = false;
    gButtonEnabled = false;
}

void ShowRestartButton()
{
    ShowWindow(restartButton, SW_SHOW);
}

void HideRestartButton()
{
    ShowWindow(restartButton, SW_HIDE);
}
