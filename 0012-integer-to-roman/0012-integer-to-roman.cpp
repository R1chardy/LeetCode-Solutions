class Solution {
public:
    string intToRoman(int num) {
        std::string roman_chars[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int int_values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    // Initialize the result string
    std::string result;

    // Loop through the integers and Roman numerals, adding the Roman numeral
    // to the result string whenever the integer is less than or equal to the
    // number we're trying to convert
    for (int i = 0; i < sizeof(int_values) / sizeof(int); i++) {
      while (num >= int_values[i]) {
        result += roman_chars[i];
        num -= int_values[i];
      }
    }

    // Return the result
    return result;
    }
};