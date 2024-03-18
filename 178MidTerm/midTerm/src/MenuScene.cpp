#include "MenuScene.h"
#include <GLScene.h>
#include <common.h>

MenuScene::MenuScene()
{
    //ctor
}

MenuScene::~MenuScene()
{
    //dtor
}
void MenuScene::DisplayMainMenu()
{
    cout << "Display Main Menu Here. \n";
    //Draw Main
}

void MenuScene::DisplayGame()
{
    cout << "Display Game Here. \n";
    //Draw Game here
}

void MenuScene::display()
{
    switch (gState)
    {
    case State_MainMenu:
        {
          DisplayMainMenu();
            break;
        }
    case State_Game:
        {
            DisplayGame();
            break;
        }
    }

}
