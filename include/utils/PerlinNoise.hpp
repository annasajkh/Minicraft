#pragma once

#include <iostream>
#include <array>

struct Vector2
{
    float x, y;

    Vector2(float x, float y)
        : x(x), y(y)
    {

    }

    float dot(const Vector2& other)
    {
        return x * other.x + y * other.y;
    }
};

class PerlinNoise
{
private:
    uint32_t seed;
    std::array<uint16_t, 512>permutationTable;
public:
    PerlinNoise(uint32_t seed);
    ~PerlinNoise();

    void setSeed(uint32_t seed);

    float noise2d(float x, float y) const;
    Vector2 getConstantVector(uint16_t v) const;
};