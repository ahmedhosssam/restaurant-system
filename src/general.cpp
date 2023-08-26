#include "../include/general.h"

int getInt() {
    string input;
    double result;

    while (true) {
        cin >> input;

        try
        {
            size_t pos;
            result = stod(input, &pos);

            if (result < 0) {
                cout << "Invalid input, please enter a number greater than 0: ";
                continue;
            }

            if (pos == input.size()) {
                // Convesion is successful
                break;
            } else {
                cerr << "Invalid input, please try again: ";
            }
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Invalid argument, please try again: ";
            continue;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Out of range, please try again: ";
            continue;
        }
    }
    return result;
}