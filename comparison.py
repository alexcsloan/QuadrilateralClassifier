#!/usr/bin/env python3
import random
import string

path = "compare/coords"
# generating 6 random points randomly in the range of 0 to 100 inclusive
def make_random_shape_0_to_100():
    num = 1
    for i in range(10000):
        file = open(path + "/"+str(num)+".txt", "w")
        file.write(str(random.randint(0, 100))+" "+str(random.randint(0, 100))+" "+str(random.randint(0, 100))
                   + " "+str(random.randint(0, 100))+" "+str(random.randint(0, 100))+" "+str(random.randint(0, 100))+"\n")
        file.close()
        num += 1
    return 0

# generating 6 random points randomly in the range of -500 to 500 inclusive
def make_random_shape_to_500():
    num = 10001
    for i in range(500):
        file = open(path + "/"+str(num)+".txt", "w")
        file.write(str(random.randint(-500, 500))+" "+str(random.randint(-500, 500))+" "+str(random.randint(-500, 500))
                   + " "+str(random.randint(-500, 500))+" "+str(random.randint(-500, 500))+" "+str(random.randint(-500, 500))+"\n")
        file.close()
        num += 1
    return 0


# generating 6 duplicate points in the range of 0-100 inclusive
def duplicate_points():
    num = 10501
    for i in range(500):
        file = open(path + "/"+str(num)+".txt", "w")
        ran = random.randint(0, 100)
        file.write(str(ran)+" "+str(ran)+" "+str(ran)+" "+str(ran)+" "+str(ran)+" "+str(ran)+"\n")
        file.close()
        num += 1
    return 0


# generating a random string with a random length
def random_character_random_length():
    num = 11001
    for i in range(500):
        file = open(path + "/"+str(num)+".txt", "w")
        random_int = random.randint(0, 50)
        random_string = ''.join([random.choice(string.ascii_letters + string.digits) for n in range(random_int)])
        file.write(random_string+"\n")
        file.close()
        num += 1
    return 0

make_random_shape_0_to_100()
make_random_shape_to_500()
duplicate_points()
random_character_random_length()
