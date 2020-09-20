#include <iostream>
#include <Windows.h>



int main() {
	HWND hwnd = GetConsoleWindow(); //���� �������� �� ���������� ���� (� �� ����� ��������)
	HDC dc = GetDC(hwnd); //��������� � ����������� ����
	RECT window = {}; //���������� window ����� ������������ ��� ��������� ������ � ������ ����
	HBRUSH brush; //���������� brush - ��� �����, ��� ����� �������������� ��� ������������


	brush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 255, 0)); // ������ ����� ������������ ����� � �����
	SelectObject(dc, brush); //�������� �����
	RECT WinCoord = {}; //������ ��������� ���� 
	GetWindowRect(hwnd, &WinCoord); //����� ����������

	brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(dc, brush); //�������� �����
	Rectangle(dc, 50, 0, 440, 150); //���������� �������������, ����������� ����� ������		
	DeleteObject(brush); //������� ������ �� ���������, �� ��� �������� �����

	brush = CreateSolidBrush(RGB(188, 0, 45)); //������ ����� ������������ ����� � �����
	SelectObject(dc, brush); //�������� �����
	Ellipse(dc, 200, 20, 300, 120); 
	DeleteObject(brush); //������� ������ �� ���������, �� ��� �������� �����

	ReleaseDC(hwnd, dc); //����������� ����� ��� ������� (�� �������� �� ����� ��� �����������) �������� ���p������, ����� ��� ��������� ��� �p���� �p�������� �����. 

	std::cin.get();
}