#include "brick.h"
#include <cmath>
#include <cstdlib>

Brick genRandBrick() {
	size_t index = rand() % BrickTypeNum;
	return Brick(index);
}
