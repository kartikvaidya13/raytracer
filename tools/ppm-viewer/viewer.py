import matplotlib.pyplot as plt


def show(pixels, title):
    plt.figure(title)
    plt.imshow(pixels)
    plt.axis("off")
    plt.tight_layout()
    plt.show()
