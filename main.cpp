#include <iostream>
#include <vector>
#include <cassert>

#include "src/hash_dictionary.hpp"
#include "src/key_not_found_exception.hpp"

class point
{
public:
    int x, y, z;

    bool operator==(const point& other) const
    {
        return x == x && y == y && z == z;
    }
};

namespace std
{
    template<> 
    struct hash<point>
    {
        std::size_t operator()(const point& pt) const noexcept
        {
            return pt.x ^ (pt.y << pt.z); 
        }
    };
}

template<class Key, class Value, class Hash = std::hash<Key>>
void check(const std::vector<Key>& keys, const std::vector<Value> values, const Key& not_included_key)
{
    assert(keys.size() == values.size() && keys.size());

    hash_dictionary<Key, Value, Hash> first;
    for (int i = 0; i < keys.size(); ++i)
        first.set(keys[i], values[i]);

    const auto second = first;
    if (second.is_set(keys[0]))
        const auto& temp = second.get(keys[0]);

    try
    {
        const auto& temp = second.get(not_included_key);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    check<int, int>(
        {1,2,3,4,5}, 
        {12,15,17,12,5}, 
        7
    );

    check<std::string, std::string>(
        {"first", "second", "third"},
        {"asd", "qwe", "zxc"},
        "fgh"
    );
    
    check<point, int>(
        {
            {2, 3, 6},
        },
        {1},
        point{5, 5, 7}
    );
    
    return 0;
}