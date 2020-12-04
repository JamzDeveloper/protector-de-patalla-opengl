#include <iostream>
#include <gl\glut.h>
#include <iostream>
#include <math.h>
#include<time.h>

using namespace std;

float trasX=0, trasY=0;
float sx=1,sy=1,sz=1;
int t=1;
float calx2, caly2;




void inicializar()
{
    glClearColor(0.2,0.2,0.2,0);
}
void graficarEjes(float r,float g, float b)

{
    glColor3f(r,g,b);
    glBegin(GL_LINES);
    glVertex2f(-100,0);
    glVertex2f(100,0);

    glVertex2f(0,-100);
    glVertex2f(0,100);
    glEnd();
}
bool tras=false;
void graficar()

{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();



    // graficarEjes(0,0,0);

    if(tras==false)
    {

        tras=true;
    }

    glColor3f(0,0,0);

    glTranslatef(trasX,trasY,0);

//  graficarEjes(0,0.5,1);

    glTranslatef(70,-43,0);
    glBegin(GL_LINES);
    glVertex2f(-80,50);//P1
    glVertex2f(-60,50);//P2

    glVertex2f(-70,60);//P3
    glVertex2f(-70,30);//P4

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9,0.6,0.3);
    glVertex2f(-80,50);//P1
    glVertex2f(-70,60);//P3
    glVertex2f(-60,50);//P2
    glVertex2f(-70,30);//P4
    glEnd();

    //orejas
    glBegin(GL_TRIANGLES);
    glColor3f(1,0.5,0.09);
    //izquierda
    glVertex2f(-77,52);
    glVertex2f(-77,66);
    glVertex2f(-72,57);
    //derecha
    glVertex2f(-68,57);
    glVertex2f(-63,66);
    glVertex2f(-63,52);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9,0.3,0.1);
    glVertex2f(-77,52);
    glVertex2f(-70,60);//P3
    glVertex2f(-63,52);
    glVertex2f(-70,30);//P4
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0.9,0.5,0.1);
    glVertex2f(-80,50);//P1
    glVertex2f(-77,52);
    glVertex2f(-77,45);
    //
    glVertex2f(-63,52);
    glVertex2f(-60,50);//P2
    glVertex2f(-63,45);
    glEnd();
    glFlush();
}
void redimensionar(int w,int h)
{


    glViewport(0,0,w,h);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100,100,-100,100,-1,1);

}


float dato=1.8,dato2=0.4;



float random()
{
    float aux;

    aux=1+rand()%(100);
    aux/=100;

    return aux;
}



void trasladarAutomatico(int i)
{

    bool inicio=true;
    if(trasX>=0&&trasY==0&&inicio)
    {
        dato=random()*3;
        dato2=random()*-5;
        inicio=false;
    }

    if(trasX>=88&&trasY<=-86)
    {
        dato=random()*3;
        dato2=random()*-3;

        cout<<dato<<"<<yyyyy--------------"<<endl;
        cout<<dato2<<"<<xxxx--------------"<<endl;
        cout<<"----------------------"<<endl;
    }
    else
    {
        if(trasX<=-88.3&&trasY>=76)
        {
            dato=random()*-3;
            dato2=random()*3;

            cout<<dato<<"<<yyyyy--------------"<<endl;
            cout<<dato2<<"<<xxxx--------------"<<endl;
            cout<<"----------------------"<<endl;
        }
        else
        {
            if(trasX>=88)
            {
                dato=random()*-3;
                dato2=random()*-3;

                cout<<dato<<"<<yyyyy--------------"<<endl;
                cout<<dato2<<"<<xxxx--------------"<<endl;
                cout<<"----------------------"<<endl;
            }
            else
            {
                if(trasX<=-88.3)
                {
                    dato=random()*3;
                    dato2=random()*3;

                    cout<<dato<<"<<yyyyy--------------"<<endl;
                    cout<<dato2<<"<<xxxx--------------"<<endl;
                    cout<<"----------------------"<<endl;
                }
                else
                {
                    if(trasY>=76)
                    {
                        dato=random()*-3;
                        dato2=random()*-3;

                        cout<<dato<<"<<yyyyy--------------"<<endl;
                        cout<<dato2<<"<<xxxx--------------"<<endl;
                        cout<<"----------------------"<<endl;
                    }
                    else
                    {

                        if(trasY<=-86)
                        {
                            dato=random()*3;
                            dato2=random()*3;

                            cout<<dato<<"<<yyyyy--------------"<<endl;
                            cout<<dato2<<"<<xxxx--------------"<<endl;
                            cout<<"----------------------"<<endl;


                        }
                    }
                }
            }
        }
    }

    trasX=trasX+dato2;
    trasY+=dato;
    glutPostRedisplay();

    glutTimerFunc(60,trasladarAutomatico,1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,500);
    glutInitWindowPosition(100,200);
    glutCreateWindow("Protector pantalla");

    inicializar();
    glutDisplayFunc(graficar);
    glutReshapeFunc(redimensionar);

    glutTimerFunc(80,trasladarAutomatico,1);

    glutMainLoop();

    return 0;
}
