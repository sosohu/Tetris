#include <GL/glut.h>
#include "frame.h"
#include "graph.h"
#include "alarm.h"
#include "log.h"
#include <iostream>

using namespace std;

const int X = 0;
const int Y = 0;
const int WIDTH = 500;
const int HEIGHT = 600;

BodyFrame bf(WIDTH, HEIGHT, X, Y);

void Initial(void){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	
	bf.setBodyFrameColor(PURPLE);
	bf.setSquareFrameColor(BLACK, BLACK, GRAY);
	bf.setNextFrameColor(BLACK, BLACK, GRAY);
	bf.setScoreFrameColor(BLACK, GRAY);
}

void ChangeSize(int w, int h){
	int winWidth = w;
	int winHeight = h;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}

Log *pLog = Log::getLogInstance();

void alarm_func(int signo){
	bf.update();
	pLog->Print(DEBUG, "alarm_func exec");
	alarm(1);
	drawBodyFrame(bf);
	glutSwapBuffers();
}

Alarm alarmObj(alarm_func, 1);

void Display(void){
	glClear(GL_COLOR_BUFFER_BIT);

	alarmObj.start();

	//drawBodyFrame(bf);

	//glutSwapBuffers();
}

void specialKeyFunc(int key,int x,int y){
	pLog->Print(DEBUG, "Special Key: %d", key);
	switch(key){
		case GLUT_KEY_LEFT:	bf.leftShift(); break;
		case GLUT_KEY_RIGHT:	bf.rightShift(); break;
		case GLUT_KEY_DOWN:	bf.downShift(); break;
		default:	;
	}
}

void normalKeyFunc(unsigned char key, int x, int y){
	pLog->Print(DEBUG, "Normal Key: %d", key);
	switch(key){
		case 32: bf.changeFollow(); break;
		default:	;
	}
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
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("俄罗斯方块");
	glutDisplayFunc(&Display);

	glutReshapeFunc(ChangeSize);//回调函数
	glutSpecialFunc(&specialKeyFunc);
	glutKeyboardFunc(&normalKeyFunc);
	//glutMouseFunc(MousePlot);//指定鼠标点击响应函数
	//glutPassiveMotionFunc(PassiveMouseMove);//指定鼠标移动响应函数
	Initial();
	glutMainLoop();
	return 0;
}

