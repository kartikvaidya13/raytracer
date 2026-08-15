import numpy as np


def load(path):
    tokens = open(path, "rb").read().split()
    width, height = int(tokens[1]), int(tokens[2])
    return np.array(tokens[4:], dtype=np.uint8).reshape(height, width, 3)
