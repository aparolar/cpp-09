#!/usr/bin/python3
import random

nums = random.sample(range(1, 3006), 30)
num_str = ' '.join(map(str, nums))
print(num_str)
