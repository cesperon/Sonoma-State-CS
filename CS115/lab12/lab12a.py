class Rectangle:
    def __init__(self, L, W):
        self.set_length(L)
        self.set_width(W)

    def set_width(self, W):
        self.width = W

    def set_length(self, L):
        self.length = L

    def get_width(self):
        return self.width

    def get_length(self):
        return self.length

    def get_area(self):
        return self.get_length() * self.get_width()

    def get_perimeter(self):
        return (self.get_length()*2) + (self.get_width()*2)

# STOP HERE
# This code uses the Rectangle class
r1 = Rectangle(1, 2) # Statement 1
r2 = Rectangle(5, 6) # Statement 2
a1 = r1.get_area() # Statement 3
a2 = r2.get_area() # Statement 4
p1= r1.get_perimeter() #Statement 5
p2= r2.get_perimeter()#Statement 6