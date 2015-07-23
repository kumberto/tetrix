#pragma once
#ifndef FIGURE_H
#define FIGURE_H

#include "Enum.cpp"

class Figure
{
private:
	FigureType shape;
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	int rotate;
public:
	Figure();
	~Figure(void);
	void rotation();// �������
	void newFigure(FigureType t);// �������� ������ ��������� ����
	FigureType getShape()const;
	void viewFigurePole(FigureType t); //�������� ������ ��� ���� �����������
	void rollbackRotate();// ������� � ����������� ��������� ��� ����������� ��������
	int getX1() const;
	int getX2() const;
	int getX3() const;
	int getX4() const;
	int getY1() const;
	int getY2() const;
	int getY3() const;
	int getY4() const;

	void setX1(int i);
	void setX2(int i);
	void setX3(int i);
	void setX4(int i);
	void setY1(int i);
	void setY2(int i);
	void setY3(int i);
	void setY4(int i);
};
#endif