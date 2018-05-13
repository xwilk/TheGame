#pragma once

#include <type_traits>
#include <utility>


template <typename T, template<typename> class crtpType>
struct Crtp
{
    T& underlying() { return static_cast<T&>(*this); }
    T const& underlying() const { return static_cast<T const&>(*this); }
};

template <typename T>
struct DividableByFloat : Crtp<T, DividableByFloat>
{
    T operator/(T divider) { return T(this->underlying().get() / divider); }
};

template <typename T, typename Parameter, template<typename> class... Skills>
class NamedType : public Skills<NamedType<T, Parameter, Skills...>>...
{
public:
    explicit NamedType(T const &value)
        : value_(value)
    {}

    T &get() { return value_; }
    T const &get() const { return value_; }

private:
    T value_;
};
