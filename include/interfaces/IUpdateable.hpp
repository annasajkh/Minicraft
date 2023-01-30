#pragma once

class IUpdateable
{
public:
    IUpdateable() { }
    ~IUpdateable() { }

    virtual void update(float delta) = 0;
};