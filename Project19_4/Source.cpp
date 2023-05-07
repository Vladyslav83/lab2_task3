#include <iostream>
#include <string>
#include <vector>

std::vector<int> xorMaskEncode(const std::string& inputSequence) {
    int inputLength = inputSequence.length(); // Отримуємо довжину вхідної послідовності
    std::string xorMask = (inputLength % 2 == 0) ? "01010101" : "10101010"; // Вибір XOR-маски залежно від розміру послідовності
    int xorMaskInt = std::stoi(xorMask, nullptr, 2); // Конвертація XOR-маски в ціле число
    std::vector<int> encodedSequence; // Закодована послідовність
    for (char c : inputSequence) {
        int encodedChar = c ^ xorMaskInt; // Застосування XOR-маски до кожного символу вхідної послідовності
        encodedSequence.push_back(encodedChar); // Додавання закодованого символу до закодованої послідовності
    }
    return encodedSequence;
}

int main() {
    std::string inputSequence = "Hello World";
    std::vector<int> encodedSequence = xorMaskEncode(inputSequence);
    std::cout << "Encoded Sequence: ";
    for (int encodedChar : encodedSequence) {
        std::cout << encodedChar << " ";
    }
    std::cout << std::endl;
    return 0;
}