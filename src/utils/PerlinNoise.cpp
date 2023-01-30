#include <utils/PerlinNoise.hpp>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <array>
#include <random>

//perlin noise tutorial i follow https://rtouti.github.io/graphics/perlin-noise-algorithm

static float fade(float t){
	return ((6*t - 15)*t + 10)*t*t*t;
}

PerlinNoise::PerlinNoise(uint32_t seed)
    : seed(seed)
{
    for(uint8_t i = 0; i < 256; i++){
        permutationTable[i] = i;
    }

    
    std::shuffle(permutationTable.begin(), permutationTable.end(), std::default_random_engine(seed));

    std::cout << "[ ";

    for(uint8_t i = 0; i < 256; i++){
        std::cout << permutationTable[i] << ",";
    }

    std::cout << " ]";
}

 void PerlinNoise::setSeed(uint32_t seed)
 {
    PerlinNoise::PerlinNoise(seed);
 }


Vector2 PerlinNoise::getConstantVector(uint8_t v) const
{
    //v is the value from the permutation table
	uint8_t h = v & 3;

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
    uint8_t X = static_cast<int>(std::floor(x)) & 255;
    uint8_t Y = static_cast<int>(std::floor(y)) & 255;

    //get the float reminder
    float xf = x - std::floor(x);
    float yf = y - std::floor(y);

    //construct the square
    Vector2 topRight(xf - 1.0f, yf - 1.0f);
    Vector2 topLeft(xf, yf - 1.0f);
    Vector2 bottomRight(xf - 1.0f, yf);
    Vector2 bottomLeft(xf, yf);

    uint8_t valueTopRight = permutationTable[permutationTable[X+1]+Y+1];
    uint8_t valueTopLeft = permutationTable[permutationTable[X]+Y+1];
    uint8_t valueBottomRight = permutationTable[permutationTable[X+1]+Y];
    uint8_t valueBottomLeft = permutationTable[permutationTable[X]+Y];

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
