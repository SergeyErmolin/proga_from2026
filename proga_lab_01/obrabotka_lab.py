import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def least_squares(x, y):
    coeff = ((x*y).mean() - x.mean()*y.mean()) / ((x**2).mean()-(x.mean())**2)
    smeshenie = y.mean() - coeff*x.mean()
    err_k = (1 / np.sqrt(len(x))) * np.sqrt(((y**2).mean() - (y).mean()**2) / ((x*x).mean()-x.mean()**2) - coeff ** 2)
    return coeff, smeshenie, err_k

tochki = pd.read_csv(r'C:\Users\zhune\OneDrive\Desktop\рабочая папка VScode\пробуем\data\tochki.csv')
#tochki_dop1 = pd.read_csv(r'C:\Users\zhune\OneDrive\Desktop\рабочая папка VScode\пробуем\data\tochki_dop1.csv')
print(tochki)

coeff, smeshenie, err = least_squares(np.log(tochki['length']), np.log(tochki['time']))
print(coeff, smeshenie, err)

plt.plot(np.log(tochki['length']), (coeff * np.log(tochki['length'])) + smeshenie)
plt.scatter(np.log(tochki["length"]), np.log(tochki["time"]), s=10, c='red')


#plt.scatter((tochki["length"]), (tochki["time"]), s=10, c='red')

#plt.errorbar(tochki["DP_3_2_4"], tochki['Q_3_2_4'], xerr=0.98, yerr=0.034, linestyle='')
# plt.scatter(0, 0, s=1, c='red')

plt.xlabel('ln(N)')
plt.ylabel('ln(T)')


'''
coeff, smeshenie, err = least_squares(tochki['M'], tochki['Omega'])
print(coeff, smeshenie, err)
'''

plt.grid(linewidth=0.5) 
plt.show()