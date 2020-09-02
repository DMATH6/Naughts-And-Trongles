#include <stdio.h>
#include <windows.h>
#include <gl/gl.h>
#include <GL/glut.h>

//OPEN GL BEGIN
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "OpenGL Sample",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          512,
                          512,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {

            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glPushMatrix();

            //Yo yo motherfuck this bad boi draws a grid

            //BEGIN THE THING

           glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(0.35f,   -1.0f);
                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(0.35f,  1.0f);

            glEnd();

            glBegin(GL_LINE_STRIP);

                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(-0.35f,   -1.0f);
                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(-0.35f,  1.0f);

            glEnd();


            glBegin(GL_LINE_STRIP);

                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(1.0f,   0.35f);
                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(-1.0f,  0.35f);

            glEnd();

            glBegin(GL_LINE_STRIP);

                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(1.0f,   -0.35f);
                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(-1.0f,  -0.35f);

            glEnd();

            glPopMatrix();

            //OH GOD ITS DONE

/*
            //This draws many X in middle row

            //BEGIN THE THING


            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.25f,   -0.25f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.25f,  0.25f);

            glEnd();

            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.25f,   0.25f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.25f,  -0.25f);

            glEnd();

            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.25f,   0.90f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.25f,  0.45f);

            glEnd();

            glPopMatrix();


            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.25f,   -0.90f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.25f,  -0.45f);

            glEnd();

            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.25f,   -0.45f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.25f,  -0.90f);

            glEnd();


            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.25f,   0.45f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.25f,  0.90f);

            glEnd();



            glPopMatrix();

            //OH GOD ITS DONE

            //This draws many X in left row

            //BEGIN THE THING


            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.45f,   -0.25f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.90f,  0.25f);

            glEnd();

            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.45f,   0.25f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.90f,  -0.25f);

            glEnd();

            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.45f,   0.90f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.90f,  0.45f);

            glEnd();

            glPopMatrix();


            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.45f,   -0.90f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.90f,  -0.45f);

            glEnd();

            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.45f,   -0.45f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.90f,  -0.90f);

            glEnd();


            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.45f,   0.45f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.90f,  0.90f);

            glEnd();




           glPopMatrix();

            //OH GOD ITS DONE

            //This draws many X in right row

            //BEGIN THE THING


            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.45f,   -0.25f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.90f,  0.25f);

            glEnd();

            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.45f,   0.25f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.90f,  -0.25f);

            glEnd();

            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.45f,   0.90f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.90f,  0.45f);

            glEnd();

            glPopMatrix();


            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.45f,   -0.90f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.90f,  -0.45f);

            glEnd();

            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.45f,   -0.45f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.90f,  -0.90f);

            glEnd();


            glBegin(GL_LINE_STRIP);


                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.45f,   0.45f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(-0.90f,  0.90f);

            glEnd();



            glPopMatrix();

            //OH GOD ITS DONE

            //This draws many 0 in right row

            //BEGIN THE THING


            glBegin(GL_TRIANGLES);

                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.45f,   0.45f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.90f,  0.45f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.45f, 0.90f);

            glEnd();

            glBegin(GL_TRIANGLES);

                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.45f,   -0.25f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.90f,  -0.25f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.45f, 0.25f);

            glEnd();

            glBegin(GL_TRIANGLES);

                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.45f,   -0.90f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.90f,  -0.90f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.45f, -0.45f);

            glEnd();

           //END THE THING
            //This draws many 0 in left row

            //BEGIN THE THING
            glBegin(GL_TRIANGLES);

                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.45f,   0.45f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.90f,  0.45f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.45f, 0.90f);

            glEnd();

            glBegin(GL_TRIANGLES);

                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.45f,   -0.25f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.90f,  -0.25f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.45f, 0.25f);

            glEnd();

            glBegin(GL_TRIANGLES);

                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.45f,   -0.90f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.90f,  -0.90f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.45f, -0.45f);

            glEnd();
            //END THE THING

            //BLAH BLAH DRAWS 0 IN THE MIDDLE
                        glBegin(GL_TRIANGLES);

                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.25f,   0.45f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.25f,  0.45f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.25f, 0.90f);

            glEnd();

            glBegin(GL_TRIANGLES);

                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.25f,   -0.25f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.25f,  -0.25f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.25f, 0.25f);

            glEnd();

            glBegin(GL_TRIANGLES);

                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.25f,   -0.90f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.25f,  -0.90f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.25f, -0.45f);

            glEnd();
*/
            glPopMatrix();

            //OH GOD ITS DONE
            SwapBuffers(hDC);

            theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                break;
            }
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

//OPEN GL END


//GAME BEGIN
int game()
{
int Position [9] = {1,2,3,4,5,6,7,8,9};
printf("Wealcome, since im a terrible programmer we are going to play useing the keyborad \n");

int r, c;

  /*  printf("Enter Number Of Rows And Columns: ");
    scanf("%d", &row);
    scanf("%d", &col); */

    int row = 3;
    int col = 3;

    for(r = 0; r < row; r++)
    {
        /* Draw Top */
        for(c = 0; c < col; c++)
            printf("+--");
        printf("+\n");

        /* Draw Middle */
        for(c = 0; c < col; c++)
            printf("|  ");
        printf("|\n");
    }

    /* Draw Bottom */
    for(c = 0; c < col; c++)
        printf("+--");
    printf("+\n");

  return 0;
}


