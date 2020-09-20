#include <iostream>
#include <Windows.h>



int main() {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	RECT window = {}; //Переменная window будет использована для получения ширины и высоты окна
	HBRUSH brush; //Переменная brush - это кисть, она будет использоваться для закрашивания


	brush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 255, 0)); // Создаём кисть определённого стиля и цвета
	SelectObject(dc, brush); //Выбираем кисть
	RECT WinCoord = {}; //Массив координат окна 
	GetWindowRect(hwnd, &WinCoord); //Узнаём координаты

	brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(dc, brush); //Выбираем кисть
	Rectangle(dc, 50, 0, 440, 150); //Нарисовали прямоугольник, закрашенный неким стилем		
	DeleteObject(brush); //Очищаем память от созданной, но уже ненужной кисти

	brush = CreateSolidBrush(RGB(188, 0, 45)); //Создаём кисть определённого стиля и цвета
	SelectObject(dc, brush); //Выбираем кисть
	Ellipse(dc, 200, 20, 300, 120); 
	DeleteObject(brush); //Очищаем память от созданной, но уже ненужной кисти

	ReleaseDC(hwnd, dc); //Освобождаем общий или оконный (не влияющий на класс или локальность) контекст устpойства, делая его доступным для дpугих пpикладных задач. 

	std::cin.get();
}