import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def least_squares(x, y):
    coeff = ((x*y).mean() - x.mean()*y.mean()) / ((x**2).mean()-(x.mean())**2)
    smeshenie = y.mean() - coeff*x.mean()
    err_k = (1 / np.sqrt(len(x))) * np.sqrt(((y**2).mean() - (y).mean()**2) / ((x*x).mean()-x.mean()**2) - coeff ** 2)
    return coeff, smeshenie, err_k

tochki_dop = pd.read_csv(r'C:\Users\zhune\OneDrive\Desktop\рабочая папка VScode\пробуем\data\tochki_dop.csv')
tochki_dop0 = pd.read_csv(r'C:\Users\zhune\OneDrive\Desktop\рабочая папка VScode\пробуем\data\tochki_dop0.csv')
tochki_dop1 = pd.read_csv(r'C:\Users\zhune\OneDrive\Desktop\рабочая папка VScode\пробуем\data\tochki_dop1.csv')
tochki_dop2 = pd.read_csv(r'C:\Users\zhune\OneDrive\Desktop\рабочая папка VScode\пробуем\data\tochki_dop2.csv')

print(tochki_dop0)
set_of_grafs = [tochki_dop,tochki_dop0,tochki_dop1,tochki_dop2]
set_of_legend = ["graf lin","graf A", "graf B", "graf C"]
counter = 0

# for tochki in set_of_grafs:
#     coeff, smeshenie, err = least_squares(np.log2(tochki['length']), np.log2(tochki['time']))
#     print(coeff, smeshenie, err)
#     plt.plot(np.log2(tochki['length']), (coeff * np.log2(tochki['length'])) + smeshenie, label=set_of_legend[counter])
#     plt.scatter(np.log2(tochki["length"]), np.log2(tochki["time"]), s=10)
#     counter += 1

# plt.xlabel('log2 (N/1)')
# plt.ylabel('log2 (T/microsecond)')

for tochki in set_of_grafs:
    coeff, smeshenie, err = least_squares((tochki['length']), (tochki['time']))
#print(coeff, smeshenie, err)
    plt.plot((tochki['length']), (coeff * (tochki['length'])) + smeshenie, label=set_of_legend[counter])
    plt.scatter((tochki["length"]), (tochki["time"]), s=10)
    counter += 1

plt.xlabel('N')
plt.ylabel('T, microsecond')

#plt.scatter((tochki["length"]), (tochki["time"]), s=10, c='red')

# plt.scatter(0, 0, s=1, c='red')



'''
coeff, smeshenie, err = least_squares(tochki['M'], tochki['Omega'])
print(coeff, smeshenie, err)
'''

plt.grid(linewidth=0.5) 
plt.legend()
plt.show()