#include <GLScene.h>
#include<GLLight.h>
#include<GLTexture.h>
#include<GLModel.h>
#include<GLInputs.h>
#include<GLParallax.h>
#include<GLPlayer.h>
#include<GLEnms.h>
#include<GLTimer.h>
#include<GLCheckCollision.h>
#include<GLObject.h>
#include<MenuScene.h>

GLParallax *landingPage = new GLParallax();
GLParallax *mainMenu = new GLParallax();
GLObject *startButton = new GLObject();
MenuScene *menuState = new MenuScene();


GLScene::GLScene()
{
    //ctor

    screenWidth  = GetSystemMetrics(SM_CXSCREEN);
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
}

GLScene::~GLScene()
{
    //dtor
}

GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH); // for smooth render
    glClearColor(0.0f,0.0f,0.0f,0.0f); // clear background to black
    glClearDepth(2.0f);            // depth test for layers
    glEnable(GL_DEPTH_TEST);       // activate depth test
    glDepthFunc(GL_LEQUAL);         // depth function type

    GLLight Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

    glEnable(GL_BLEND);             // Transparent effect of pngs
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);  //enable textures

    landingPage->parallaxInit("images/forestWithMushroomsLanding.png");
    mainMenu->parallaxInit("images/forestWithMushrooms.png");
    startButton->initObject(1, 1, "images/StartButton.png");

    return true;
}

GLint GLScene::drawScene()    // this function runs on a loop
                              // DO NOT ABUSE ME
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// clear bits in each iteration
   glLoadIdentity();
   glColor3f(1.0,1.0,1.0);     //color the object red

   switch (menuState->gState)
   {
   case State_LandingPage:
       glPushMatrix();
        glScalef(3.5,3.2,1.0);
        glDisable(GL_LIGHTING);
        landingPage->parallaxDraw(screenWidth, screenHeight);
        glEnable(GL_LIGHTING);
       glPopMatrix();
       break;
   case State_MainMenu:
       glPushMatrix();
        glScalef(3.5,3.2,1.0);
        glDisable(GL_LIGHTING);
        mainMenu->parallaxDraw(screenWidth, screenHeight);
        mainMenu->parallaxScroll(true, "right", 0.0005);
        glEnable(GL_LIGHTING);
       glPopMatrix();

       glPushMatrix();
        startButton->drawObject();
       glPopMatrix();
       break;
   case State_Game:
    break;
   }


   return true;
}

GLvoid GLScene::resizeScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height; // keep track of the ratio
    glViewport(0,0,width,height); // adjusting the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,aspectRatio,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int GLScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)   // check for inputs
    {
    case WM_KEYDOWN:
        if(wParam == VK_RETURN && menuState->gState == State_LandingPage)
        {
            menuState->gState = State_MainMenu;
        }
         break;

    case WM_KEYUP:

         break;

    case WM_LBUTTONDOWN:

         break;

    case WM_RBUTTONDOWN:

         break;

    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:

        break;

    case WM_MOUSEMOVE:

         break;
    case WM_MOUSEWHEEL:


       break;
    }
}


