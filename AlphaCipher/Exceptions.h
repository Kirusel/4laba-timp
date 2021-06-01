/**
 * @class MyExceptions
 * @author Kirill Koltunov 20PT1
 * @date 06/01/21
 * @file Exceptions.h
 * @brief Header file for MyExpections
 */
#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;
/// @brief  Класс для обработки ошибок
class MyExceptions : public invalid_argument
{
private:
    int num; ///< атрибут, хранящий код ошибки
    string correction; ///< атрибут, хранящий информацию об исправлении ошибки
public:
    /// @brief  Запрещающий конструктор
    MyExceptions() = delete;
    /** @brief  Конструктор с параметрами
     * @param num - целочисленное число, хранящее информацию о коде ошибки
     * @param error - строка, хранящая описание ошибки. 
     * @param correction - строка, хранящая информацию об исправлении ошибки
     */
    MyExceptions (const string & error, const int &num, const string &fix);
     /// @brief  Предназначен для вывода информации об исправлении ошибки
    void fix ();
    /// @brief  Предназначен для вывода кода ошибки
    void code ();
};