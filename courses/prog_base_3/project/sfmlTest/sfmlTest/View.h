#include <SFML/Graphics.hpp>
#include "PointF.h"

using namespace sf;

View view;

View getplayercoordinateforview(PointF point) { //������� ��� ���������� ��������� ������
	view.setCenter(point.x+750, point.y+375); //������ �� �������, ��������� ��� ���������� ������. +100 - �������� ������ �� ���� ������. �����������������
	return view;

}


View viewmap(float time) { //������� ��� ����������� ������ �� �����. ��������� ����� sfml


	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move(0.1*time, 0);//�������� ����� ������ (�� ����, ����� �� ������� ����� - �� ���� �����)
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, 0.1*time);//�������� ����� ���� (�� ����, ����� �� ������� ����� - �� ���� �����)
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move(-0.1*time, 0);//�������� ����� ����� (�� ����, ����� �� ������� ����� - �� ���� �����)
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, -0.1*time);//�������� ����� ������ (�� ����, ����� �� ������� ����� - �� ���� �����)
	}
	return view;

}