from tkinter import *
from PIL import ImageTk, Image

root = Tk()

c = Canvas(root, width=1000, height=800, bg='white')
c.pack()

X1_DME = 20
Y1_DME = 40
X2_DME = X1_DME + 300 * 2
Y2_DME = Y1_DME + 80 * 2
c.create_rectangle((X1_DME, Y1_DME), (X2_DME, Y2_DME), width=2)
c.create_text(X1_DME, Y1_DME - 10, text="DME",
              anchor=W, font="Verdana 14")

X1_SVO = 20
Y1_SVO = Y2_DME + 40
X2_SVO = X1_SVO + 200 * 2
Y2_SVO = Y1_SVO + 90 * 2
c.create_rectangle((X1_SVO, Y1_SVO), (X2_SVO, Y2_SVO), width=2)
c.create_text(X1_SVO, Y1_SVO - 10, text="SVO",
              anchor=W, font="Verdana 14")

X1_VKO = 20
Y1_VKO = Y2_SVO + 40
X2_VKO = X1_VKO + 150 * 2
Y2_VKO = Y1_VKO + 70 * 2
c.create_rectangle((X1_VKO, Y1_VKO), (X2_VKO, Y2_VKO), width=2)
c.create_text(X1_VKO, Y1_VKO - 10, text="VKO",
              anchor=W, font="Verdana 14")

aircrafts = {
    'Ил-96-300': (57.66, 55.345),
    'Ил-96-400': (60.105, 63.939),
    'Ту-154М': (37.55, 47.9),
    'Ан-24': (29.2, 23.53),
    'Ан-124': (73.3, 69.1),
    'A319': (34.1, 33.84),
    'A320': (34.1, 37.57),
    'A321': (34.1, 44.51),
    '737-200': (28.35, 30.53),
    '737-300': (28.88, 33.25),
    '737-800': (34.32, 39.47)
}

# with open('coordinates.txt', 'r', encoding='UTF-8') as file:
#     n = int(file.readline())
#     for i in range(n):
#         coordinates = file.readline().split()
#         aircraft = coordinates[0]
#         x = float(coordinates[1])
#         y = float(coordinates[2])
#         print(coordinates)
#         c.create_rectangle(
#             (X1_DME + x, Y1_DME + y),
#             (X1_DME + x + aircrafts[aircraft][0] * 2, Y1_DME + y + aircrafts[aircraft][1] * 2))
#         pilImage = Image.open(aircraft + '.png')
#         pilImage = pilImage.resize((int(aircrafts[aircraft][0]) * 2, int(aircrafts[aircraft][1]) * 2), Image.ANTIALIAS)
#         exec(
#             "img_%s = ImageTk.PhotoImage(pilImage)\n" \
#             "c.create_image(X1_DME + x, Y1_DME + y, anchor=NW, image=img_%d)" % (i, i))

# with open('VKO_out.txt', 'r', encoding='UTF-8') as file:
#     file.readline()
#     n = int(file.readline())
#     for i in range(n):
#         coordinates = file.readline().split()
#         x = float(coordinates[1])
#         y = float(coordinates[2])
#         start = int(coordinates[3])
#         length = float(coordinates[4])
#         width = float(coordinates[5])
#         duration = int(coordinates[6])
#         aircraft = aircrafts[(length, width)]
#         print(coordinates)
#         if start <= t <= start + duration:
#             c.create_rectangle(
#                 (X1_VKO + x * 2, Y1_VKO + y * 2),
#                 (X1_VKO + (x + width) * 2, Y1_VKO + (y + length) * 2))
#             pilImage = Image.open(aircraft + '.png')
#             pilImage = pilImage.resize((int(length) * 2, int(width) * 2), Image.ANTIALIAS)
#             exec(
#                 "img_%s = ImageTk.PhotoImage(pilImage)\n" \
#                 "c.create_image(X1_DME + x * 2, Y1_DME + y * 2, anchor=NW, image=img_%d)" % (i, i))

t = 60

orders = open('data/orders.txt', 'r', encoding='UTF-8').readlines()
print(orders[3])

with open('data/DME_out.txt', 'r', encoding='UTF-8') as file:
    n = int(file.readline())
    for i in range(n):
        coordinates = file.readline().split()
        position = int(coordinates[0])
        ord = orders[position].split()
        x = float(coordinates[2])
        y = float(coordinates[1])
        start = int(coordinates[3])
        aircraft = ord[1]
        print(aircraft)
        length = float(aircrafts[aircraft][0])
        width = float(aircrafts[aircraft][1])
        duration = int(ord[-2])
        print(x, y, start, aircraft, length, width, duration)
        if start <= t <= start + duration:
            c.create_rectangle(
                (X1_DME + x * 2, Y1_DME + y * 2),
                (X1_DME + (x + width) * 2, Y1_DME + (y + length) * 2))
            pilImage = Image.open(aircraft + '.png')
            pilImage = pilImage.resize((int(width) * 2, int(length) * 2), Image.ANTIALIAS)
            exec(
                "img_%s = ImageTk.PhotoImage(pilImage)\n" \
                "c.create_image(X1_DME + x * 2, Y1_DME + y * 2, anchor=NW, image=img_%d)" % (i, i))

with open('data/SVO_out.txt', 'r', encoding='UTF-8') as file:
    n = int(file.readline())
    for i in range(n):
        coordinates = file.readline().split()
        position = int(coordinates[0])
        ord = orders[position].split()
        x = float(coordinates[2])
        y = float(coordinates[1])
        start = int(coordinates[3])
        aircraft = ord[1]
        print(aircraft)
        length = float(aircrafts[aircraft][0])
        width = float(aircrafts[aircraft][1])
        duration = int(ord[-2])
        print(x, y, start, aircraft, length, width, duration)
        #if start <= t <= start + duration:
        if start == 0:
            c.create_rectangle(
                (X1_SVO + x * 2, Y1_SVO + y * 2),
                (X1_SVO + (x + width) * 2, Y1_SVO + (y + length) * 2))
            pilImage = Image.open(aircraft + '.png')
            pilImage = pilImage.resize((int(width) * 2, int(length) * 2), Image.ANTIALIAS)
            exec(
                "img_SVO%s = ImageTk.PhotoImage(pilImage)\n" \
                "c.create_image(X1_SVO + x * 2, Y1_SVO + y * 2, anchor=NW, image=img_SVO%d)" % (i, i))

with open('data/VKO_out.txt', 'r', encoding='UTF-8') as file:
    n = int(file.readline())
    for i in range(n):
        coordinates = file.readline().split()
        position = int(coordinates[0])
        ord = orders[position].split()
        x = float(coordinates[2])
        y = float(coordinates[1])
        start = int(coordinates[3])
        aircraft = ord[1]
        print(aircraft)
        length = float(aircrafts[aircraft][0])
        width = float(aircrafts[aircraft][1])
        duration = int(ord[-2])
        print(position, x, y, start, aircraft, length, width, duration)
        if start <= t <= start + duration:
            c.create_rectangle(
                (X1_VKO + x * 2, Y1_VKO + y * 2),
                (X1_VKO + (x + width) * 2, Y1_VKO + (y + length) * 2))
            pilImage = Image.open(aircraft + '.png')
            pilImage = pilImage.resize((int(width) * 2, int(length) * 2), Image.ANTIALIAS)
            exec(
                "img_VKO%s = ImageTk.PhotoImage(pilImage)\n" \
                "c.create_image(X1_VKO + x * 2, Y1_VKO + y * 2, anchor=NW, image=img_VKO%d)" % (i, i))

root.mainloop()
