#include <algorithm>

#include "utils.hpp"

#include "07.hpp"

using namespace std;
using namespace myg;

Hand::Hand(const string& cs, const int b) :
cards(cs),
bid(b)
{
    card_map = map<char, int>();
    for (auto c : cs) card_map[c]++;
}

bool Hand::operator<(const Hand& h) const {
    if (strength() != h.strength())
        return strength() < h.strength();

    for (auto i = 0; i < 5; i++)
        if (cards[i] != h.cards[i])
            return card_value(i) < h.card_value(i);

    return false;
}

const vector<int> Hand::card_counts(void) const {
    vector<int> ret;
    for (auto i = card_map.begin(); i != card_map.end(); ++i)
        ret.push_back(i->second);
    return ret;
}

int Hand::card_value(const int i) const {
    switch(cards[i]) {
        case 'A':
            return 13;
            break;
        case 'K':
            return 12;
            break;
        case 'Q':
            return 11;
            break;
        case 'J':
            return 10;
            break;
        case 'T':
            return 9;
            break;
        case '9':
            return 8;
            break;
        case '8':
            return 7;
            break;
        case '7':
            return 6;
            break;
        case '6':
            return 5;
            break;
        case '5':
            return 4;
            break;
        case '4':
            return 3;
            break;
        case '3':
            return 2;
            break;
        case '2':
            return 1;
            break;
    }
    return 0;
}

int Hand::strength(void) const {
    if (is_five()) {
        return 8;
    } else if (is_four()) {
        return 7;
    } else if (is_full()) {
        return 6;
    } else if (is_three()) {
        return 5;
    } else if (is_two()) {
        return 4;
    } else if (is_one()) {
        return 3;
    } else if (is_high()) {
        return 2;
    } else {
        return 1;
    }
}

bool Hand::is_five(void) const {
    return card_map.size() == 1;
}

bool Hand::is_four(void) const {
    vector<int> cc(card_counts());
    return (
        (cc.size() == 2) &&
        ((cc[0] == 4) || (cc[1] == 4))
    );
}

bool Hand::is_full(void) const {
    vector<int> cc(card_counts());
    return (
        (cc.size() == 2) &&
        ((cc[0] == 3) || (cc[1] == 3))
    );
}

bool Hand::is_three(void) const {
    vector<int> cc(card_counts());
    return (
        (cc.size() == 3) &&
        ((cc[0] == 3) || (cc[1] == 3) || (cc[2] == 3))
    );
}

bool Hand::is_two(void) const {
    vector<int> cc(card_counts());
    return (
        (cc.size() == 3) && (
            ((cc[0] == 2) && (cc[1] == 2)) ||
            ((cc[0] == 2) && (cc[2] == 2)) ||
            ((cc[1] == 2) && (cc[2] == 2))
        )
    );
}

bool Hand::is_one(void) const {
    vector<int> cc(card_counts());
    return cc.size() == 4;
}

bool Hand::is_high(void) const {
    return card_map.size() == 5;
}

int Day07::part_1(void) {
    vector<Hand> hands;

    for (auto str : _data) {
        vector<string> parts = myg::split(str, ' ');
        hands.push_back(Hand(parts.front(), stoi(parts.back())));
    }

    sort(hands.begin(), hands.end());

    ulong total = 0;
    for (int i = 0, n = hands.size(); i < n; i++)
        total += static_cast<ulong>(i + 1) * static_cast<ulong>(hands[i].bid);

    return total;
}

int Day07::part_2(void) {
    return 0;
}
