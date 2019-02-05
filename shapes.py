#!/usr/bin/env python3
import random
import string
#path = "/Users/alexcsloan/Desktop/QuadrilateralClassifier/testFiles"
path = "testFiles"

# make this file executable with: chmod +x shapes.py


# generating shapes that I know to be squares
def make_square():
    file = open(path+"/squares.txt", "w")
    x1 = 1
    y1 = 0
    x2 = 1
    y2 = 1
    x3 = 0
    y3 = 1
    for i in range(100):
        file.write(str(x1)+" "+str(y1)+" "+str(x2)+" "+str(y2)+" "+str(x3)+" "+str(y3)+"\n")
        x1 += 1
        x2 += 1
        y2 += 1
        y3 += 1
    file.close()
    return 0


def make_square_key():
    file = open(path + "/squareSol.txt", "w")
    for i in range(100):
        file.write("square\n")
    file.close()
    return 0


# generating shapes that I know to be rectangles
def make_rectangle():
    file = open(path+"/rectangles.txt", "w")
    x1 = 2
    y1 = 0
    x2 = 2
    y2 = 1
    x3 = 0
    y3 = 1
    for i in range(99):
        file.write(str(x1)+" "+str(y1)+" "+str(x2)+" "+str(y2)+" "+str(x3)+" "+str(y3)+"\n")
        x1 += 1
        x2 += 1
        y2 += 1
        y3 += 1
    file.close()
    return 0


def make_rectangle_key():
    file = open(path + "/rectangleSol.txt", "w")
    for i in range(99):
        file.write("rectangle\n")
    file.close()
    return 0


# generating shapes that I know to be trapezoids
def make_trapezoid():
    file = open(path+"/trapezoids.txt", "w")
    x1 = 3
    y1 = 0
    x2 = 2
    y2 = 1
    x3 = 1
    y3 = 1
    for i in range(98):
        file.write(str(x1)+" "+str(y1)+" "+str(x2)+" "+str(y2)+" "+str(x3)+" "+str(y3)+"\n")
        x1 += 1
        x2 += 1
        y2 += 1
        y3 += 1
    file.close()
    return 0


def make_trapezoid_key():
    file = open(path + "/trapezoidSol.txt", "w")
    for i in range(98):
        file.write("trapezoid\n")
    file.close()
    return 0


# generating shapes that I know to be rhombi
def make_rhombus():
    file = open(path+"/rhombus.txt", "w")
    x1 = 2
    y1 = 1
    x2 = 3
    y2 = 3
    x3 = 1
    y3 = 2
    for i in range(98):
        file.write(str(x1)+" "+str(y1)+" "+str(x2)+" "+str(y2)+" "+str(x3)+" "+str(y3)+"\n")
        x1 += 1
        x2 += 1
        y2 += 1
        y3 += 1
    file.close()
    return 0


def make_rhombus_key():
    file = open(path + "/rhombusSol.txt", "w")
    for i in range(98):
        file.write("rhombus\n")
    file.close()
    return 0


# generating shapes that I know to be rhombi
def make_parallelogram():
    file = open(path+"/parallelograms.txt", "w")
    x1 = 3
    y1 = 0
    x2 = 4
    y2 = 2
    x3 = 1
    y3 = 2
    for i in range(97):
        file.write(str(x1)+" "+str(y1)+" "+str(x2)+" "+str(y2)+" "+str(x3)+" "+str(y3)+"\n")
        x1 += 1
        x2 += 1
        y2 += 1
        y3 += 1
    file.close()
    return 0


def make_parallelogram_key():
    file = open(path + "/parallelogramSol.txt", "w")
    for i in range(97):
        file.write("parallelogram\n")
    file.close()
    return 0


# generating 6 random points randomly in the range of 0 to 100 inclusive
def make_random_shape_0_to_100():
    num = 1
    for i in range(500):
        file = open(path + "/"+str(num)+".txt", "w")
        file.write(str(random.randint(0, 100))+" "+str(random.randint(0, 100))+" "+str(random.randint(0, 100))
                   + " "+str(random.randint(0, 100))+" "+str(random.randint(0, 100))+" "+str(random.randint(0, 100))+"\n")
        file.close()
        num += 1
    return 0


# generating 6 random points randomly in the range of -500 to 500 inclusive
def make_random_shape_to_500():
    num = 501
    for i in range(300):
        file = open(path + "/"+str(num)+".txt", "w")
        file.write(str(random.randint(-500, 500))+" "+str(random.randint(-500, 500))+" "+str(random.randint(-500, 500))
                   + " "+str(random.randint(-500, 500))+" "+str(random.randint(-500, 500))+" "+str(random.randint(-500, 500))+"\n")
        file.close()
        num += 1
    return 0


# generating 6 duplicate points in the range of 0-100 inclusive
def duplicate_points():
    num = 801
    for i in range(100):
        file = open(path + "/"+str(num)+".txt", "w")
        ran = random.randint(0, 100)
        file.write(str(ran)+" "+str(ran)+" "+str(ran)+" "+str(ran)+" "+str(ran)+" "+str(ran)+"\n")
        file.close()
        num += 1
    return 0


# generating a random string with a random length
def random_character_random_length():
    num = 901
    for i in range(100):
        file = open(path + "/"+str(num)+".txt", "w")
        random_int = random.randint(0, 50)
        random_string = ''.join([random.choice(string.ascii_letters + string.digits) for n in range(random_int)])
        file.write(random_string+"\n")
        file.close()
        num += 1
    return 0


make_square()
make_rectangle()
make_trapezoid()
make_rhombus()
make_parallelogram()
make_rhombus_key()
make_square_key()
make_rectangle_key()
make_trapezoid_key()
make_parallelogram_key()
make_random_shape_0_to_100()
make_random_shape_to_500()
duplicate_points()
random_character_random_length()

