#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<cmath>
#include<iomanip>


size_t IntegerLogarithm2(size_t arg) {
    size_t logarithm = 0;
    while (arg >>= 1) ++logarithm;
    return logarithm;
}

size_t IntegerPower2(size_t arg) {
    if (arg)
        return (size_t)2 << (arg - 1);
    else
        return 1;
}

size_t LineLength(size_t level, size_t item_width, size_t spaces_between) {
    return IntegerPower2(level) * (item_width + spaces_between) - spaces_between;
}

int main()
{
    std::vector<int> A = { 1000, 555, 123, 2, 1234, 51, 6, 20, 1, 3, 2, 2, 1, 0, 2 };
    std::vector<std::vector<int> > levels;
    size_t levels_number = IntegerLogarithm2(A.size() + 1);
    levels.resize(levels_number);
    for (size_t i = 0; i < levels.size(); ++i) {
        size_t elements_number = IntegerPower2(i);
        levels[i].resize(elements_number);
        for (size_t j = elements_number - 1, p = 0; p < elements_number; ++j, ++p)
            levels[i][p] = A[j];
    }

    if (levels_number < 1) return 0;

    int magnitude = (abs(A[0]) <= 1 ? 1 : abs(A[0]));
    size_t tab_width = (size_t)floor(log(double(magnitude)) / log(10.0)) + 1;
    std::vector<std::string> text;
    text.reserve(levels_number * 2 - 1);

    for (size_t i = 0; i < levels_number; ++i) {
        size_t outer_space_width = IntegerPower2(levels_number - 1 - i) - 1;
        size_t inner_space_width = outer_space_width * 2 + 1;
        std::string outer_space(outer_space_width * tab_width, ' ');
        std::string inner_space(inner_space_width * tab_width, ' ');

        std::ostringstream line;
        line << outer_space;

        if (i > 0) {
            std::ostringstream branchline;
            std::string joint(tab_width, '|');
            std::string branch(inner_space_width * tab_width, '-');

            branchline << outer_space;

            if (levels[i].size() > 0) {
                branchline << joint;
            }

            bool isline = true;
            for (size_t j = 1; j < levels[i].size(); ++j, isline = !isline) {
                if (isline)
                    branchline << branch << joint;
                else
                    branchline << inner_space << std::setfill(' ') <<
                    std::setw(tab_width) << joint;
            }

            branchline << outer_space;
            text.push_back(branchline.str());
        }

        if (levels[i].size() > 0) {
            line << std::setfill(' ') << std::setw(tab_width) << levels[i][0];
        }

        for (size_t j = 1; j < levels[i].size(); ++j) {
            line << inner_space << std::setfill(' ') <<
                std::setw(tab_width) << levels[i][j];
        }

        line << outer_space;
        text.push_back(line.str());
    }

    for (auto& i : text)
        std::cout << i << std::endl;

    return 0;
}