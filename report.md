# 51115141

作業一

## 解題說明

這題要實現一個遞迴函式計算 Ackermann 函數  A(m, n) ，
<img width="663" height="136" alt="image" src="https://github.com/user-attachments/assets/0f44292d-e105-47c5-a4a6-8e1b45774090" />

### 解題策略

遞迴實現: 直接根據定義實現，通過條件判斷分情況遞迴呼叫。

非遞迴實現: 模擬遞迴過程，使用顯式堆疊或迭代來避免堆疊溢出，但由於複雜性高，此處簡化為示意。

## 程式實作

```cpp
#include <iostream>
using namespace std;

int ackermannRecursive(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return ackermannRecursive(m - 1, 1);
    return ackermannRecursive(m - 1, ackermannRecursive(m, n - 1));
}

int ackermannNonRecursive(int m, int n) {
    while (true) {
        if (m == 0) return n + 1;
        if (n == 0) {
            m--;
            n = 1;
            continue;
        }
        m--;
        n = ackermannNonRecursive(m, n - 1);
    }
}

int main() {
    int m, n;
    cout << "輸入 m 和 n: ";
    cin >> m >> n;
    cout << "遞迴結果: " << ackermannRecursive(m, n) << endl;
    return 0;
}
```

## 效能分析

時間複雜度: 遞迴版本為  O(2^{2^m}) ，非遞迴版本依賴堆疊模擬，理論上相似。

空間複雜度: 遞迴版本為  O(m)  (堆疊深度)，非遞迴版本可優化至  O(1) 。

## 測試與驗證

### 測試案例

| 測試案例 | 輸入參數  (m, n) | 預期輸出 | 實際輸出 |
|----------|--------------|----------|----------|
| 測試一   | (0, 0)      | 1        | 1        |
| 測試二   | (1, 0)      | 2        | 2        |
| 測試三   | (1, 1)      | 3        | 3        |
| 測試四   | (2, 1)      | 5       | 5       |
| 測試五   | (3, 0)     | 5 | 5 |

編譯與執行指令

```shell
$ g++ -std=c++17 -o ackermann ackermann.cpp
$ ./ackermann
輸入 m 和 n: 1 1
遞迴結果: 3
```

### 結論

程式正確計算小值情況下的 Ackermann 函數。由於增長極快， m, n  應保持小值，驗證與定義一致。

### 心得

透過實現 Ackermann 函數，我體會到遞迴的強大與限制。
