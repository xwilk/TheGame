#pragma once

#include <type_traits>


class Event
{
public:
    virtual ~Event() = default;

    virtual std::uint32_t getMessageId() const = 0;
    virtual std::unique_ptr<Event> clone() const  = 0;
};

template <class T>
class EventT : public Event
{
    static_assert(std::is_copy_constructible<T>::value, "Payload type must be copy-construcible!");

public:
    EventT(T const& payload = T())
        : m_payload(std::make_unique<T>(payload))
    {}

    EventT(T&& payload)
        : m_payload(std::make_unique<T>(std::forward<T>(payload)))
    {}

    EventT(EventT&&) = default;

    EventT(EventT<T> const&) = delete;
    EventT& operator=(EventT<T> const&) = delete;

    std::uint32_t getMessageId() const override
    {
        return T::MESSAGE_ID;
    };

    T& operator*() noexcept
    {
        return *m_payload;
    }

    T const& operator*() const noexcept
    {
        return *m_payload;
    }

private:
    std::unique_ptr<T> m_payload;
};

template <class T>
T const& payload(Event const& p_evt)
{
    return *static_cast<EventT<T> const&>(p_evt);
}

template <class T>
T& payload(Event& p_evt)
{
    return *static_cast<EventT<T>&>(p_evt);
}

enum class SIDEMOVE
{
    NONE = 0,
    LEFT = -90,
    RIGHT = 90
};

struct SideMove
{
    static constexpr InputMsg MESSAGE_ID = InputMsg::SIDE_MOVE;

    Sidemove sidemove;
};

struct Rotate
{
    static constexpr InputMsg MESSAGE_ID = InputMsg::ROTATE;

    Point target;
};

