#ifndef BG_PAIR_H
#define BG_PAIR_H

template<typename T1, typename T2>
struct BgPair {
    BgPair() : first(T1()), second(T2()) { }
    BgPair(const T1 &first, const T2 &second) : first(first), second(second) { }

    T1 first;
    T2 second;
};

#endif