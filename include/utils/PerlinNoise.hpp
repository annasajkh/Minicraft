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
    std::array<uint8_t, 256>permutationTable;
public:
    PerlinNoise(uint32_t seed);
    ~PerlinNoise();

    void setSeed(uint32_t seed);

    float noise2d(float x, float y) const;
    Vector2 getConstantVector(uint8_t v) const;
};