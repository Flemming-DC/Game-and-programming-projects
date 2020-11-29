import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

T = 5

I = np.zeros([T,T],float)
s = np.zeros([T,T],float)
n = np.zeros(T,float)

I[0,0] = 1
I[1,0] = 1
#n[0] = 1
n[1] = 1        #this is both the generalized number on the diagram up to t and the effective weight of the internal point at t

for t in range(1,T-1):
    I[t+1] = I[t]*n[t]/(n[t]+1)
    I[t+1,t] = 1/(n[t]+1)
    I[t,t] = 1
    d = np.append(np.linspace(t+2,2,t+1) , np.ones(T-t-1))
    n[t+1] = sum(sum(I/d))
I[T-1,T-1] = 1

print("I = ")
print(I)
print()
print("n = ")
print(n)

t_list = np.linspace(1,T,T)
def fit(t, a, b):
    return a*(t**b-1)/b        #a*np.log(t)

param, cov = curve_fit(fit, t_list, n, p0=[1.5,0.01], bounds=[0.000000001,10])

a_fit = param[0]
b_fit = param[1]

t_denselist = np.linspace(1,T,5*T)
n_fit = fit(t_denselist, a_fit, b_fit)


print('a_fit = ', a_fit, 'b_fit = ', b_fit)
print()

#plt.plot(t_list, n, 'k.')
#plt.plot(t_denselist, n_fit, 'b-')           #a_fit*np.log(t_denselist)
#plt.plot(t_denselist, 1/np.log(2)*np.log(t_denselist), 'r--')
#plt.xlabel('time')
#plt.ylabel('generalized number in partial minddiagram')
#plt.show()

#______________________________________________

we = np.zeros(T,float)
wi = np.zeros(T,float)

#print(I[2:T])

we = sum(I)/np.linspace(T,1,T)

for t in range(1,T):
    wi[t] = sum(we[0:t])
wi[0] = we[0]

print('we = ')
print(we)

print('wi = ')
print(wi)

L = sum(we)+sum(wi)-we[0]
print('nul = ',L-(2*T-1))

plt.plot(t_list, we, 'k.')
#plt.plot(t_list, wi, 'b.')
plt.xlabel('time')
plt.ylabel('effective weight')
plt.show()







