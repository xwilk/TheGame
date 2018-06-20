#pragma once

#include <cassert>

#include "Point.hpp"


enum class InputMsgId
{
    INCREASE_SPEED,
    DECREASE_SPEED,
    SIDEMOVE_LEFT,
    SIDEMOVE_RIGHT,
    ROTATE
};

struct Rotate
{
    Point target;
};

union Payload
{
    Payload() {}
    Payload(Rotate r) : rotateTowards(r) {}
    Rotate rotateTowards;
};

struct Message
{
    Message() {}
    Message(InputMsgId id) : id(id) {}
    Message(InputMsgId id, Payload payload) : id(id), payload(payload) {}

    InputMsgId id;
    Payload payload;
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
