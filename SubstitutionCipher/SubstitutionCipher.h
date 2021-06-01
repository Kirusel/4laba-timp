/**
 * @class SubstitutionCipher
 * @author Kirill Koltunov 20PT1
 * @date 06/01/21
 * @file SubstitutionCipher.h
 * @brief Header file for SubstitutionCipher
 */
#pragma once
#include <string>
using namespace std;

// @brief Класс для шифрования и расшифрования шифра табличной маршрутной перестановки

class SubstitutionCipher
{
private:
/// @brief атрибут, хранящий ключ для шифрования или расшифрования
    int key;

public:
/// @brief Запрещающий конструктор 
    SubstitutionCipher() = delete;
    /// @brief Конструктор для ключа
     /**@param целочисленное число ключ
     * @details число, которое пришло на вход записывается в "private" атрибут с названием "key"
     */	
    SubstitutionCipher(int k);
   /** @brief Метод , предназначенный для шифрования шифром табличной маршрутной перестановки
     *@param экземляр класса "SubstitutionCipher", в котором установился ключ
     *@param std::wstring - строка, которую нужно зашифровать
     * @details
     * <p>вычисляется количество строк для таблицы по формуле.
     * @code
     * const int stroki = ((data.size()-1)/key.key)+1; // количество строк по формуле
     *@endcode
     * Затем создаётся двумерный массив типа "wchar_t", который имеет необходимый размер:
     * количество строк вычисляется по формуле, а количество столбцов - это ключ, который устанавливается в экземляре класса "PermutationCipher".</p>
     * @code
     * wchar_t matr[stroki][key.key];
     *@endcode
     * <p> созданный двумерный массив записываются символы строки. Запись символов просходит слева-направа. 
     * @code
     * for (auto i = 0; i <stroki; i++) {
     *  for (auto j = 0; j < key.key; j++ ) {
     *     }
     * }
     *@endcode
     *</p>
     * <p>символы, которые находятся в двумерном массиве записываются в строку типа
     * wstring с именем "Result" сверху-вниз.
     * @code
     * for (auto i = 0; i < key.key; i++) {
     *   for (auto j = 0; j < stroki; j++ ) {
     *       if (index <= data.size())
     *          Result.push_back(matr[j][i]);
     *           index++;
     *      }
     *   }
     * @endcode
     *</p>
     * @return зашифрованная строка типа "wstring"
     */    
	wstring Encode(SubstitutionCipher key, wstring& data);
    /** @brief Метод , предназначенный для расшифрования шифра табличной маршрутной перестановки
     *@param экземляр класса "PermutationCipher", в котором установился ключ
     *@param std::wstring - строка, которую нужно расшифровать
     * @details
     * <p>Сначала вычисляется количество строк для таблицы по формуле.
     * @code
     * const int stroki = ((data.size()-1)/key.key)+1; // количество строк по формуле
     *@endcode
     * Затем создаётся двумерный массив типа "wchar_t", который имеет необходимый размер:
     * количество строк вычисляется по формуле, а количество столбцов - это ключ, который устанавливается в экземляре класса "PermutationCipher".</p>
     * @code
     * wchar_t matr[stroki][key.key];
     *@endcode
     * <p>Далее в созданный двумерный массив записываются символы строки, которую нужно расшифровать. Запись символов просходит
     * сверху-вниз. То есть, запись происходит по столбцам.
     * @code
     * for (auto i = 0; i < key.key; i++) {
     *  for (auto j = 0; j < stroki; j++ ) {
     *      }
     * }
     *@endcode
     *</p>
     * <p>В конечном итоге происходит процесс расшифрования. символы, которые находятся в двумерном массиве записываются в строку типа
     * wstring с именем "Result" слева-направа.
     * @code
     * for(auto i = 0; i < stroki; i++) {
     *   for (auto j = 0; j< key.key; j++) {
     *       if (index<data.size())
     *           Result.push_back(matr[i][j]);
     *          index++;
     *     }
     *   }
     * @endcode
     *</p>
     * @return расшифрованная строка типа "wstring"
     */	
    wstring Decode(SubstitutionCipher key, wstring& data);
};