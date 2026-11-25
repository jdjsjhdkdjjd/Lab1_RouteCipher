#include "routeCipher.h"
#include <vector>
#include <stdexcept>

routeCipher::routeCipher(int k) {
    if (k <= 0) throw std::invalid_argument("Ключ должен быть больше 0");
    key = k;
}

std::string routeCipher::encrypt(const std::string& open_text) {
    if (open_text.empty()) return "";
    int n = open_text.length();
    int rows = (n + key - 1) / key;

    std::vector<std::vector<char>> table(rows, std::vector<char>(key, 0));
    
    int idx = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < key; ++c) {
            if (idx < n) table[r][c] = open_text[idx++];
        }
    }

    std::string result = "";
    for (int c = key - 1; c >= 0; --c) {
        for (int r = 0; r < rows; ++r) {
            if (table[r][c] != 0) result += table[r][c];
        }
    }
    return result;
}

std::string routeCipher::decrypt(const std::string& cipher_text) {
    if (cipher_text.empty()) return "";
    int n = cipher_text.length();
    int rows = (n + key - 1) / key;

    std::vector<std::vector<char>> table(rows, std::vector<char>(key, 0));
    
    int idx = 0;
    for (int c = key - 1; c >= 0; --c) {
        for (int r = 0; r < rows; ++r) {
            if (r * key + c < n) table[r][c] = cipher_text[idx++];
        }
    }

    std::string result = "";
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < key; ++c) {
            if (table[r][c] != 0) result += table[r][c];
        }
    }
    return result;
}