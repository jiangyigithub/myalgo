import collections

class LRUCache(collections.OrderedDict):

    def __init__(self, capacity: int):
        super().__init__()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self:
            return -1
        self.move_to_end(key) # 将访问的键移动到末尾，标记为最近使用
        return self[key]

    def put(self, key: int, value: int) -> None:
        if key in self:
            self.move_to_end(key)  # 如果键已存在，移动到末尾
        self[key] = value
        if len(self) > self.capacity:
            self.popitem(last=False)  # 移除最前面的键值对，即最久未使用的

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
# 创建一个有序字典
od = collections.OrderedDict([('a', 1), ('b', 2), ('c', 3)])
print(od)  # OrderedDict([('a', 1), ('b', 2), ('c', 3)])

# 将键 'b' 移动到末尾
od.move_to_end('b')
print(od)  # OrderedDict([('a', 1), ('c', 3), ('b', 2)])

# 将键 'a' 移动到开头
od.move_to_end('a', last=False)
print(od)  # OrderedDict([('a', 1), ('c', 3), ('b', 2)])

# 创建一个有序字典
od2 = collections.OrderedDict([('a', 1), ('b', 2), ('c', 3)])
print(od2)  # OrderedDict([('a', 1), ('b', 2), ('c', 3)])

# 删除并返回最后一个键值对
item = od2.popitem()
print(item)  # ('c', 3)
print(od2)  # OrderedDict([('a', 1), ('b', 2)])

# 删除并返回第一个键值对
item = od2.popitem(last=False)
print(item)  # ('a', 1)
print(od2)  # OrderedDict([('b', 2)])

test_lru_cache()
