//
//  main.cpp
//  CSCI368_Project2
//
//  Created by Madushani Lekam Wasam Liyanage on 10/17/17.
//  Copyright © 2017 Madushani Lekam Wasam Liyanage. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <math.h>

GLfloat shield[4][3] = {{8,-10,0},{8,20,0},{-8,20,0},{-8,-10,0}};
GLfloat leftBorder[4][2] = {{0,-10},{-8,-10},{-8,20}, {0,20}};
GLfloat rightBorder[4][3] = {{0,20,0},{8,20,0},{-8,-10,0},{0,-10,0}};

GLfloat colors[3][3] = {{0.25,0.41,0.88},{1,1,1},{0,0,0}};

void draw_border(bool isLeft){
    if (isLeft) {
        glBegin(GL_LINES);
        glLineWidth(3);
        for (int i=0; i<4; i++) {
            glVertex2d(leftBorder[i][0],leftBorder[i][1]);
        }
        glColor3f(1, 1, 1);
    }
    else {
        glBegin(GL_LINES);
        glLineWidth(100);
        for (int i=0; i<4; i++) {
            glVertex2d(rightBorder[i][0],rightBorder[i][1]);
        }
        glColor3f(0, 0, 0);
    }
    glEnd();
}

void draw_shield(void) {
    
    glBegin(GL_POLYGON);
    for (int i=0; i<4; i++) {
        glVertex3fv(shield[i]);
      
    }
    glEnd();
    
}

void draw_ring(void) {
    for (int r=0; r<360; r+=45) {
        glPushMatrix();
        glRotated(r, 0, 0, 1);
        glTranslated(0, 35, 0);
        draw_shield();
        glPopMatrix();
    }
    for (int r=0; r<360; r+=45) {
        glPushMatrix();
        glRotated(r, 0, 0, 1);
        glTranslated(0, 35, 0);
        draw_border(true);
        draw_border(false);
        glPopMatrix();
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    for (int i=0; i<9; i++) {
        glColor3f(0.25,0.41,0.88);
        glPushMatrix();
        if (i<4) {
            glTranslated((i-2)*120, 0, 0);
        }
        else if (i == 4) {
            glTranslated((2-i)*120, (2-i)*75, 0);
        }
        else {
            glTranslated((((i-2)/2)-2)*120, -150, 0);
        }
        draw_ring();
        glPopMatrix();
    }
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Project2");
    glClearColor(0.6, 0.6, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-300, 300, -300, 300, 0, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
