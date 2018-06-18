#ifndef CPPGO_COLOR_HPP
#define CPPGO_COLOR_HPP


namespace cppgo {

    enum class Color {
        BLACK = +1,
        WHITE = -1,
        EMPTY =  0
    };

    inline constexpr Color opposite_color(Color c) {
        if (c == Color::BLACK) {
            return Color::WHITE;
        }

        if (c == Color::WHITE) {
            return Color::BLACK;
        }

        return Color::EMPTY;
    }

}

#endif //CPPGO_COLOR_HPP
