#include <utils/PerlinNoise.hpp>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <array>
#include <random>

//perlin noise tutorial i follow https://rtouti.github.io/graphics/perlin-noise-algorithm

static float fade(float t){
	return ((6*t - 15) * t + 10) * t * t * t;
}

PerlinNoise::PerlinNoise(uint32_t seed)
    : seed(seed)
{
    std::array<uint8_t, 256> tableChunk;

    for (size_t i = 0; i < tableChunk.size(); i++)
    {
        tableChunk[i] = static_cast<uint8_t>(i);
    }
    
    std::shuffle(tableChunk.begin(), tableChunk.end(), std::default_random_engine(seed));

    for(size_t i = 0; i < permutationTable.size(); i++){
        permutationTable[i] = static_cast<uint16_t>(tableChunk[i % 256]);
    }

    
}

 void PerlinNoise::setSeed(uint32_t seed)
 {
    PerlinNoise::PerlinNoise(seed);
 }


Vector2 PerlinNoise::getConstantVector(uint16_t v) const
{
    //v is the value from the permutation table
	uint16_t h = v % 3;

	if(h == 0)
    {
		return Vector2(1.0, 1.0);
    }
	else if(h == 1)
	{
    	return Vector2(-1.0, 1.0);
    }
	else if(h == 2)
    {
		return Vector2(-1.0, -1.0);
    }
	else
    {
		return Vector2(1.0, -1.0);
    }
}

float PerlinNoise::noise2d(float x, float y) const
{
    //cap the x and y value to be between 0 - 255
    uint16_t X = static_cast<uint16_t>(std::floor(x)) % 255;
    uint16_t Y = static_cast<uint16_t>(std::floor(y)) % 255;


    //get the float reminder
    float xf = x - std::floor(x);
    float yf = y - std::floor(y);

    //construct the square
    Vector2 topRight(xf - 1.0f, yf - 1.0f);
    Vector2 topLeft(xf, yf - 1.0f);
    Vector2 bottomRight(xf - 1.0f, yf);
    Vector2 bottomLeft(xf, yf);


    uint16_t valueTopRight = permutationTable[(permutationTable[X+1]+Y+1)];
    uint16_t valueTopLeft = permutationTable[(permutationTable[X]+Y+1)];
    uint16_t valueBottomRight = permutationTable[(permutationTable[X+1]+Y)];
    uint16_t valueBottomLeft = permutationTable[(permutationTable[X]+Y)];

    float dotTopRight = topRight.dot(getConstantVector(valueTopRight));
    float dotTopLeft = topLeft.dot(getConstantVector(valueTopLeft));
    float dotBottomRight = bottomRight.dot(getConstantVector(valueBottomRight));
    float dotBottomLeft = bottomLeft.dot(getConstantVector(valueBottomLeft));

    float u = fade(xf);
    float v = fade(yf);

    return std::lerp(std::lerp(dotBottomLeft, dotTopLeft, v), std::lerp(dotBottomRight, dotTopRight, v), u);
}

PerlinNoise::~PerlinNoise()
{

}
