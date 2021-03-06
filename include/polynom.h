﻿#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include "monom.h"
#include "list.h"

#define OFFSET 120	//Код символа 'x'

//Класс полином
class polynom
{
private:
	list<monom> pmlist;		//Список, содержащий полином
public:
	polynom(const polynom& src) : pmlist(src.pmlist) {}								//Конструктор копирования
	polynom& operator=(const polynom &src) { pmlist = src.pmlist; return *this; }	//Перегрузка оператора присваивания
	friend std::ostream& operator<<(std::ostream &ostr, const polynom &pm);			//Оператор вставки в поток
	friend polynom operator*(const double mp, const polynom& pol) { return pol*mp; }//Умножение на константу с другой стороны
	polynom operator-(const polynom& pml) const { return *this + pml*(-1); }		//Бинарный минус
	polynom operator-() const { return (-1)*(*this); }								//Унарный минус
	polynom(list<monom> &inlist) : pmlist(inlist) {}								//Конструктор по списку
	bool operator==(const polynom& pml) const { return pmlist == pml.pmlist; }		//Операторы
	bool operator!=(const polynom& pml) const { return pmlist != pml.pmlist; }		//Сравнения

	polynom(const std::string ipm = "");					//Конструктор по строке
	polynom operator+(const polynom& pml) const;			//Оператор сложения полиномов
	polynom operator*(const polynom& pml) const;			//Оператор умножения полиномов
	polynom operator*(const double mp) const;				//Умножение на константу
};