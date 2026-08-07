#include <windows.h>
#include <GL/glut.h>
#include <math.h>

const float PI = 3.1416f;

void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0, 100.0, 0.0, 80.0);
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

void daySky()
{
   glColor3ub(135, 206, 235);
   glBegin(GL_QUADS);
   glVertex2f(0,80);
   glVertex2f(0,40);
   glVertex2f(100,40);
   glVertex2f(100,80);
   glEnd();
}

void cloud1()
{
    glColor3ub(255,255,255);
    circle(2.4922786882403, 75.5043191689104,3.9772003980637, 74.3320125558917);
    circle(4.3809799828252, 75.6143314367059,5.6549081256392, 74.4219142562808);
    circle(6.1255373129155, 75.5786751994564,7.4985183330438, 74.3496158167747);
}

void cloud2()
{
    glColor3ub(255,255,255);
    circle(45, 75,46.524927664043, 73.2192430839797);
    circle(47.3427527105824, 74.9105052427417,48.6548311666087, 72.8433777599974);
    circle(50, 75,48.6548311666087, 72.8433777599974);
}

void cloud3()
{
    glColor3ub(255,255,255);
    circle(60, 75,61.0663593780385, 73.4578824212047);
    circle(61.870522586026, 75.1280398575707,62.6449115817596, 73.4329627154597);
    circle(63.729106307906, 75.264536682381,64.1565307252693, 73.5125216177497);
    circle(65.5167458678174, 75.0266433804721,65.9333462097456, 73.3003645449764);
}

void sun()
{
    glColor3ub(255, 213, 79);
    circle(80.0395857191211, 73.0939546426522,81.7936238977046, 70.7134742574314);
}

void hill()
{
    //left hill
    glColor3ub(160, 105, 55);
    glBegin(GL_TRIANGLES);
    glVertex2f(0,40);
    glVertex2f(20, 70);
    glVertex2f(34, 40);
    glEnd();

    //mid hill
    glBegin(GL_TRIANGLES);
    glVertex2f(35, 40);
    glVertex2f(50, 70);
    glVertex2f(70, 40);
    glEnd();

    //right hill
    glBegin(GL_TRIANGLES);
    glVertex2f(70, 40);
    glVertex2f(80, 60);
    glVertex2f(100, 40);
    glEnd();
}

void atcTower()
{
    glColor3ub(240, 221, 175);
    glBegin(GL_QUADS);
    glVertex2f(37.9904162531719, 55.882930098799);
    glVertex2f(38, 40);
    glVertex2f(48, 40);
    glVertex2f(48.0155503041018, 55.8335579990934);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(37.9904162531719, 55.882930098799);
    glVertex2f(38, 40);
    glVertex2f(48, 40);
    glVertex2f(48.0155503041018, 55.8335579990934);
    glEnd();

    glColor3ub(135, 129, 112);
    glBegin(GL_QUADS);
    glVertex2f(38.0012052297718, 57.8461803347203);
    glVertex2f(37.9904162531719, 55.882930098799);
    glVertex2f(48.0155503041018, 55.8335579990934);
    glVertex2f(48.0012052297718, 57.8461803347203);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(38.0012052297718, 57.8461803347203);
    glVertex2f(37.9904162531719, 55.882930098799);
    glVertex2f(48.0155503041018, 55.8335579990934);
    glVertex2f(48.0012052297718, 57.8461803347203);
    glEnd();

    glColor3ub(217, 82, 117);
    glBegin(GL_QUADS);
    glVertex2f(37.0012052297718, 59.8461803347203);
    glVertex2f(38.0012052297718, 57.8461803347203);
    glVertex2f(48.0012052297718, 57.8461803347203);
    glVertex2f(49.0012052297718, 59.8461803347203);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(37.0012052297718, 59.8461803347203);
    glVertex2f(38.0012052297718, 57.8461803347203);
    glVertex2f(48.0012052297718, 57.8461803347203);
    glVertex2f(49.0012052297718, 59.8461803347203);
    glEnd();

    glColor3ub(204, 173, 122);
    glBegin(GL_QUADS);
    glVertex2f(37.0012052297718, 60.8461803347203);
    glVertex2f(37.0012052297718, 59.8461803347203);
    glVertex2f(49.0012052297718, 59.8461803347203);
    glVertex2f(49.0012052297718, 60.8461803347203);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(37.0012052297718, 60.8461803347203);
    glVertex2f(37.0012052297718, 59.8461803347203);
    glVertex2f(49.0012052297718, 59.8461803347203);
    glVertex2f(49.0012052297718, 60.8461803347203);
    glEnd();

    glColor3ub(66, 98, 135);
    glBegin(GL_QUADS);
    glVertex2f(39.0012052297718, 61.8461803347203);
    glVertex2f(39.0012052297718, 60.8461803347203);
    glVertex2f(47.0012052297718, 60.8461803347203);
    glVertex2f(47.0012052297718, 61.8461803347203);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(39.0012052297718, 61.8461803347203);
    glVertex2f(39.0012052297718, 60.8461803347203);
    glVertex2f(47.0012052297718, 60.8461803347203);
    glVertex2f(47.0012052297718, 61.8461803347203);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(42.5012052297718, 64.3461803347203);
    glVertex2f(42.5012052297718, 61.8461803347203);
    glVertex2f(43.5012052297718, 61.8461803347203);
    glVertex2f(43.5012052297718, 64.3461803347203);
    glEnd();
    glColor3ub(255,0,0);
    circle(43.0012052297718, 65.3461803347203,43.1213369923815, 64.3461803347203);

}

void hanger()
{
    glColor3ub(177, 163, 201);
    glBegin(GL_POLYGON);
    glVertex2f(62, 58);
    glVertex2f(52, 50);
    glVertex2f(52, 40);
    glVertex2f(72, 40);
    glVertex2f(72, 50);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(62, 58);
    glVertex2f(52, 50);
    glVertex2f(52, 40);
    glVertex2f(72, 40);
    glVertex2f(72, 50);
    glEnd();

    glColor3ub(101, 117, 117);
    glBegin(GL_QUADS);
    glVertex2f(54, 50);
    glVertex2f(54, 40);
    glVertex2f(70, 40);
    glVertex2f(70, 50);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(54, 50);
    glVertex2f(54, 40);
    glVertex2f(70, 40);
    glVertex2f(70, 50);
    glEnd();
}

void hangerPlane()
{
    glColor3ub(255,255,255);
    circle(62, 44, 63.2575445667734, 42.4668697844203);

    //leftwindow
    glColor3ub(135, 206, 235);
    glBegin(GL_QUADS);
    glVertex2f(60.8003341390141, 44.7965940785092);
    glVertex2f(60.8003341390141, 43.7965940785092);
    glVertex2f(61.6003341390141, 43.7965940785092);
    glVertex2f(61.6003341390141, 44.7965940785092);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(60.8003341390141, 44.7965940785092);
    glVertex2f(60.8003341390141, 43.7965940785092);
    glVertex2f(61.6003341390141, 43.7965940785092);
    glVertex2f(61.6003341390141, 44.7965940785092);
    glEnd();

    //rightwindow
    glColor3ub(135, 206, 235);
    glBegin(GL_QUADS);
    glVertex2f(62.4, 44.8);
    glVertex2f(62.4, 43.8);
    glVertex2f(63.2, 43.8);
    glVertex2f(63.2, 44.8);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(62.4, 44.8);
    glVertex2f(62.4, 43.8);
    glVertex2f(63.2, 43.8);
    glVertex2f(63.2, 44.8);
    glEnd();

    //backwing
    glColor3ub(217, 43, 105);
    glBegin(GL_QUADS);
    glVertex2f(61.4582720519266, 47.9961282026604);
    glVertex2f(61.5, 46);
    glVertex2f(62.5, 46);
    glVertex2f(62.5291727243499, 47.9961282026604);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(61.4582720519266, 47.9961282026604);
    glVertex2f(61.5, 46);
    glVertex2f(62.5, 46);
    glVertex2f(62.5291727243499, 47.9961282026604);
    glEnd();

    //leftwing
    glColor3ub(217, 43, 105);
    glBegin(GL_QUADS);
    glVertex2f(56, 45);
    glVertex2f(56, 43);
    glVertex2f(60, 43);
    glVertex2f(60, 45);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(56, 45);
    glVertex2f(56, 43);
    glVertex2f(60, 43);
    glVertex2f(60, 45);
    glEnd();

    //leftengine
    glColor3ub(0,0,0);
    circle(57, 42,57.3642205039828, 41.0766261199721);
    glColor3ub(255,255,255);
    circle(57, 42, 57.116795052542, 41.506083562404);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(56.5,42);
    glVertex2f(57.5,42);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(57,42.5);
    glVertex2f(57,41.5);
    glEnd();

    //leftwheel
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(58.5,43);
    glVertex2f(58.5,40);
    glVertex2f(59,40);
    glVertex2f(59,43);
    glEnd();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(58.7, 40.2);
    glVertex2f(58.7,40);
    glVertex2f(58.8,40);
    glVertex2f(58.8,40.2);
    glEnd();

     //rightwing
    glColor3ub(217, 43, 105);
    glBegin(GL_QUADS);
    glVertex2f(64, 45);
    glVertex2f(64, 43);
    glVertex2f(68, 43);
    glVertex2f(68, 45);
    glEnd();
    glColor3ub(0,0,0);
    glVertex2f(64, 45);
    glVertex2f(64, 43);
    glVertex2f(68, 43);
    glVertex2f(68, 45);
    glBegin(GL_LINE_LOOP);
    glEnd();

    //rightengine
    glColor3ub(0,0,0);
    circle(67, 42,67.3313134544279, 41.0449510364432);
    glColor3ub(255,255,255);
    circle(67, 42, 67.1739384250585, 41.5429653349676);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(66.5,42);
    glVertex2f(67.48,42);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(67,42.5);
    glVertex2f(67,41.5);
    glEnd();

    //leftwheel
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(65,43);
    glVertex2f(65,40);
    glVertex2f(65.5,40);
    glVertex2f(65.5,43);
    glEnd();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(65.2,40.2);
    glVertex2f(65.2,40);
    glVertex2f(65.3,40);
    glVertex2f(65.3,40.2);
    glEnd();

    //frontwheel
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(61.5, 42);
    glVertex2f(61.5, 40);
    glVertex2f(62.5,40);
    glVertex2f(62.5, 42);
    glEnd();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(61.5,40.5);
    glVertex2f(61.5,40);
    glVertex2f(62.5,40);
    glVertex2f(62.5, 40.5);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(62,40.5);
    glVertex2f(62,40);
    glEnd();

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

    daySky();
    sun();
    cloud1();
    cloud2();
    cloud3();
    hill();
    atcTower();
    hanger();
    hangerPlane();

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
