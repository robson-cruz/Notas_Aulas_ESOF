col = int(input("Enter the column [1 to 8]: "))
row = int(input("Enter the row [1 to 8]: "))

# King on a corn of the chessboard
if (col == 1 or col == 8) and (row == 1 or row == 8):
    print(3)
# King on a border but not in the corn of the chessboard
elif col == 1 or col == 8 or row == 1 or row == 8:
    print(5)
# King in the center of the chessboard
else:
    print(8)
