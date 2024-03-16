#setup
import numpy as np

#data input function
def inputm():
  row, col = map(int, input("Row, Column 숫자: ").split())
  arr = []
  for i in range(row):
    arr.append(list(map(float, input().split())))
  arr = np.array(arr, dtype = float)
  print("\nInput Matrix")
  print(arr)
  return arr.copy(), row, col

#Function to transform a matrix into Row Echelon Form
def cal_REF(arr, row, col):
  arr_res = arr.copy()
  for i in np.arange(row - 1):
    for j in np.arange(i, col - 1):
      #Check if we need to switch columns
      if arr_res[i][j] == 0:
        #In case of the need
        for k in np.arange(i + 1, row):
          if (arr_res[k][j] != 0):
            temp = arr_res[i].copy()
            arr_res[i] = arr_res[k].copy()
            arr_res[k] = temp.copy()
            break
        #In case of no switchable column
        if k == (row - 1):
          #Move on to the next column
          continue
      #Gaussian elimination part
      for l in np.arange(i + 1, row):
          if arr_res[l][j] != 0:
            eff = arr_res[l][j] / arr_res[i][j]
            arr_res[l] = arr_res[l] - (arr_res[i] * eff)
      break
  #This part transforms a vector's values to set it's leading variable as 1.
  for i in np.arange(row):
    for j in np.arange(col):
      if abs(arr_res[i][j]) < 1e-10:
        arr_res[i][j] = 0
      if arr_res[i][j] != 0:
        arr_res[i] /= arr_res[i][j]
        break
  print(arr_res)
  return arr_res.copy()

#from REF to RREF
def cal_RREF(arr_REF, row, col):
  arr_RREF = arr_REF.copy()
  if (arr_RREF[row - 1][:col - 1].any() == False) & (arr_RREF[row - 1][col - 1] == True):
    print("No solution, this system is inconsistent.")
  else:
    for i in np.arange(1, row):
      for j in np.arange(i, col - 1):
        if (arr_RREF[i][j] == 1):
          for k in np.arange(i):
            if (arr_RREF[k][j] != 0):
              eff = arr_RREF[k][j]
              arr_RREF[k] -= arr_RREF[i] * eff
          break
  print(arr_RREF)
  return  arr_RREF.copy()

def show_solution():
  arr, row, col = inputm()
  print("\nRow Echelon Form")
  arr_REF = cal_REF(arr, row, col)
  print("\nReduced Row Echelon Form")
  arr_RREF = cal_RREF(arr_REF, row, col)

show_solution()
