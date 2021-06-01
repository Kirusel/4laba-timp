/**
 * @class Exception
 * @author Kirill Koltunov 20PT1
 * @date 06/01/21
 * @file Exception.h
 * @brief Header file for Exception
 */
#pragma once
#include <string>
#include <iostream>
using namespace std;
///@brief класс для иcключений
class Exception
{
protected:
    string error; ///< @brief атрибут, хранящий описание ошибки
    int num;  ///< @brief атрибут, хранящий информацию о коде ошибки  
    string correction;  ///< @brief атрибут, хранящий информацию об исправлении ошибки
public:
///@brief Предназначен для вывода описания ошибки.
    virtual string what () = 0; 
///@brief виртуальный метод. Предназначен для вывода кода ошибки. 	
    virtual int code () = 0;
 ///@brief виртуальный метод. Предназначен для вывода информации об исправлении ошибки.    
	virtual string fix () = 0;
};
