from tkinter import *
from PIL import ImageTk, Image

root = Tk()

c = Canvas(root, width=500, height=800, bg='white')
c.pack()

X1_DME = 10
Y1_DME = 100
X2_DME = 310
Y2_DME = 190
c.create_rectangle((X1_DME, Y1_DME), (X2_DME, Y2_DME), width=2)
c.create_text(X1_DME, Y1_DME - 10, text="DME",
                anchor=W, font="Verdana 14")

X1_SVO = 10
Y1_SVO = 300
X2_SVO = 210
Y2_SVO = 390
c.create_rectangle((X1_SVO, Y1_SVO), (X2_SVO, Y2_SVO), width=2)
c.create_text(X1_SVO, Y1_SVO - 10, text="SVO",
                anchor=W, font="Verdana 14")

X1_VKO = 10
Y1_VKO = 500
X2_VKO = 160
Y2_VKO = 570
c.create_rectangle((X1_VKO, Y1_VKO), (X2_VKO, Y2_VKO), width=2)
c.create_text(X1_VKO, Y1_VKO-10, text="VKO",
                anchor=W, font="Verdana 14")

with open('coordinates.txt', 'r') as file:
    n = int(file.readline())
    for i in range(n):
        coordinates = list(map(float, file.readline().split()))
        print(coordinates)
        c.create_rectangle(
            (X1_DME + coordinates[0], Y1_DME + coordinates[1]),
            (X1_DME + coordinates[2], Y1_DME + coordinates[3]))

pilImage = Image.open("самолёт 1.png")
img = ImageTk.PhotoImage(pilImage)
c.create_image(X1_DME + 5, Y1_DME + 5, anchor=NW, image=img)


root.mainloop()

