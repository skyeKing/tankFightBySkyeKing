// tankFightOfSkyeKing.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include <conio.h>
#include <graphics.h>
using namespace std;
enum tankDirection
{

	left = 37,
	top,
	right,
	down
};
enum tankState {
	idle,
	move,
	attack
};
class Tank
{
public:
	Tank(int x, int y ,int sZ);
	~Tank();
	int getDirect();
	int getPositionX();
	int getPositionY();
	int getState();
	int getScaleSize();
	void move(int direct, int pixelX, int pixelY);
private:
	int partA[8] = { -4, -3, -4, 3, -2, 3, -2, -3};//left track
	int partB[8] = { -2, 2, 2, 2, 2, -2, -2, -2 };//middle part
	int partC[8] = { 2, 3, 4, 3, 4, -3, 2, -3 };//right track
	int partD[8] = { 1, -2, 1, -5, -1, -5, -1, -2 };//gun
	int tempPartA[8], tempPartB[8], tempPartC[8], tempPartD[8];//record the currentPoints position
	int positionX = 0, positionY = 0;
	int pivotX = 0, pivotY = 0;
	int boundingBoxMaxX = 4, boundingBoxMinX = -4, boundingBoxMaxY = 3, boundingBoxMinY = -5;
	int scaleSize = 1;	
	int currentState = idle;
	int currentDirect = top;
	void updateBBPosition(int x, int y);
	void updatePointsPosition(int x, int y);
	void initSize(int sZ=1);//init boundingBoxSize and pointsSize
};
int Tank::getDirect() {	return currentDirect;}
int Tank::getPositionX() {	return positionX;}
int Tank::getPositionY() {	return positionY;}
int Tank::getState() {	return currentState;}
int Tank::getScaleSize() {	return scaleSize;}
void Tank::move(int direct, int pixelX,int pixelY) {
	if (direct == getDirect() && pixelX || pixelY) {//方向相同，并且有像素数值
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(boundingBoxMinX, boundingBoxMaxY, boundingBoxMaxX, boundingBoxMinY);
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 0)
				partA[i] += pixelX;
			else
				partA[i] += pixelY;
		}
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 0)
				partB[i] += pixelX;
			else
				partB[i] += pixelY;
		}
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 0)
				partC[i] += pixelX;
			else
				partC[i] += pixelY;
		}
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 0)
				partD[i] += pixelX;
			else
				partD[i] += pixelY;
		}
		//set fill color
		setlinecolor(BLACK);
		setfillcolor(WHITE);
		// fill the polygon belong the points
		fillpolygon((POINT*)partA, 4);
		fillpolygon((POINT*)partB, 4);
		fillpolygon((POINT*)partC, 4);
		fillpolygon((POINT*)partD, 4);

	}
}
void Tank::initSize(int sZ) {
	scaleSize = sZ;	
	boundingBoxMaxX *= scaleSize;
	boundingBoxMinX *= scaleSize;
	boundingBoxMaxY *= scaleSize;
	boundingBoxMinY *= scaleSize;
	for (int i = 0; i < 8; i++) {
		partA[i] *= scaleSize;
		partB[i] *= scaleSize;
		partC[i] *= scaleSize;
		partD[i] *= scaleSize;
	}
}
void Tank::updateBBPosition(int x,int y) {
	boundingBoxMaxX += x;
	boundingBoxMinX += x;
	boundingBoxMaxY += y;
	boundingBoxMinY += y;
}
void Tank::updatePointsPosition(int x, int y) {//update bbox position and points position;
	positionX = x;
	positionY = y;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0)
			partA[i] += positionX;
		else
			partA[i] += positionY;
	}
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0)
			partB[i] += positionX;
		else
			partB[i] += positionY;
	}
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0)
			partC[i] += positionX;
		else
			partC[i] += positionY;
	}
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0)
			partD[i] += positionX;
		else
			partD[i] += positionY;
	}
	updateBBPosition(positionX, positionY);
}
Tank::Tank(int x, int y,int sZ) :positionX(x),positionY(y)
{

	initSize(sZ);
	updatePointsPosition(positionX, positionY);
	//set fill color
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	// fill the polygon belong the points
	fillpolygon((POINT*)partA, 4);
	fillpolygon((POINT*)partB, 4);
	fillpolygon((POINT*)partC, 4);
	fillpolygon((POINT*)partD, 4);
}
Tank::~Tank()
{
}
int main()
{
	int windowWidth = 640;
	int windowHigh = 480;
	initgraph(windowWidth, windowHigh);
	Tank gameplay(320,240,2);
	Tank gameplay2(220, 240, 2);
	//cout << "tank position:X" << gameplay.getPositionX << " Y" << gameplay.getPositionY << endl;
	for (int i = 0; i < 100; i++) {
		gameplay.move(top, 0, 1);
		Sleep(100);
		//cout << "tank position:X" << gameplay.getPositionX << " Y" << gameplay.getPositionY << endl;
	}
	_getch();
	closegraph();
	return 0;
}

