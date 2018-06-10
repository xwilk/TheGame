#pragma once

#include <cassert>


enum class InputMsgId
{
    INCREASE_SPEED,
    DECREASE_SPEED
};

struct IncreaseSpeed
{
    static constexpr InputMsgId MESSAGE_ID = InputMsgId::INCREASE_SPEED;
};

struct DecreaseSpeed
{
    static constexpr InputMsgId MESSAGE_ID = InputMsgId::DECREASE_SPEED;
};

struct Message
{
    InputMsgId id;
};

class InputPort
{
public:
    void push(Message msg)
    {
        assert((_tail + 1) % MAX_MESSAGES != _head);

        _messageQueue[_tail] = msg;
        _tail = (_tail + 1) % MAX_MESSAGES;
    }

    Message pop()
    {
        auto message = _messageQueue[_head];
        _head = (_head + 1) % MAX_MESSAGES;
        return message;
    }

    bool empty()
    {
        return _head == _tail;
    }

private:
    static const int MAX_MESSAGES = 16;

    unsigned _head{0};
    unsigned _tail{0};
    Message _messageQueue[MAX_MESSAGES];
};
