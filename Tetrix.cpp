#include "Tetrix.h"
#include <cstdio>



Tetrix::Tetrix() : BaseApp(80, 40)
{
	createPanel();
	t = FigureType(rand()%7);
	followFigure = FigureType(rand()%7);
	next.viewFigurePole(followFigure);
	shape.newFigure(t);
	initialCoordinate();
	account = 0;
	SetChar(next.getX1(), next.getY1(), '*');
	SetChar(next.getX2(), next.getY2(), '*');
	SetChar(next.getX3(), next.getY3(), '*');
	SetChar(next.getX4(), next.getY4(), '*');
	SetChar(16, 7, account);
}

void Tetrix::checkInLine() {
	int line = 0;
	int scope = 0;
	for ( int i = 19; i > 1; i-- ) {
		for ( int j = 1; j < 14; j++) {
			if (stock[j][i] == true) {
				scope += 1;
				
			} else {
				scope = 0;
				j = 13;
			}
			if ( scope == 13 ) {
				deleteLine(i);
				j = 13;
				i += 1;
				line += 1;
				account += 13;
				
			}
		}
		
		scope = 0;
	}
	if ( line > 1 ) {
		account = account + ( (13 * line / 100) * line);
	}
	SetChar(16, 7, ' ');
	SetChar(17, 7, ' ');
	SetChar(18, 7, ' ');
	SetChar(16, 7, account);
}

void Tetrix::deleteLine(int i) {
	for ( ; i > 1  ; i-- ) {
		int k = i - 1;
		for ( int j = 1; j < 14; j++ ) {
			stock[j][i] = stock[j][k];
		}
	}
	clearPanel();
	playStockFill();
}


void Tetrix::KeyPressed(int btnCode)
{
	if (btnCode == 115) //down
	{
		
	}
	else if (btnCode == 97 && checkLeftMove() ) //left
	{
		shape.setX1(-1);
		shape.setX2(-1);
		shape.setX3(-1);
		shape.setX4(-1);
		SetChar(shape.getX1()+1, shape.getY1(), ' ');
		SetChar(shape.getX2()+1, shape.getY2(), ' ');
		SetChar(shape.getX3()+1, shape.getY3(), ' ');
		SetChar(shape.getX4()+1, shape.getY4(), ' ');
	
	}
	else if ( btnCode == 100 && checkRightMove() ) //right
	{
		shape.setX1(1);
		shape.setX2(1);
		shape.setX3(1);
		shape.setX4(1);
		SetChar(shape.getX1()-1, shape.getY1(), ' ');
		SetChar(shape.getX2()-1, shape.getY2(), ' ');
		SetChar(shape.getX3()-1, shape.getY3(), ' ');
		SetChar(shape.getX4()-1, shape.getY4(), ' ');
 	}else if ( btnCode == 32 )
	{
		SetChar(shape.getX1(), shape.getY1(), ' ');
		SetChar(shape.getX2(), shape.getY2(), ' ');
		SetChar(shape.getX3(), shape.getY3(), ' ');
		SetChar(shape.getX4(), shape.getY4(), ' ');
		if (checkRotate()) {
			SetChar(shape.getX1(), shape.getY1(), ' ');
			SetChar(shape.getX2(), shape.getY2(), ' ');
			SetChar(shape.getX3(), shape.getY3(), ' ');
			SetChar(shape.getX4(), shape.getY4(), ' ');
 			shape.rotation();
		}
	}
}

void Tetrix::UpdateF(float deltaTime)
{
	SetChar(shape.getX1(), shape.getY1(), ' ');
	SetChar(shape.getX2(), shape.getY2(), ' ');
	SetChar(shape.getX3(), shape.getY3(), ' ');
	SetChar(shape.getX4(), shape.getY4(), ' ');
	
	if (fillPlayField())
	{
		shape.setY1(1);
		shape.setY2(1);
		shape.setY3(1);
		shape.setY4(1);
	}
	else
	{
		SetChar(next.getX1(), next.getY1(), ' ');
		SetChar(next.getX2(), next.getY2(), ' ');
		SetChar(next.getX3(), next.getY3(), ' ');
		SetChar(next.getX4(), next.getY4(), ' ');

 		checkInLine();
		t = followFigure;
		shape.newFigure(t);
		initialCoordinate();
		followFigure = FigureType(rand()%7);
		next.viewFigurePole(followFigure);

		SetChar(next.getX1(), next.getY1(), '*');
		SetChar(next.getX2(), next.getY2(), '*');
		SetChar(next.getX3(), next.getY3(), '*');
		SetChar(next.getX4(), next.getY4(), '*');
	}

	SetChar(shape.getX1(), shape.getY1(), '*');
	SetChar(shape.getX2(), shape.getY2(), '*');
	SetChar(shape.getX3(), shape.getY3(), '*');
	SetChar(shape.getX4(), shape.getY4(), '*');
}

void Tetrix::stockFill() {
	for ( int  i = 0; i < 21; i++ ) {
		for ( int j = 0; j < 15; j++ ) {
			
			if ( i == 0 || j == 0 || i == 20 || j == 14) {
				stock [j][i] = true;
			} else {
				stock [j][i] = false;
			}
		}
	}
}

void Tetrix::createPanel() {
	stockFill();
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 15; j++) {
			if ( i == 0 || j == 0 || i == 20 || j == 14) {
				SetChar(j, i, '#');
			}  
		}
	}
	for ( int i = 0; i < 9; i++ ) {
		for ( int j = 15; j < 22; j++ ) {
			if ( i == 0 || i == 5 || i == 8 || j == 21 ) {
				SetChar(j, i, '#');
			} 
		}
	}
}

bool Tetrix::fillPlayField() {
	if ( stock[shape.getX1()][shape.getY1()+1] == false && stock[shape.getX2()][shape.getY2()+1] == false && stock[shape.getX3()][shape.getY3()+1] == false && stock[shape.getX4()][shape.getY4()+1] == false ) {
		return true;
	} else if ( stock[shape.getX1()][shape.getY1()] == true && stock[shape.getX2()][shape.getY2()] == true && stock[shape.getX3()][shape.getY3()] == true && stock[shape.getX4()][shape.getY4()] == true ) {
		clearPanel();
		stockFill();
		return false;
	} else {
		if ( shape.getY1() != 1 || shape.getY2() != 1 ) {
			stock[shape.getX1()][shape.getY1()] = true;
			stock[shape.getX2()][shape.getY2()] = true;
			stock[shape.getX3()][shape.getY3()] = true;
			stock[shape.getX4()][shape.getY4()] = true;
			SetChar(shape.getX1(), shape.getY1(), '*');
			SetChar(shape.getX2(), shape.getY2(), '*');
			SetChar(shape.getX3(), shape.getY3(), '*');
			SetChar(shape.getX4(), shape.getY4(), '*');
		}
		if ( stock[initialCoordinateX1][initialCoordinateY1 - 1] == true && (stock[shape.getX4()][shape.getY4()+1] == true || stock[shape.getX3()][shape.getY3()+1] == true ) && shape.getY1() == 1 ) {
			clearPanel();
			stockFill();
		}
	}
	return false;
}

bool Tetrix::checkLeftMove(){
	if ( shape.getX1() == 1 || shape.getX2() == 1 || shape.getX3() == 1 || shape.getX4() == 1 )
	{
		return false;
	} else if ( stock[shape.getX1()-1][shape.getY1()] == true || stock[shape.getX2()-1][shape.getY2()] == true || stock[shape.getX3()-1][shape.getY3()] == true || stock[shape.getX4()-1][shape.getY4()] == true ) {
		return false;
	}
	return true;
}
bool Tetrix::checkRightMove(){
	if ( shape.getX1() == 13 || shape.getX2() == 13 || shape.getX3() == 13 || shape.getX4() == 13 )
	{
		return false;
	}else if ( stock[shape.getX1()+1][shape.getY1()] == true || stock[shape.getX2()+1][shape.getY2()] == true || stock[shape.getX3()+1][shape.getY3()] == true || stock[shape.getX4()+1][shape.getY4()] == true ) {
		return false;
	}
	return true;
}

bool Tetrix::checkRotate() {
	shape.rotation();
	if (stock[shape.getX1()][shape.getY1()] == false && stock[shape.getX2()][shape.getY2()] == false && stock[shape.getX3()][shape.getY3()] == false && stock[shape.getX4()][shape.getY4()] == false ) {
		shape.rollbackRotate();
		return true;
	}
	shape.rollbackRotate();
	return false;
	
}


void Tetrix::clearPanel() {
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 14; j++) {
				SetChar(j, i, ' ');
		}
	}
}

void Tetrix::initialCoordinate(){
	initialCoordinateX1 = shape.getX1();
	initialCoordinateY1 = shape.getY1();
}

void Tetrix::playStockFill() {
	for ( int j = 1; j < 20; j++ ) {
		for (int i = 1; i < 14; i++ ) {
			if ( stock[i][j] == true ) {
				SetChar(i, j, '*');
			} else {
				SetChar(i, j, ' ');
			}
		}
	}
}