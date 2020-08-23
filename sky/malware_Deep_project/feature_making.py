import numpy as np
import os, array
import scipy.misc
import sys
import imageio
from PIL import Image
import cv2

class IMAGE_feature():
    def __init__(self, in_path, out_path):
        self.in_path = in_path
        self.out_path = out_path

    def get_image(self, path, file):

            filename = path + file

            f = open(filename, 'rb')
            ln = os.path.getsize(filename)
            width = int(ln**0.5)
            rem = ln % width

            a = array.array("B")
            a.fromfile(f, ln-rem)
            f.close()

            g = np.reshape(a, (int(len(a)/width), width))
            g = np.uint8(g)

            fpng = self.out_path + file + ".png"
            imageio.imwrite(fpng, g)
            print(fpng)

    def get_all(self):
        path = self.in_path

        for file in os.listdir(path):
            self.get_image(path, file)

def main():
    mal_path = "/media/lmsky/A279-DD87/kisa_dataset/대용량_정상,악성파일1/대용량_정상,악성파일1/sample_test1/"
    mal_out_path = "/home/lmsky/PycharmProjects/malware_Deep_project/result/"
    im1 = IMAGE_feature(mal_path, mal_out_path)
    im1.get_all()

    return mal_out_path