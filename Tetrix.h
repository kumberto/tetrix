
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
		void checkInLine();// ��������� ���������� �����
		void deleteLine( int i);// ������� ����� � ����������� ����
		virtual void KeyPressed(int btnCode);
		virtual void UpdateF(float deltaTime);
		void createPanel(); //������� ������� ����
		void stockFill();//��������� ������ ������
		bool fillPlayField();// �������� ���������� ���� � ����
		bool checkLeftMove();// �������� ����������� � ����
		bool checkRightMove();//�������� ����������� � �����
		bool checkRotate();// �������� ����������
		void clearPanel();// ������� ������� ����
		void initialCoordinate(); //������������� ���������� ���������
		void playStockFill();//���������� ���� 
};
