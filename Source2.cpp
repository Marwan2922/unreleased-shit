#include <iostream>
#include <cstdlib>
using namespace std;
#include "Image_Class.h"

int main() {

    string filename;
    int x, y, w, h;
    cout << "Pls enter image name to crop it: ";
    cin >> filename;
    cout << "Pls enter starting point: ";
    cin >> x >> y;
    cout << "please enter the dimensions of the area to cut: ";
    cin >> w >> h;

    Image image(filename);


    if (x + w > image.width || y + h > image.height)
    {
        cout << "Error ";
    }
    else {
        Image cropped(w, h);

        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {

                for (int k = 0; k < 3; ++k) {





                    cropped(i, j, k) = image(i + x, j + y, k);

                }

            }


        }


        cout << "Pls enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        cin >> filename;
        cropped.saveImage(filename);
        system(filename.c_str());   //

    }
}
