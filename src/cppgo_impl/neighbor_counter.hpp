#ifndef CPPGO_NEIGHBOR_COUNTER_HPP
#define CPPGO_NEIGHBOR_COUNTER_HPP

#include "color.hpp"


namespace cppgo {

    class NeighborCounter {
    public:
        NeighborCounter();

        void increment(Color c);
        void decrement(Color c);

        int empty_count() const;
        int player_count(Color c) const;

        bool is_eye_like(Color c) const;

        static NeighborCounter empty();
        static NeighborCounter empty_on_edge();
        static NeighborCounter empty_at_corner();

    private:
        unsigned int bits_;

        explicit NeighborCounter(unsigned int b);

        static NeighborCounter create(unsigned int black, unsigned int white, unsigned int empty);
    };

}

#endif //CPPGO_NEIGHBOR_COUNTER_HPP
