#include <iostream>
#include <string>
#include "routeCipher.h"

using namespace std;

int main() {
    // Включаем русскую кодировку в консоли
    system("chcp 1251 > nul");

    // Задаем значения для красивого скриншота
    int key = 3; 
    string text = "ПРИВЕТ"; 

    cout << "=== Шифр табличной маршрутной перестановки ===" << endl;
    cout << "Введите ключ (количество столбцов таблицы): " << key << endl;
    cout << "Введите текст для шифрования (можно с пробелами): " << text << endl;

    try {
        routeCipher cipher(key);
        
        string encrypted = cipher.encrypt(text);
        cout << "\n[Зашифрованный текст]:\n" << encrypted << endl;

        string decrypted = cipher.decrypt(encrypted);
        cout << "\n[Расшифрованный текст]:\n" << decrypted << endl;

        if (text == decrypted) {
            cout << "\n[Проверка]: Успешно! Тексты совпадают." << endl;
        } else {
            cout << "\n[Проверка]: Ошибка! Тексты не совпадают." << endl;
        }
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}