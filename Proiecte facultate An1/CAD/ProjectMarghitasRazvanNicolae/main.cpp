#include <windows.h>
#include <GL/glut.h>

char title[] = "Project Marghitas Razvan";
GLfloat pyraang = 0.0f;
int refresh = 15;
int speed = 1;

void initial(){

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}


void displayp(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.5f, -6.0f);
    glRotatef(pyraang, 1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLES); //beggins rotation


    // Front
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    // Right
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    // Back
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    // Left
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);

    // Bottom
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);


    // Bottom
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    glEnd();

    glutSwapBuffers();

    pyraang += 0.15f*speed; //incresease the angle of rotation/speed

}

void timer(int value) {

    glutPostRedisplay();
    glutTimerFunc(refresh, timer, 0);

}

//key bindings for exiting, increasing speed and decreasing it
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

        case 'q':
            exit(0);
            break;

        case '+':

            speed++;

            break;

        case '-':
            if (speed>1)
            {
                speed--;
            }
            break;
    }

    glutPostRedisplay();
}

void reshape(GLsizei width, GLsizei height) {

    if(height == 0) height = 1;
    GLfloat aspect = (GLfloat)width/(GLfloat)height;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);

}

int main(int argc, char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1240,640);
    glutInitWindowPosition(50,50);
    glutCreateWindow(title);
    glutDisplayFunc(displayp);
    glutKeyboardFunc(key);
    glutReshapeFunc(reshape);
    initial();
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;

}
