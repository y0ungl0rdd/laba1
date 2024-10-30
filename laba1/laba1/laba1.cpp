#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
string process(char text[], int length) {
    string input = text;
    input.pop_back();
    string shortest_word = "";
    string current_word = "";
    for (int i = 0; i < length; i++) {
        if (i == length || input[i] == ' ') {
            if (current_word.length() > 0) {
                if (shortest_word.length() == 0 or current_word.length() < shortest_word.length()) {
                    shortest_word = current_word;
                }
                current_word = "";
            }
        }
        else {
            current_word += input[i];
        }
    }
    string result = shortest_word + " " + input + " " + shortest_word;
    return result;
}

int z1() {
    FILE* initial_file;
    FILE* final_file;
    char input[100] = { '\0' };

    initial_file = fopen("initial_file.txt", "r");
    if (initial_file == NULL) {
        cout << "error opening file" << endl;
        return 1;
    }

    if (fgets(input, sizeof(input), initial_file) != NULL) {
        int len = strlen(input);
        fclose(initial_file);
        final_file = fopen("final_file.txt", "w");
        if (final_file == NULL) {
            cout << ("error opening file") << endl;
            return 1;
        }
        fputs(process(input, len).c_str(), final_file);
        fclose(final_file);
    }
    else {
        cout << "error reading file" << endl;
    }

}

int z2() {
    char input[100] = { "\0" };
    printf("enter a string: ");
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    string res = process(input, len);
    cout << res << endl;;
    return 0;
}

int z3() {
    char input[100] = { "\0" };
    int i = 0;
    printf("enter a string: ");
    while ((input[i] = getchar()) != '\n') {
        i++;
    }
    int len = strlen(input);
    string res = process(input, len);
    cout << res << endl;
    return 0;
}
void main() {
    z1();
    z2();
    z3();
}