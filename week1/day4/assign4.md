```
#include <cassert>

int main(void) {
	int x = 4;
	int y = x + + + 2;

	assert(y == 6);
	assert(x == 5);
}

```


The code above will work with no errors because x + + + 2 is treated as (x++) + 2. The post-increment operator returns a copy of x before it is
incremented so y becomes 6 and x becomes 5. Therefore the post-increment operator takes precedence to the addition operation. Also,
increment operators do not work on literals so ++2 would not be considered.