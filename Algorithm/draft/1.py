n = int(input())
a = list(map(int, input().split()))

ans = 0
for k in range(n):
    # 计算当前元素的贡献
    contribution = a[k] * (k + 1) * (n - k)
    ans += contribution

print(ans)
