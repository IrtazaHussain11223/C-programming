#include <iostream>
using namespace std;

void Decode(char text[], char Triggers[], int key) {
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] == 'B') {
            int sum = 0;
            int end;
            while (text[end] >= '0' && text[end] <= '9') {
                sum += text[end] - '0';
                end++;
            }
            if (sum > key) {
                while (i < end) {
                    char temp = text[i];
                    text[i] = text[end];
                    text[end] = temp;
                    i++;
                    end--;
                }
            }
        }
        else {
            i++;
        }
    }
}

int main() {
    char text[] = "Bi9llio6ns1 Qco3de9 Myst9erious3";
    char triggers[] = { 'B', 'Q' };
    int key = 10;
    Decode(text, triggers, key);
    return 0;
}
