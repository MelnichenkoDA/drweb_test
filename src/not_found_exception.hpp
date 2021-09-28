#ifndef __NOT__FOUND__EXCEPTION__HPP
#define __NOT__FOUND__EXCEPTION__HPP

template <class Key>
class not_found_exception : public std::exception
{
public:
    virtual const Key &get_key() const noexcept = 0;
};

#endif