/**
 * @class modAlphaCipher
 * @author Kirill Koltunov 20PT1
 * @date 06/01/21
 * @file modAlphaCipher.h
 * @brief Header file for modAlphaCipher
 */
#pragma once
#include <vector>
#include <map>
#include <locale>
#include <cctype>
#include "Exceptions.h"
using namespace std;
/**  @brief  Класс, реализует шифрование методом "Гронсвельда"
* */
class modAlphaCipher
{
private:
    /// @brief  Используемый алфавит для сообщений
    wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    /// @brief  Ассоциативный массив "номер по символу"
    map <char,int> alphaNum;
    /// @brief  Атрибут для ключа
    vector <int> key; //ключ
    /** @brief  Преобразование строки в вектор(чисел)
     * @details В вектор типа "int" с именем "Result" формируются числа, которые являются индексами алфавита "numAlpha" из строки, 
     * которая пришла на вход.
     * @code
     *  vector<int> result;
     *   for(auto c:s) {
     *       result.push_back(alphaNum[c]);
     *   }
     * @endcode
     * @return std::vector <int>, в котором хранятся индексы букв сообщения из алфавита "numAlpha"
     */
    vector<int> convert(const wstring& s); 
     /** @brief Преобразование вектора(чисел) в строку
     * @details В переменную типа "wstring" с именем "Result" формируется строка по индексам алфавита "numAlpha".
     * Индексы хранятся в векторе типа "int", который пришёл на вход.
     * @code
     *  wstring result;
     *   for(auto i:v) {
     *       result.push_back(numAlpha[i]);
     *   }
     * @endcode
     * @return строка текста типа "wstring"
     */
    wstring convert(const vector<int>& v);
    /** @brief  Валидация ключа
     * @details Сначала ключ проверяется на пустоту при помощи обычного условия. Если проверка закончилась успешно, то
     * ключ проверяется на наличие недопустимых символов. 
     * @warning регистр букв русского алфавита не влияет на появление исключений.
     * @param std::wstring s - ключ в виде строки, который нужно проверить на наличие ошибок
     * @throw MyExceptions, если ключ является пустым или в нём присутствуют недопустимые символы
     * @return Ключ в виде строки типа "wstring", который успешно прошёл валидацию
     */
    wstring getValidKey(const wstring & s);
    /** @brief  Валидация текста при шифровании или расшифровании
     * @details Сначала текст проверяется на пустоту при помощи обычного условия. Если проверка закончилась успешно, то
     * текст проверяется на наличие недопустимых символов. 
     * @warning Письменные буквы алфавита переводятся в прописные. То есть регистр букв русского алфавита не влияет на появление исключений.
     * @param std::wstring s - строка текста для шифрования или расшифрования, которую нужно проверить на наличие ошибок
     * @throw MyExceptions, если текст является пустым или в нём присутствуют недопустимые символы
     * @return Текст в виде строки типа "wstring", который успешно прошёл валидацию
     */
    wstring getValidAlphabetText(const wstring & s);
public:
     /// @brief Запрещающий конструктор без параметров
        modAlphaCipher()=delete; 
     /** @brief  Конструктор для ключа
      *    @details Цикл for по строке-алфавиту на каждом шаге добавляет в массив
      *  символ и его номер. массив в данном случае удобен из-за доступа к
      * элементам по индексу-символу
      *  @code
      *     for (unsigned i=0; i<numAlpha.size(); i++) {
      *          alphaNum[numAlpha[i]]=i;
      *      }
      *  @endcode
      *  @param std::wstring - ключ в виде строки
      */ 
    modAlphaCipher(wstring skey); //конструктор для установки ключа
    /**
     * @brief Метод для шифрования
     * @details Здесь формируется вектор work из строки открытого текста с помощью метода
     *   convert().
     *  @code
     *       vector<int> work = convert(getValidAlphabetText(open_text));
     * @endcode
     *  в цикле к каждому элементу вектора прибавляется элемент ключа по модулю размера
     *   алфавита. Так как ключ может быть короче текста, то при индексации ключа выполняется операция
     *   по модулю размера ключа.
     *  @code
     *   for(unsigned i=0; i < work.size(); i++) {
     *      work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
     *   }
     * @endcode
     * вектор work опять преобразуется в строку.
     * @param std::wstring open_text - сообщение, которое нужно зашифровать
     * @throw MyException , если строка, которая пришла на вход оказывается пустой или в ней есть недопустимые символы
     * @return строка шифротекста типа "wstring"
     */
    wstring encrypt(const wstring& open_text); //зашифрование
    /**
     * @brief Метод для расшифрования
     * @details Здесь сначала формируется вектор work из строки  щифратекста с помощью метода
     *   convert().  А также происходит проверка шифротекста на наличие ошибки при помощи метода getValidAlphabetText().
     *  @code
     *       vector<int> work = convert(getValidAlphabetText(cipher_text));
     * @endcode
     *  Если при зашифровывании прибавляли значение ключа, то при расшифровывании значения ключа надо вычитать. выполняется еще прибавление значения модуля, так как такое
     *  прибавление не влияет на результат модулю.
     *  @code
     *   for(unsigned i=0; i < work.size(); i++) {
     *           work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
     *   }
     * @endcode
     *
     *@param std::wstring cipher_text - сообщение, которое нужно расшифровать
     * @throw MyException , если строка, которая пришла на вход оказывается пустой или в ней есть недопустимые символы
     * @return  строка расшифрованного текста типа "wstring"
     */
    wstring decrypt(const wstring& cipher_text);//расшифрование
};