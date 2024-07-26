import collections
import time

class LRUCache(collections.OrderedDict):

    def __init__(self, capacity: int, ttl: int):
        super().__init__()
        self.capacity = capacity
        self.ttl = ttl  # time-to-live in seconds

    def _is_expired(self, key: int) -> bool:
        current_time = time.time()
        return current_time > self[key][1]

    def _remove_expired_keys(self):
        keys_to_remove = [key for key in self if self._is_expired(key)]
        for key in keys_to_remove:
            del self[key]

    def get(self, key: int) -> int:
        self._remove_expired_keys()
        if key not in self or self._is_expired(key):
            if key in self:
                del self[key]  # 删除过期的键
            return -1
        self.move_to_end(key)
        return self[key][0]

    def put(self, key: int, value: int) -> None:
        self._remove_expired_keys()
        expiry_time = time.time() + self.ttl
        if key in self:
            self.move_to_end(key)
        self[key] = (value, expiry_time)
        if len(self) > self.capacity:
            self.popitem(last=False)

def test_lru_cache_with_ttl():
    cache = LRUCache(2, 2)  # 容量为2，TTL为2秒

    cache.put(1, 1)  # 缓存内容：{1=1}
    cache.put(2, 2)  # 缓存内容：{1=1, 2=2}
    assert cache.get(1) == 1  # 返回 1，因为键 1 存在，并且缓存更新为：{2=2, 1=1}

    time.sleep(3)  # 等待超过TTL

    assert cache.get(1) == -1  # 返回 -1，因为键 1 已过期
    assert cache.get(2) == -1  # 返回 -1，因为键 2 已过期

    cache.put(3, 3)  # 缓存内容：{3=3}
    cache.put(4, 4)  # 缓存内容：{3=3, 4=4}
    assert cache.get(3) == 3  # 返回 3
    assert cache.get(4) == 4  # 返回 4

    # 测试更新已有的键值对
    cache.put(3, 30)  # 缓存内容：{4=4, 3=30}
    assert cache.get(3) == 30  # 返回 30

    # 测试再次超出容量时的行为
    cache.put(5, 5)  # 缓存内容：{3=30, 5=5}，因为键 4 被移除
    assert cache.get(4) == -1  # 返回 -1，因为键 4 已过期或被移除
    assert cache.get(3) == 30  # 返回 30
    assert cache.get(5) == 5  # 返回 5

    print("所有测试用例通过！")

# 运行测试用例
test_lru_cache_with_ttl()
