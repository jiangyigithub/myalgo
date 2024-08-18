

The reason there is no vector::find is because there is no algorithmic advantage over std::find (std::find is O(N) and in general, you can't do better for vectors).

But the reason you have map::find is because it can be more efficient (map::find is O(log N) so you would always want to use that over std::find for maps).

https://stackoverflow.com/questions/2994073/why-there-is-no-find-for-vector-in-c
