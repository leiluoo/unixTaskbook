#ifndef COLORS_HPP
#define COLORS_HPP

#include <string>

namespace colors {

// Text styles
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string DIM = "\033[2m";
const std::string UNDERLINED = "\033[4m";
const std::string BLINK = "\033[5m";
const std::string REVERSE = "\033[7m";
const std::string HIDDEN = "\033[8m";

// Text colors
const std::string BLACK = "\033[38;2;0;0;0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[38;2;255;255;0m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[38;2;255;255;255m";
const std::string GRAY = "\033[90m";
const std::string BRIGHT_RED = "\033[91m";
const std::string BRIGHT_GREEN = "\033[92m";
const std::string BRIGHT_YELLOW = "\033[93m";
const std::string BRIGHT_BLUE = "\033[94m";
const std::string BRIGHT_MAGENTA = "\033[95m";
const std::string BRIGHT_CYAN = "\033[96m";
const std::string BRIGHT_WHITE = "\033[97m";

// Background colors
const std::string BG_BLACK = "\033[48;2;0;0;0m";
const std::string BG_RED = "\033[48;2;255;0;0m";
const std::string BG_GREEN = "\033[48;2;0;128;0m";
const std::string BG_YELLOW = "\033[48;2;255;112;0m";
const std::string BG_BLUE = "\033[48;2;0;0;128m";
const std::string BG_MAGENTA = "\033[45m";
const std::string BG_CYAN = "\033[46m";
const std::string BG_WHITE = "\033[47m";
const std::string BG_GRAY = "\033[100m";
const std::string BG_BRIGHT_RED = "\033[48;2;255;64;128m";
const std::string BG_BRIGHT_GREEN = "\033[102m";
const std::string BG_BRIGHT_YELLOW = "\033[103m";
const std::string BG_BRIGHT_BLUE = "\033[104m";
const std::string BG_BRIGHT_MAGENTA = "\033[48;2;255;0;255m";
const std::string BG_BRIGHT_CYAN = "\033[106m";
const std::string BG_BRIGHT_WHITE = "\033[48;2;255;255;255m";

// Function to colorize a string
inline std::string colorize(const std::string& str, const std::string& color) {
    return color + str + RESET;
}

} // namespace colors

#endif // COLORS_HPP
