#include <iostream>
#include <string>
#include <vector>

std::vector<int> xorMaskEncode(const std::string& inputSequence) {
    int inputLength = inputSequence.length(); // �������� ������� ������ �����������
    std::string xorMask = (inputLength % 2 == 0) ? "01010101" : "10101010"; // ���� XOR-����� ������� �� ������ �����������
    int xorMaskInt = std::stoi(xorMask, nullptr, 2); // ����������� XOR-����� � ���� �����
    std::vector<int> encodedSequence; // ���������� �����������
    for (char c : inputSequence) {
        int encodedChar = c ^ xorMaskInt; // ������������ XOR-����� �� ������� ������� ������ �����������
        encodedSequence.push_back(encodedChar); // ��������� ������������ ������� �� ���������� �����������
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