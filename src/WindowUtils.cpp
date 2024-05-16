#include "WindowUtils.hpp"

void WindowUtils::getInput(float params[PARAMS_SIZE]) {
    for (int i = 0; i < PARAMS_SIZE; i++) {
        bool done = false;
        float temp;

        while (!done) {
            float min = PARAM_CONSTRAINTS[i].min;
            float max = PARAM_CONSTRAINTS[i].max;
            RangeType rangeType = PARAM_CONSTRAINT_TYPES[i];
            std::string label = PARAM_LABELS[i];
            std::string err = PARAM_ERRORS[i];

            std::cout << "\n[" << label << "]: ", std::cin >> temp;

            done = rangeType == INCLUSIVE ?
                   temp >= min && temp <= max
                   : temp > min && temp < max;

            if ((i == RANGE_KT_MAX && temp < params[RANGE_KT_MIN]) ||
                (i == RANGE_DZETA_MAX && temp < params[RANGE_DZETA_MIN]))
                done = false;

            if (!done && !err.empty()) {
                std::cout << err << "\n";
            }
        }

        params[i] = temp;
    }
}

void WindowUtils::printParamsTable(float params[PARAMS_SIZE], const std::string& title) {
    VariadicTable<std::string, float> table({ "Name", "Value" });

    if (!title.empty())
        std::cout << "\n- " << title << "\n";

    for (int i = 0; i < PARAMS_SIZE; i++) {
        table.addRow(PARAM_LABELS[i], params[i]);
    }

    table.print(std::cout);
}

void WindowUtils::getConfirmation(const std::string& text, bool ignore) {
    std::cout << "\n" << text;

    if (ignore)
        std::cin.ignore();

    std::cin.get();
    std::cout << "\n";
}

void WindowUtils::printTitle() {
    std::string title = R"(
 ____                 _   _
/ ___| ___ _ __   ___| |_(_) ___
| |  _ / _ \ '_ \ / _ \ __| |/ __|
| |_| |  __/ | | |  __/ |_| | (__
\____|\___|_| |_|\___|\__|_|\___|
    _    _                  _ _   _
   / \  | | __ _  ___  _ __(_) |_| |__  _ __ ___
  / _ \ | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \
 / ___ \| | (_| | (_) | |  | | |_| | | | | | | | |
/_/   \_\_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|
            |___/
    )";

    std::cout << title << "\n";
}
