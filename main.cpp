#include <iostream>

int main() {
    // Image Dimensions
    int image_width = 256;
    int image_height = 256;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; ++i) {
            // Calculate color based on pixel position
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;

            // Convert to RGB values
            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            // Output the pixel color
            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}