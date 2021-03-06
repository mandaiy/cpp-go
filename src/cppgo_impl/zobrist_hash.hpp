#ifndef CPPGO_ZOBRIST_HASH_HPP
#define CPPGO_ZOBRIST_HASH_HPP

#include <cstdint>

#include "color.hpp"
#include "move.hpp"


namespace cppgo {

    class ZobristHash {
    public:
        using ValueType = std::uint_fast64_t;

    private:
        ValueType hash_value_;

    public:
        explicit ZobristHash(ValueType initial_value=0u);

        void update(Color c, Move const& v);

        ValueType hash_value() const;
    };

}

#endif //CPPGO_ZOBRIST_HASH_HPP
