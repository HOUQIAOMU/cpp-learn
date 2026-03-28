import random
import time
import numpy as np
def dot_product(vec1, vec2):
    if len(vec1) != len(vec2):
        raise ValueError("Vectors must be of the same length")
    # 记录计算开始时间
    start_time = time.time()
    result = sum(a * b for a, b in zip(vec1, vec2))
    end_time = time.time()
    print(f"Time taken: {end_time - start_time} seconds.")
    return result

if __name__ == "__main__":
    # Generate two random vectors of size 1000000
    size = 1000000
    vec1 = [random.random() for _ in range(size)]
    vec2 = [random.random() for _ in range(size)]
    
    result = dot_product(vec1, vec2)
    print(f"Dot product: {result}")

    # 利用np.array进行点积计算，并记录时间
    np.vec1 = np.array(vec1)
    np.vec2 = np.array(vec2)
    start_time = time.time()
    np_result = np.dot(np.vec1, np.vec2)
    end_time = time.time()
    print(f"NumPy dot product: {np_result}")
    print(f"Time taken for NumPy: {end_time - start_time} seconds.")


    