#ifndef MENUSCENE_H
#define MENUSCENE_H

 enum State
     {
     State_MainMenu = 0,
     State_Game = 1
     };

class MenuScene
{
    public:
        MenuScene();
        virtual ~MenuScene();

        State gState = State_MainMenu;
        void DisplayMainMenu(); //Draw main menu here
        void DisplayGame(); // Draw game here
        void display(); //GLUT callback

    protected:

    private:
};

#endif // MENUSCENE_H
