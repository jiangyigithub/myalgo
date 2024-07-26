import collections

class LRUCache(collections.OrderedDict):

    def __init__(self, capacity: int):
        super().__init__()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self:
            return -1
        self.move_to_end(key)
        return self[key]

    def put(self, key: int, value: int) -> None:
        if key in self:
            self.move_to_end(key)
        self[key] = value
        if len(self) > self.capacity:
            self.popitem(last=False)

def test_lru_cache():
    # 创建容量为2的LRU缓存
    cache = LRUCache(2)

    # 测试 put 和 get 方法
    cache.put(1, 1) # 缓存内容：{1=1}
    cache.put(2, 2) # 缓存内容：{1=1, 2=2}
    assert cache.get(1) == 1  # 返回 1，因为键 1 存在，并且缓存更新为：{2=2, 1=1}

    # 超出容量时，插入新元素，将删除最久未使用的元素
    cache.put(3, 3) # 缓存内容：{1=1, 3=3}，因为键 2 被移除
    assert cache.get(2) == -1 # 返回 -1，因为键 2 不存在

    cache.put(4, 4) # 缓存内容：{3=3, 4=4}，因为键 1 被移除
    assert cache.get(1) == -1 # 返回 -1，因为键 1 不存在
    assert cache.get(3) == 3  # 返回 3
    assert cache.get(4) == 4  # 返回 4

    # 测试更新已有的键值对
    cache.put(3, 30) # 缓存内容：{4=4, 3=30}
    assert cache.get(3) == 30  # 返回 30

    # 测试再次超出容量时的行为
    cache.put(5, 5) # 缓存内容：{3=30, 5=5}，因为键 4 被移除
    assert cache.get(4) == -1 # 返回 -1，因为键 4 不存在
    assert cache.get(3) == 30 # 返回 30
    assert cache.get(5) == 5  # 返回 5

    print("所有测试用例通过！")

# 运行测试用例
test_lru_cache()
