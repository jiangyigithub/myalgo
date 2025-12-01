import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader, TensorDataset
 
# 定义一个简单的 MLP
class MLP(nn.Module):
    def __init__(self, input_size=784, hidden_size=128, num_classes=10):
        super(MLP, self).__init__()
        self.fc1 = nn.Linear(input_size, hidden_size)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(hidden_size, num_classes)
        
    def forward(self, x):
        # x: [batch_size, input_size]
        out = self.fc1(x)
        out = self.relu(out)
        out = self.fc2(out)
        return out
 
# 假数据 (比如 batch_size=64, input=28*28 的图片展平)
x = torch.randn(64, 784)
y = torch.randint(0, 10, (64,))
 
# 数据集和 dataloader
dataset = TensorDataset(x, y)
dataloader = DataLoader(dataset, batch_size=32, shuffle=True)
 
# 模型、损失函数、优化器
model = MLP()
criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)
 
# 训练一个 epoch
for epoch in range(1):
    for batch_x, batch_y in dataloader:
        outputs = model(batch_x)
        loss = criterion(outputs, batch_y)
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
    print(f"Epoch [{epoch+1}], Loss: {loss.item():.4f}")