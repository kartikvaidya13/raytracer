import argparse
import subprocess
from pathlib import Path

from ppm import load
from viewer import show

ROOT = Path(__file__).resolve().parents[2]
IMAGE = ROOT / "image.ppm"


def render(build):
    if build:
        subprocess.run(["cmake", "--build", ROOT / "build"], check=True)
    with open(IMAGE, "wb") as out:
        subprocess.run([ROOT / "build" / "raytracer"], stdout=out, check=True)
    return IMAGE


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("image", nargs="?")
    parser.add_argument("--no-build", action="store_true")
    args = parser.parse_args()

    path = Path(args.image) if args.image else render(not args.no_build)
    pixels = load(path)
    show(pixels, f"{path.name}  {pixels.shape[1]}x{pixels.shape[0]}")


if __name__ == "__main__":
    main()
