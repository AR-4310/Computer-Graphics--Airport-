#include <windows.h>
#include <GL/glut.h>
#include <math.h>

const float PI = 3.1416f;

void initGL()
{
    glClearColor(0.6f, 0.9f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0, 100.0, 0.0, 80.0);
}

void airportGround()
{
    glColor3ub(170, 170, 170);
    glBegin(GL_QUADS);
    glVertex2f(0,40);
    glVertex2f(0,0);
    glVertex2f(100,0);
    glVertex2f(100,40);
    glEnd();
}

void runwayThreshold(float x, float y)
{
    glColor3ub(255, 255, 255);

    glBegin(GL_QUADS);
        glVertex2f(x,     y);
        glVertex2f(x + 6, y);
        glVertex2f(x + 6, y + 2);
        glVertex2f(x,     y + 2);
    glEnd();
}

void runwayLight(float x, float y)
{
    float radius = 0.4f;

    glColor3ub(255, 255, 0);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);

        for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1416f * i / 100;

            glVertex2f(
                x + radius * cos(angle),
                y + radius * sin(angle)
            );
        }
    glEnd();
}

void runway()
{
    glColor3ub(60, 60, 60);
    glLineWidth(3.0f);
    glBegin(GL_QUADS);
    glVertex2f(0,20);
    glVertex2f(0,5.7598027257196);
    glVertex2f(100,5.7598027257196);
    glVertex2f(100,20);
    glEnd();

    runwayThreshold(2,16);
    runwayThreshold(2,12);
    runwayThreshold(2,8);
    runwayThreshold(12,12);
    runwayThreshold(28,12);
    runwayThreshold(44,12);
    runwayThreshold(60,12);
    runwayThreshold(76,12);
    runwayThreshold(92,12);

    //upper lights
    runwayLight(2,20);
    runwayLight(14, 20);
    runwayLight(26, 20);
    runwayLight(38, 20);
    runwayLight(50, 20);
    runwayLight(62, 20);
    runwayLight(74, 20);
    runwayLight(86, 20);
    runwayLight(98, 20);

    //lower lights
    runwayLight(2,5.7);
    runwayLight(14,5.7);
    runwayLight(26,5.7);
    runwayLight(38,5.7);
    runwayLight(50,5.7);
    runwayLight(62,5.7);
    runwayLight(74,5.7);
    runwayLight(86,5.7);
    runwayLight(98,5.7);

}

void planeWindow(float x, float y)
{
    // Window fill
    glColor3ub(135, 206, 235);

    glBegin(GL_QUADS);
        glVertex2f(x,     y);
        glVertex2f(x + 1, y);
        glVertex2f(x + 1, y + 1);
        glVertex2f(x,     y + 1);
    glEnd();

    // Black border
    glColor3ub(0, 0, 0);

    glBegin(GL_LINE_LOOP);
        glVertex2f(x,     y);
        glVertex2f(x + 1, y);
        glVertex2f(x + 1, y + 1);
        glVertex2f(x,     y + 1);
    glEnd();
}

void planeDoorCircle(float x, float y)
{
    float radius = 0.796f;

    glColor3ub(80, 80, 80);

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(x, y);

        for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1416f * i / 100;

            glVertex2f(
                x + radius * cos(angle),
                y + radius * sin(angle)
            );
        }

    glEnd();
}

void circle(float centerX, float centerY, float radiusX, float radiusY)
{
    // Calculate radius from the two points
    float radius = sqrt(
        (radiusX - centerX) * (radiusX - centerX) +
        (radiusY - centerY) * (radiusY - centerY)
    );

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(centerX, centerY);

        for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1416f * i / 100;

            glVertex2f(
                centerX + radius * cos(angle),
                centerY + radius * sin(angle)
            );
        }

    glEnd();
}

void runwayPlane()
{
     //body
     glColor3ub(240, 238, 235);
     glBegin(GL_POLYGON);
     glVertex2f(12.804627368261, 20.5324931212866);
     glVertex2f(8.804627368261, 18.5324931212866);
     glVertex2f(10.804627368261, 18.5324931212866);
     glVertex2f(12.804627368261, 14.5324931212866);
     glVertex2f(32.804627368261, 14.5324931212866);
     glVertex2f(36.7147021857575, 17.684104579344);
     glVertex2f(34.804627368261, 18.5324931212866);
     glVertex2f(32.804627368261, 20.5324931212866);
     glEnd();

     glColor3ub(0,0,0);
     glBegin(GL_LINE_LOOP);
     glVertex2f(12.804627368261, 20.5324931212866);
     glVertex2f(8.804627368261, 18.5324931212866);
     glVertex2f(10.804627368261, 18.5324931212866);
     glVertex2f(12.804627368261, 14.5324931212866);
     glVertex2f(32.804627368261, 14.5324931212866);
     glVertex2f(36.7147021857575, 17.684104579344);
     glVertex2f(34.804627368261, 18.5324931212866);
     glVertex2f(32.804627368261, 20.5324931212866);
     glEnd();

     //upper wing
     glColor3ub(240,238,235);
     glBegin(GL_QUADS);
     glVertex2f(12.804627368261, 24.5324931212866);
     glVertex2f(12.804627368261, 20.5324931212866);
     glVertex2f(16.8,20.5324931212866);
     glVertex2f(14.2284004928393, 24.5324931212866);
     glEnd();

     glColor3ub(0,0,0);
     glBegin(GL_LINE_LOOP);
     glVertex2f(12.804627368261, 24.5324931212866);
     glVertex2f(12.804627368261, 20.5324931212866);
     glVertex2f(16.8,20.5324931212866);
     glVertex2f(14.2284004928393, 24.5324931212866);
     glEnd();

     //middle wing
     glColor3ub(200, 205, 210);
     glBegin(GL_TRIANGLES);
     glVertex2f(12.804627368261, 19.5324931212866);
     glVertex2f(12.804627368261, 17.5324931212866);
     glVertex2f(13.804627368261, 19.5324931212866);
     glEnd();

     glColor3ub(0,0,0);
     glBegin(GL_LINE_LOOP);
     glVertex2f(12.804627368261, 19.5324931212866);
     glVertex2f(12.804627368261, 17.5324931212866);
     glVertex2f(13.804627368261, 19.5324931212866);
     glEnd();

     //main wing
     glColor3ub(200,205,210);
     glBegin(GL_TRIANGLES);
     glVertex2f(16.804627368261, 17.5324931212866);
     glVertex2f(16.804627368261, 12.5324931212866);
     glVertex2f(22.804627368261, 17.5324931212866);
     glEnd();

     glColor3ub(0,0,0);
     glBegin(GL_LINE_LOOP);
     glVertex2f(16.804627368261, 17.5324931212866);
     glVertex2f(16.804627368261, 12.5324931212866);
     glVertex2f(22.804627368261, 17.5324931212866);
     glEnd();

     //plane windows
     planeWindow(14.8, 18.53);
     planeWindow(16.8, 18.53);
     planeWindow(18.8, 18.53);
     planeWindow(20.8, 18.53);
     planeWindow(22.8, 18.53);
     planeWindow(24.8, 18.53);
     planeWindow(30.8, 18.53);

     glColor3ub(135, 206, 235); //front window
     glBegin(GL_QUADS);
     glVertex2f(32.804627368261, 19.5324931212866);
     glVertex2f(32.804627368261, 18.5324931212866);
     glVertex2f(34.804627368261, 18.5324931212866);
     glVertex2f(33.799,19.538);
     glEnd();
     glColor3ub(0,0,0);
     glBegin(GL_LINE_LOOP);
     glVertex2f(32.804627368261, 19.5324931212866);
     glVertex2f(32.804627368261, 18.5324931212866);
     glVertex2f(34.804627368261, 18.5324931212866);
     glVertex2f(33.799,19.538);
     glEnd();

     //plane door
     glColor3ub(130, 135, 140);
     glBegin(GL_QUADS);
     glVertex2f(26.804627368261, 20.032099651688);
     glVertex2f(26.804627368261, 16.032099651688);
     glVertex2f(28.804627368261, 16.032099651688);
     glVertex2f(28.804627368261, 20.032099651688);
     glEnd();
     glColor3ub(0,0,0);
     glBegin(GL_LINE_LOOP);
     glVertex2f(26.804627368261, 20.032099651688);
     glVertex2f(26.804627368261, 16.032099651688);
     glVertex2f(28.804627368261, 16.032099651688);
     glVertex2f(28.804627368261, 20.032099651688);
     glEnd();
     planeDoorCircle(27.8046, 18.5321);

     //plane front wheel
     glColor3ub(0,0,0);
     glBegin(GL_QUADS);
     glVertex2f(31.3833324793164, 12.5928111121142);
     glVertex2f(31.994050076722, 12.6033407258625);
     glVertex2f(31.994050076722, 14.5324931212866);
     glVertex2f(31.3833324793164,14.5324931212866);
     glEnd();
     circle(31.6535964332166, 12.2923002908545,31.8218151473123, 12.0318326045127);

     //plane back wheel left
     glColor3ub(0,0,0);
     glBegin(GL_QUADS);
     glVertex2f(13.2029509052645, 12.3746674003598);
     glVertex2f(14.0041352940111, 12.3866253763112);
     glVertex2f(14.0041352940111, 14.5323931212866);
     glVertex2f(13.2029509052645, 14.5323931212866);
     glEnd();
     circle(13.4790138073317, 11.8715738633303,13.8182001946567, 11.49325058516);

     //plane back wheel right
     glColor3ub(0,0,0);
     glBegin(GL_QUADS);
     glVertex2f(14.3902056493907, 13.017790945389);
     glVertex2f(14.8133426700766, 13.017790945389);
     glVertex2f(14.8133426700766, 14.5324931212866);
     glVertex2f(14.3902056493907, 14.5324931212866);
     glEnd();
     circle(14.6009380115608, 12.5499466379804,14.783576835505, 12.1194408386832);

}

//------------------------------------------------------
// Display function
//------------------------------------------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    airportGround();
    runway();
    runwayPlane();


    glutSwapBuffers();
}

//------------------------------------------------------
// Main function
//------------------------------------------------------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("OpenGL Scenario");

    initGL();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
