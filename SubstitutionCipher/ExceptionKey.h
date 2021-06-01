/**
 * @class ExceptionKey
 * @author Kirill Koltunov 20PT1
 * @date 06/01/21
 * @file ExceptionKey.h
 * @brief Header file for ExceptionKey
 */
#pragma once
#include "Exception.h"
class ExceptionKey : protected Exception
{
public:
///@brief Запрещающий конструктор 
    ExceptionKey() = delete;
    /**@brief Конструктор с параметрами
     * @param num - целочисленное число, хранящее информацию о коде ошибки.
     * @param error - строка, хранящая описание ошибки.
     * @param correction - строка, хранящая информацию об исправлении ошибки.
     */
    ExceptionKey (const int &num,const string &error, const string& correction);
    string what () override;
    string fix () override;
    int code () override;
	
/**@brief Статический метод, проверяющий ключ при шифровании или расшифровании
     *@details 
     * <p>ключ проверяется на пустоту при помощи обычного условия. Если ключ является пустым, то возбуждается исключение типа "ExceptionKey".
     * Далее ключ проверяется на допустимые символы при помощи обычного условия. если в ключе присутствуют символы каких-либо
     * алфавитов или специальные символы, то вобуждается исключение типа "ExceptionKey.</p>
     * <p>ключ проверяется на нужный размер и на натуральность при помощи обычного условия. Если ключ
     * является ненатуральным числом или не соотвествует нужному размеру, то вобуждается исключение типа "ExceptionKey.</p>
     * <p>Ключ является корректным если он является натуральным числом и не превышает размера строки для шифрования или расшифрования.</p>
     * @param data - std::wstring, строка, которую нужно зашифровать или расшифровать.
     * @param str_key - std::string, ключ, который нужно проверить при шифровании или расшифровании.
     * @return значение "true", если проверки завершились успешно.
     * @throw  ExceptionKey, если:
     *   - ключ оказался пустым;<br>
     *   - в ключе присутствует недопустимые символы;<br>
     *   - ключ не соответствует нужному размеру.
     */	

    static bool check_key (const wstring &data,const string str_key);
};