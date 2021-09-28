#ifndef __KEY__NOT__FOUND__ECEPTION__
#define __KEY__NOT__FOUND__ECEPTION__

#include "not_found_exception.hpp"

template<class Key>
class key_not_found_exception : public not_found_exception<Key>
{
public:
    key_not_found_exception(const Key& value)
        :key(value)
    {}

    virtual const char* what() const noexcept
    {
        return "Couldn't get value from dictionary.";
    }

    virtual const Key& get_key() const noexcept
    {
        return key;
    }

private:
    Key key;
};

#endif