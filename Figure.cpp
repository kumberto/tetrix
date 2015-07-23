#include "Figure.h"

Figure::Figure(){
	//x1 = x2 = x3 = x4 = 0;
	//y1 = y2 = y3 = y4 = 0;
	
}

Figure::~Figure(void){
}

void Figure::rotation(){
	switch(shape) {
		case line:
			if ( rotate == 0) {
				y1 = y3 = y4 = y2;
				x1 = x2 - 1;
				x3 = x2 + 1;
				x4 = x2 + 2;
				rotate = 1;
			} else {
				x1 = x3 = x4 = x2;
				y1 = y2 - 1;
				y3 = y2 + 1;
				y4 = y2 + 2;
				rotate = 0;
			}
			break;
		case square:
			break;
		case pyramide:
			if ( rotate == 0 ) {
				x3 = x4 = x2 = x1 - 1;
				y2 = y1 - 1;
				y3 = y1;
				y4 = y1 + 1;
				rotate = 1;
			} else if ( rotate == 1 ) {
				x2 = x1 + 1;
				x3 = x1;
				x4 = x1 - 1;
				y3 = y4 = y2 = y1 - 1;
				rotate = 2;
			} else if ( rotate == 2 ) {
				x3 = x4 = x2 = x1 + 1;
				y2 = y1 + 1; 
				y3 = y1;
				y4 = y1 - 1;
				rotate = 3;
			} else {
				y3 = y4 = y2 = y1 + 1;
				x2 = x1 - 1;
				x3 = x1;
				x4 = x1 + 1;
				rotate = 0;
			}
			break;
		case rightL:
			if ( rotate == 0 ) {
				y1 = y3 = y2;
				x1 = x2 + 1;
				x4 = x3 = x2 - 1;
				y4 = y2 + 1;
				rotate = 1;
			} else if ( rotate == 1 ) {
				x1 = x3 = x2;
				x4 = x2 - 1;
				y1 = y2 + 1;
				y3 = y4 = y2 - 1;
				rotate = 2;
			} else if ( rotate == 2 ) {
				y1 = y3 = y2;
				y4 = y2 - 1;
				x1 = x2 - 1;
				x3 = x4 = x2 + 1;
				rotate = 3;
			} else {
				x1 = x3 = x2;
				x4 = x2 + 1;
				y1 = y2 - 1;
				y3 = y4 = y2 + 1;
				rotate = 0;
			}
			break;
		case leftL:
			if ( rotate == 0 ) {
				y1 = y3 = y2;
				y4 = y3 - 1;
				x1 = x2 + 1;
				x3 = x4;
				rotate = 1;
			} else if ( rotate == 1 ) {
				x1 = x3 = x2;
				x4 = x2 + 1;
				y1 = y2 + 1;
				y3 = y4 ;
				rotate = 2;
			} else if ( rotate == 2 ) {
				y1 = y3 = y2;
				y4 = y2 + 1;
				x1 = x2 - 1;
				x3 = x4;
				rotate = 3;
			} else {
				x1 = x3 = x2;
				x4 = x2 - 1;
				y3 = y4;
				y1 = y2 - 1;
				rotate = 0;
			}
			break;
		case leftZ:
			if ( rotate == 0 ) {
				y3 = y2;
				y1 = y2 - 1;
				x1 = x2;
				x3 = x4 = x2 - 1;
				rotate = 1;
			} else {
				x1 = x2 - 1;
				x3 = x2;
				x4 = x2 + 1;
				y1 = y2;
				y3 = y4;
				rotate = 0;
			}
			break;
		case rightZ:
			if ( rotate == 0 ) {
				y1 = y2 - 1;
				y3 =y2;
				x3 = x4 = x2 + 1;
				x1 = x2;
				rotate = 1;
			} else {
				y1 = y2;
				y3 = y4;
				x1 = x2 + 1;
				x3 = x2;
				x4 = x2 - 1;
				rotate = 0;
			}

	}
}
void Figure::newFigure(FigureType t){
	shape = t;
	rotate = 0;

	switch (shape) {
		case line :
			x1 = x2 = x3 = x4 = 6;
			y1 = 1;
			y2 = 2;
			y3 = 3;
			y4 = 4;
		
			break;
		case square:
			x1 = 6; y1 = 1;
			x2 = 7; y2 = 1;
			x3 = 6; y3 = 2;
			x4 = 7; y4 = 2;
			break;
		case rightL:
			x1 = 6; y1 = 1;
			x2 = 6; y2 = 2;
			x3 = 6; y3 = 3;
			x4 = 7; y4 = 3;
			break;
		case leftL:
			x1 = 6; y1 = 1;
			x2 = 6; y2 = 2;
			x3 = 6; y3 = 3;
			x4 = 5; y4 = 3;
			break;
		case rightZ:
			x1 = 7; y1 = 1;
			x2 = 6; y2 = 1;
			x3 = 6; y3 = 2;
			x4 = 5; y4 = 2;
			break;
		case leftZ:
			x1 = 5; y1 = 1;
			x2 = 6; y2 = 1;
			x3 = 6; y3 = 2;
			x4 = 7; y4 = 2;
			break;
		case pyramide:
			x1 = 6; y1 = 1;
			x2 = 5; y2 = 2;
			x3 = 6; y3 = 2;
			x4 = 7; y4 = 2;
			break;

	}
}

FigureType Figure::getShape() const {
	return shape;
}

void Figure::viewFigurePole(FigureType t) {
	shape = t;
	switch (shape) {
		case line :
			x1 = x2 = x3 = x4 = 17;
			y1 = 1;
			y2 = 2;
			y3 = 3;
			y4 = 4;
		
			break;
		case square:
			x1 = 16; y1 = 2;
			x2 = 16; y2 = 3;
			x3 = 17; y3 = 2;
			x4 = 17; y4 = 3;
			break;
		case rightL:
			x1 = 17; y1 = 2;
			x2 = 17; y2 = 3;
			x3 = 17; y3 = 4;
			x4 = 18; y4 = 4;
			break;
		case leftL:
			x1 = 17; y1 = 2;
			x2 = 17; y2 = 3;
			x3 = 17; y3 = 4;
			x4 = 16; y4 = 4;
			break;
		case rightZ:
			x1 = 18; y1 = 2;
			x2 = 17; y2 = 2;
			x3 = 17; y3 = 3;
			x4 = 16; y4 = 3;
			break;
		case leftZ:
			x1 = 16; y1 = 2;
			x2 = 17; y2 = 2;
			x3 = 17; y3 = 3;
			x4 = 18; y4 = 3;
			break;
		case pyramide:
			x1 = 17; y1 = 2;
			x2 = 16; y2 = 3;
			x3 = 17; y3 = 3;
			x4 = 18; y4 = 3;
			break;

	}
}
void Figure::rollbackRotate(){
	if (rotate == 1) {
		if ( shape == 0 || shape == 5 || shape == 6 ) {
			rotate = 3;
		}else {
			rotate = 1;
		}
	} else if ( rotate == 2 ) {
		if ( shape == 0 || shape == 5 || shape == 6 ) {
			rotate = 0;
		}
	}else if ( rotate == 3 ) {
		if ( shape == 0 || shape == 5 || shape == 6 ) {
			rotate = 1;
		}
	} else {
		if ( shape == 0 || shape == 5 || shape == 6 ) {
			rotate = 2;
		}else {
			rotate = 0;
		}
	}
	rotation();
}
int Figure::getX1()const {
	return x1;
}
int Figure::getX2()const {
	return x2;
}
int Figure::getX3() const{
	return x3;
}
int Figure::getX4() const{
	return x4;
}
int Figure::getY1() const{
	return y1;
}
int Figure::getY2() const{
	return y2;
}
int Figure::getY3() const{
	return y3;
}
int Figure::getY4() const{
	return y4;
}

void Figure::setX1(int i) {
	x1 += i;
}
void Figure::setX2(int i) {
	x2 += i;
}
void Figure::setX3(int i) {
	x3 += i;
}
void Figure::setX4(int i) {
	x4 += i;
}
void Figure::setY1(int i) {
	y1 += i;
}
void Figure::setY2(int i) {
	y2 += i;
}
void Figure::setY3(int i) {
	y3 += i;
}
void Figure::setY4(int i) {
	y4 += i;
}