import numpy as np

def test1(scores, labels, n):
    count = 0
    for score,label in scores, labels:
        # 找到score中最大值的坐标
        idx = np.where(a == np.max(score))
        if label == idx :
            count = count + 1
    # 总体准确率
    p1 = count / len(label)

    # 根据真值找类召回率
    a = [0 for _ in range(n)]
    for i in range(0, n):
        a[i] = np.sum(labels == i)
        count = 0
        for score,label in scores, labels:
            # 找到score中最大值的坐标
            idx = np.where(a == np.max(score))
            if label == idx and idx == i:
                count = count + 1
        
        a[i] = count/a[i]

    # 根据预测值找类准确率
    b = [0 for _ in range(n)]
    
