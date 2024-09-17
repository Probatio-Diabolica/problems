
from functools import cache
@cache
def something(a):
    return a+100

print(something(78))
print(something(78))
# print(something(67))
