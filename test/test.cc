#include <GL/glut.h>
#include "frame.h"
#include "graph.h"
#include <iostream>

using namespace std;

const int X = 100;
const int Y = 100;
const int WIDTH = 800;
const int HEIGHT = 1400;

BodyFrame bf(700, 1300, X + 50, Y + 50);

void Initial(void){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}


void ChangeSize(int w, int h){
	int winWidth = w;
	int winHeight = h;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}

void Display(void){
	glClear(GL_COLOR_BUFFER_BIT);

	drawBodyFrame(bf);

	glutSwapBuffers();
}


/*响应鼠标函数
void MousePlot(GLint button, GLint action, GLint xMouse, GLint yMouse){
	//左键点击
	if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
		//cout<<"asdf"<<endl;
	//	cout<<flag<<endl;
		if(flag == 0){
			//cout<<"123"<<endl;
			flag = 1;
			Rect[n].x1 = xMouse;
			Rect[n].y1 = winHeight - yMouse;
			cout<<Rect[n].x1<<"  "<<Rect[n].y1<<endl;
			
		}else {
			//cout<<"345"<<endl;
			flag = 0;
			Rect[n].x2 = xMouse;  
            Rect[n].y2 = winHeight - yMouse;  
			
	        n++;  
            glutPostRedisplay(); 
            // 
            //Rect[n].x1 = Rect[n-1].x2;  
           // Rect[n].y1 = Rect[n-1].y2; 
		}
	
	}
	//右键点击
	if(button == GLUT_RIGHT_BUTTON && action == GLUT_DOWN){
		flag = 0;
		n = 0;
		glutPostRedisplay();	
	}

}

// 鼠标移动函数
void PassiveMouseMove(GLint xMouse, GLint yMouse){
	//
	if(flag == 1){
		tempX = xMouse;
		tempY = winHeight - yMouse;
// 	Rect[n].x2 = xMouse;
// 	Rect[n].y2 = winHeight - yMouse;
		glutPostRedisplay();
	}
	
}
*/

//
int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 2000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("俄罗斯方块");
	glutDisplayFunc(&Display);

	glutReshapeFunc(ChangeSize);//回调函数
	//glutMouseFunc(MousePlot);//指定鼠标点击响应函数
	//glutPassiveMotionFunc(PassiveMouseMove);//指定鼠标移动响应函数
	Initial();
	glutMainLoop();
	return 0;
}

