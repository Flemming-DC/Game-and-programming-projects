import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt

b = 1
s = 10

x_max = 10
x_min = 0
Nx = 100    #300 is about the maximum for my laptop
dx = (x_max-x_min)/Nx
x = np.linspace(x_min,x_max,Nx)

t_min = 0
t_max = 10
Nt = 100    #my laptop can accpt numbers as high as 10^5
t = np.linspace(t_min,t_max,Nt)

dudt = np.zeros(Nx)
u0 = np.zeros(Nx)
u0[0] = s

def model(u,t):
    dudt[0] = 0
    for n in range(1,Nx-2):
        dudt[n] = (b/dx**2)*(u[n+1]-2*u[n]+u[n-1])
    dudt[Nx-1] = (2*b/dx**2)*(-u[Nx-1]+u[Nx-2])
    return dudt

u = odeint(model,u0,t)



X, T = np.meshgrid(x,t)
fig,ax=plt.subplots(1,1)
cp = ax.contourf(X, T, u)
fig.colorbar(cp)            # Add a colorbar to a plot
ax.set_title('Filled Contours Plot')
ax.set_xlabel('x')
ax.set_ylabel('t')
plt.show()


