
#pragma once
#include "BaseApp.h"
#include "Figure.h"
#include "Enum.cpp"

class Tetrix : public BaseApp
{
	typedef BaseApp Parent;

	private:
		FigureType t;
		Figure shape;
		FigureType followFigure;
		Figure next;
		bool stock[15][21];
		int initialCoordinateX1;
		int initialCoordinateY1;
		int account;
	public:
		Tetrix();
		void checkInLine();// проверяет заполнение линии
		void deleteLine( int i);// удаляет линию и перестраива поле
		virtual void KeyPressed(int btnCode);
		virtual void UpdateF(float deltaTime);
		void createPanel(); //создает игровое поле
		void stockFill();//заполняет массив нулями
		bool fillPlayField();// проводит построение поля в игре
		bool checkLeftMove();// проверка перемешения в лево
		bool checkRightMove();//проверка перемещения в право
		bool checkRotate();// проверка переворота
		void clearPanel();// очищает игровое поле
		void initialCoordinate(); //инициализация предидущих координат
		void playStockFill();//заполнение поля 
};
