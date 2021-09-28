#ifndef __HASH__DICTIONARY__
#define __HASH__DICTIONARY__

#include <unordered_map>

#include "dictonary.hpp"
#include "key_not_found_exception.hpp"

template<class Key, class Value, class Hash = std::hash<Key>>
class hash_dictionary : public dictionary<Key, Value>
{
public:
    hash_dictionary() = default;
    hash_dictionary(const hash_dictionary& other) = default;
    hash_dictionary(hash_dictionary&& other) = default;
    hash_dictionary& operator=(const hash_dictionary& other) = default;
    hash_dictionary& operator=(hash_dictionary&& other) = default;

    virtual ~hash_dictionary() = default;

    virtual const Value& get(const Key& key) const
    {
        auto result_itr = data.find(key);
        if (result_itr == data.cend())
            throw key_not_found_exception<Key>(key);
        
        return result_itr->second;
    }

    virtual void set(const Key& key, const Value& value)
    {
        data[key] = value;
    }

    virtual bool is_set(const Key& key) const
    {
        const auto itr = data.find(key);
        return itr != data.cend();
    }

private:
    std::unordered_map<Key, Value, Hash> data;
};

#endif